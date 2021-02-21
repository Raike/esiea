#include <stdio.h>
#include <stdlib.h>

int * ALLOCATION_TAB_DYN(int N)
{
    int * TAB;
    TAB = malloc(N*sizeof(int*));
    return TAB;
}

void CHARGEMENT_TAB(int N, int * TAB)
{
    FILE* fichier = NULL;
    fichier = fopen("My_Tab.txt", "w");
    int temp = 0;

    if (fichier != NULL)
    {
        fprintf(fichier, "%d\n", N);
        printf("Donnez les valeurs de My_Tab :\n");
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &temp);
            fprintf(fichier, "%d ", temp);
            TAB[i] = temp;
        }
        fclose(fichier);
    }
}

void AFFICHAGE_TAB(int N, int * TAB)
{
    printf("\nVotre Tableau est : ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", * (TAB+i));
    }
    
}

int ** ALLOCATION_MAT_DYN(int NB_L, int NB_C)
{
    int ** TAB;
    TAB = malloc(NB_L*sizeof(int*));
    for (int i = 0; i < NB_L; i++)
    {
        TAB[i] = malloc(NB_C*sizeof(int));
    }
    return TAB;
}

void CHARGEMENT_MAT(int NB_L, int NB_C, int ** MAT)
{
    FILE* fichier = NULL;
    fichier = fopen("My_Matrice.txt", "w");
    int temp = 0;
    int j = 0;
    if (fichier != NULL)
    {
        fprintf(fichier, "%d %d\n", NB_L, NB_C);
        printf("Donnez les valeurs de My_Matrice :\n");
        for (int i = 0; i < NB_L; i++)
        {
            for (j = 0; j < NB_C; j++)
            {
                scanf("%d", &temp);
                fprintf(fichier, "%d ", temp);
                MAT[i][j] = temp;
            }
            j = 0;
            fprintf(fichier, "\n");
        }
        fclose(fichier);
    }
}

void AFFICHAGE_MAT(int NB_L, int NB_C, int ** MAT)
{
    int j = 0;
    printf("Votre matrice est :\n");
    for (int i = 0; i < NB_L; i++)
    {
        for (j = 0; j < NB_C; j++)
        {
            printf("%d ",MAT[i][j]);
        }
        j = 0;
        printf("\n");
    }
    
}

int main(int argc, char ** argv)
{
    // PARTIE A //
/*
    int N = 0;
    printf("Donnez la taille du tableau : ");
    scanf("%d", &N);
    int *TAB = ALLOCATION_TAB_DYN(N);
    CHARGEMENT_TAB(N, TAB);
    AFFICHAGE_TAB(N, TAB);
    free(TAB); TAB = NULL;
*/
    // PARTIE B //

    int NB_L = 0;
    int NB_C = 0;
    printf("\nDonnez le nombre de ligne et de colone de votre matrice : ");
    scanf("%d %d", &NB_L, &NB_C);
    int ** MAT = ALLOCATION_MAT_DYN(NB_L, NB_C);
    CHARGEMENT_MAT(NB_L, NB_C, MAT);
    AFFICHAGE_MAT(NB_L, NB_C, MAT);
    return 0;
}