#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void AFFICHAGE_BOISSONS()
{
    FILE* map = NULL;
    int caractere = 0;

    map = fopen("map.txt", "r");

    if (map != NULL)
    {
        for(;;)
        {
            caractere = fgetc(map);
            if (caractere == EOF)
                break;
            printf("%c", caractere); 
        }; 

        fclose(map); 
        printf("\n");
    }
}

void ACHAT_BOISSON(double MONNAIE_DISPO[10], double PRIX_BOISSONS[10], int choix, double Somme)
{
    double prix = PRIX_BOISSONS[choix];
    double rendu = Somme - prix;
    int temp = 0;

    printf("La monaie a rendre est de : %lf\n\n", rendu);

    for (int i = 9; i >= 0; i--)
    {
        while (rendu>=MONNAIE_DISPO[i] || fabs (rendu-MONNAIE_DISPO[i]) < 0.001)
        {
            temp ++;
            rendu -= MONNAIE_DISPO[i];
            if (rendu == 0)
            {
                break;
            }
        }
        if (temp != 0)
        {
            printf("%d x %.2lf\n", temp, MONNAIE_DISPO[i]);
        temp = 0;
        }
    }
}

void ACHAT_BOISSON_2(double MONNAIE_DISPO[10], int NB_PIECES_DISPO[10], double PRIX_BOISSONS[10], int choix, double Somme)
{
    double prix = PRIX_BOISSONS[choix];
    double rendu = Somme - prix;
    int temp = 0;

    printf("La monaie a rendre est de : %lf\n\n", rendu);

    for (int i = 9; i >= 0; i--)
    {
        while ((rendu>=MONNAIE_DISPO[i] || fabs (rendu-MONNAIE_DISPO[i]) < 0.001 )&& NB_PIECES_DISPO[i] >= 1)
        {
            temp ++;
            rendu -= MONNAIE_DISPO[i];
            NB_PIECES_DISPO[i] -= 1;
            if (rendu == 0)
            {
                break;
            }
        }
        if (temp != 0)
        {
            printf("%d x %.2lf\n", temp, MONNAIE_DISPO[i]);
            temp = 0;
        }
    }
}

void ACHAT_BOISSON_3(double MONNAIE_DISPO[10], int NB_PIECES_DISPO[10], double PRIX_BOISSONS[10], int choix, double Somme)
{
    double prix = PRIX_BOISSONS[choix];
    double rendu = Somme - prix;
    double main_monaie = 0;
    int z = 0;
    int temp = 0;

    printf("La monaie a rendre est de : %lf\n", rendu);
    printf("Quelle est votre pièces ou billet préféré : ");
    scanf("%lf", &main_monaie);

    for (int i = 0; i < 10; i++)
    {
        if (main_monaie == MONNAIE_DISPO[i])
        {
            z = i;
        }
    }

    while ((rendu>=MONNAIE_DISPO[z] || fabs (rendu-MONNAIE_DISPO[z]) < 0.001 )&& NB_PIECES_DISPO[z] >= 1)
    {
        temp ++;
        rendu -= MONNAIE_DISPO[z];
        NB_PIECES_DISPO[z] -= 1;
        if (rendu == 0)
        {
            break;
        }
    }
    if (temp != 0)
        {
            printf("\n%d x %.2lf\n", temp, MONNAIE_DISPO[z]);
            temp = 0;
        }
    temp = 0;
    
    for (int i = 9; i >= 0; i--)
    {
        while ((rendu>=MONNAIE_DISPO[i] || fabs (rendu-MONNAIE_DISPO[i]) < 0.001 )&& NB_PIECES_DISPO[i] >= 1)
        {
            temp ++;
            rendu -= MONNAIE_DISPO[i];
            NB_PIECES_DISPO[i] -= 1;
            if (rendu == 0)
            {
                break;
            }
        }
        if (temp != 0)
        {
            printf("%d x %.2lf\n", temp, MONNAIE_DISPO[i]);
            temp = 0;
        }
    }
}

void REMP_NOMS_BOISSONS(char BOISSONS[10][17], int choix)
{
    printf("\nVotre boison ");
    for (int i = 0; i < 17; i++)
    {
        printf("%c", BOISSONS[choix][i]);
    }
    printf(" est pret(e) !\n");
}

int main()
{
    system("clear");

    double MONNAIE_DISPO[10] = {0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10};
    double PRIX_BOISSONS[10] = {0.70, 0.80, 0.60, 0.50, 0.40, 0.60, 0.60, 1, 1.20, 0.40};
    int NB_PIECES_DISPO[10] = {10, 5, 4, 2, 0, 2, 4, 1, 1, 0};
    char BOISSONS[10][17] = {"Café court", "Café long", "Café au lait", "Chocolat", "Lait", "Thé au citron", "Thé a la menthe", "Thé au gingembre", "Thé au miel", "Eau"};

    double Somme = 0;
    int choix = 0;
    
    AFFICHAGE_BOISSONS();

    printf("Quel est votre choix ? (Taper 10 pour quitter)\n");
    scanf("%d", &choix);
    if (choix == 10)
    {
        return 0;
    }
    else
    {
        printf("Donnez votre montant : ");
        scanf("%lf", &Somme);
            // Partie n°A
        //ACHAT_BOISSON(MONNAIE_DISPO, PRIX_BOISSONS, choix, Somme);
            // Partie n°B
        //ACHAT_BOISSON_2(MONNAIE_DISPO, NB_PIECES_DISPO,PRIX_BOISSONS, choix, Somme);
            // Partie n°C
        ACHAT_BOISSON_3(MONNAIE_DISPO, NB_PIECES_DISPO,PRIX_BOISSONS, choix, Somme);
            // PArtie n°D
        REMP_NOMS_BOISSONS(BOISSONS, choix);
    }
    return 0;
}