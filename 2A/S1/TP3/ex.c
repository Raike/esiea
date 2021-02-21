#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Eleve
    {
        char* nom;
        char* prenom;
        float moyenne_generale;
    };

void saisir(struct Eleve *T, int *nb)
{
    for (int i = 0; i < *nb; i++)
    {
        char *name = calloc(21,sizeof(char));
        printf("Quel est le nom de l'eleve numéro %d : ",i);
        scanf("%s", name);
        T[i].nom = name;

        printf("Quel est le prenom de l'eleve numéro %d : ",i);
        T[i].prenom = calloc(21,sizeof(char));
        scanf("%s", T[i].prenom);

        printf("Quelle est la moyenne generale numéro %d : ",i);
        scanf("%f", &(T[i].moyenne_generale));
    }
}

void afficher(struct Eleve *T, int nbeleves)
{
    for (int i = 0; i < nbeleves; i++)
    {
        printf("\n\nElève numéro %d : \n", i);
        printf("    nom : %s\n", T[i].nom);
        printf("    prenom : %s\n", T[i].prenom);
        printf("    moyenne_generale : %f\n\n", T[i].moyenne_generale);
    }
}

void ajouter(struct Eleve *T, int *nb)
{
    int position = *nb;

    printf("Quel est le nom de l'eleve numéro %d : ", position);
    T[position].nom = calloc(21,sizeof(char));
    scanf("%s", T[position].nom);

    printf("Quel est le prenom de l'eleve numéro %d : ", position);
    T[position].prenom = calloc(21,sizeof(char));
    scanf("%s", T[position].prenom);

    printf("Quelle est la moyenne generale numéro %d : ", position);
    scanf("%f", &(T[position].moyenne_generale));

    *nb += 1;
}

int recherche(struct Eleve *T, int nb, int i, char nm[20])
{
    if (i == nb)
    {
        return 0;
    }
    if(strcmp(nm,T[i].nom) == 0)
    {
        return 1;
    }
    else
    {
        recherche(T, nb, i+1, nm);
    }

    return 0;
}

void supprime(struct Eleve *T, int *nb, double moy)
{
    int base = 0;
    int MAX = 2000;
    int data = *nb;
    for (int i = 0; i < *nb; i++)
    {
        if (T[i].moyenne_generale == moy)
        {
            base ++;
        }
    }
    if (base == 0)
    {
        printf("Eror la moyenne n’est pas dans le tableau\n");
        exit(0);
    }
    else
    {
        for (int i = 0; i < *nb; i++)
        {
            if (T[i].moyenne_generale == moy)
            {
                if (T[*nb].moyenne_generale != moy)
                {
                    T[i] = T[*nb];
                    *nb -= 1;
                }
                else
                {
                    while (T[data].moyenne_generale == moy)
                    {
                        data --;
                    }
                    T[i] = T[data];
                    *nb -= 1;
                }
            }
        }
    }
    
}

int main()
{
    const int MAX_ELEVES = 2000;
    int nb;
    double moy;
    int choix;
    char nm[21];
    int i = 0;
    struct Eleve tab[MAX_ELEVES];

    printf("Combien d'eleves voulez vous ajouter : ");
    scanf("%d", &nb);
    printf("\n");
    saisir(tab, &nb);

    while (1)
    {
        printf("\n\n\nEntrez 0 pour quitter\nEntrez 1 pour afficher les élèves\nEntrez 2 pour ajouter des élèves\nEntrez 3 pour rechercher un élève\nEntrez 4 pour retirer des élèves\n       ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 0:
            exit(0);
            break;
    
        case 1: 
            afficher(tab, nb);
            break; 
        
        case 2 :
            ajouter(tab, &nb);
            break;

        case 3 :
            printf("Quelle nom recherché vous : ");
            scanf("%s", nm);

            if(recherche(tab, nb, i, nm) == 1)
            {
                printf("Le nom est présent dans la liste\n");
            }
            else
            {
                printf("Le nom n'est pas présent dans la liste\n");
            }
            break;
        case 4 :
            printf("Quelle est la moyenne ? ");
            scanf("%lf", &moy);
            supprime(tab, &nb, moy);
            break;
        default:
        break;
        }
    }
    return 0;
}



/*

-----------------------------

struct Movie {
    char *name;
    char *director;
    float duration;
    char **cast;
    int castSize;
};

struct AucunSens {
    struct Movie movieThatMakeSense;
    struct Movie *movieThatDoesntMakeSense;
}

int main() {
    struct AucunSens *param = giveMeSomeNonSenseData();

    theFunction(param);

    return 0;
}

// Compare director of both movies, print "directors match" / "directors doesn't match"
// 1er acteur de MovieThatMakeSense est présent dans la liste d'acteur de MovieThatDoesntMakeSense, si oui: "starring %s"
void theFunction(struct AucunSens *param) {
    if (strcmp(param->movieThatMakeSense.director, param->movieThatDoesntMakeSense->director) == 0) {
        printf("directors match\n");
    } else {
        printf("directors doesn't match\n");
    }


    for (int i = 0; i < param->movieThatDoesntMakeSense->castSize; i++)
    {
        if (strcmp(param->movieThatMakeSense.cast[0], param->movieThatDoesntMakeSense->cast[i]) == 0)
        {
            printf("starring %s\n", param->movieThatMakeSense.cast[0]);
            break;
        }
    }
}

------------------------------------------------------------------------

int main() {
    int filmCount;
    struct Movie myFilms;

    getFilms(&myFilms, &filmCount);

    // Ecrire le code qui:
    // Print le nom du 4e acteur, si le nombre d'acteur est pair, sinon, le 3e
    for (int i = 0; i < filmCount; i++)
    {
        struct Movie myMovie = myFilms[i];
        if (myMovie.castSize % 2 == 0)
        {
            printf("%s\n", myMovie.cast[3]);
        } else {
            printf("%s\n", myMovie.cast[2]);
        }
    }

    return 0;
}

/
  (Un tableau de film) INPUTS => [ FUNCTION ] => OUTPUTS (Print le nom du 4e acteur, si le nombre d'acteur est pair, sinon, le 3e, pour chaque film)
 */