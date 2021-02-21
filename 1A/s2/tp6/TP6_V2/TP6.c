#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
 
void AFFICHAGE_BOISSONS()
{
    FILE* map = NULL;
    int caractere = 0;

    map = fopen("map.txt", "r"); // Ouverture du fichier map.txt

    if (map != NULL) // Boucle de lecture des caractères un à un
    {
        for(;;)
        {
            caractere = fgetc(map); // On lit le caractère
            if (caractere == EOF)
                break;
            printf("%c", caractere); // On l'affiche
        }; // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

        fclose(map); // Fermeture du fichier map.txt
        printf("\n");
    }

}

void REMP_NOMS_BOISSONS(char BOISSONS[10][20], int choix)
{
    int i=0;
    printf("Vous avez choisi la boisson  :");
    while(BOISSONS[choix][i]!='\0')
    {
        printf("%c\n",BOISSONS[choix][i] );
        i++;
    }
 
}

void ACHAT_BOISSON(double MONNAIE_DISPO[],double PRIX_BOISSON[], int choix,double Somme)
{
    double r=0;
    int temp=0;

  

    printf("Donnez votre montant:  ");
    scanf("%lf",&Somme);
    printf("\n");

    Somme-=PRIX_BOISSON[choix];

    for (int i = 0; i < 9 ; i++)
    {
        while(Somme/MONNAIE_DISPO[i]>=1 && Somme !=0 )              
        {
        	if(Somme==0){break;}
            temp++;                                //compteur pour le nombre de billet
            r+=MONNAIE_DISPO[i];
            Somme-=MONNAIE_DISPO[i]; 
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("On vous rend [%dx]   %.2lf$.\n",temp,MONNAIE_DISPO[i]);
        
        temp=0;
    }
           printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("~~~Le total rendu est : %.2lf $ ~~~\n",r );
}




void ACHAT_BOISSON_2(double MONNAIE_DISPO[],int NB_PIECE_DISPO[],double PRIX_BOISSON[], int choix,double Somme)
{
	 double r=0;
    int temp=0;

    
    printf("Vous devez %.2f ",PRIX_BOISSON[choix]);
    printf("Donnez votre montant:  ");
    scanf("%lf",&Somme);
    printf("\n");

    Somme-=PRIX_BOISSON[choix];
    for (int i = 0; i < 15 ; i++)
    {
        while(Somme/MONNAIE_DISPO[i]>=1 && Somme!=0 && NB_PIECE_DISPO[i]!=0)              
        {
            temp++;                                //compteur pour le nombre de billet
            r+=MONNAIE_DISPO[i];
            NB_PIECE_DISPO[i]-=1;
            Somme-=MONNAIE_DISPO[i];   
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("On vous rend [%dx]   %.2lf$.\n",temp,MONNAIE_DISPO[i]);
        
        temp=0;
    }
           printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("~~~Le total rendu est : %.2lf $ ~~~\n",r );
}

void ACHAT_BOISSON_3(double MONNAIE_DISPO[],int NB_PIECE_DISPO[],double PRIX_BOISSON[], int choix,double Somme)
{
    
     double r=0;
    int temp=0;
    int temp2=0;
    double pref;
    int k=20;
    
    printf("Vous devez %.2f ",PRIX_BOISSON[choix]);

    printf("Donnez votre montant:  ");
    scanf("%lf",&Somme);

    printf("Quelle est votre monnaie préféré ?\n");
    scanf("%lf",&pref);
    printf("\n");

    for(int j=0;j<9;j++)
    {
        if(MONNAIE_DISPO[j]==pref)
        {
            temp2=j;
        }

    }

    Somme-=PRIX_BOISSON[choix];
    for (int i = temp2; i < 9 ; i++)
    {
        while(Somme/MONNAIE_DISPO[i]>=1 && Somme!=0 && NB_PIECE_DISPO[i]!=0)              
        {
            temp++;                                //compteur pour le nombre de billet
            r+=MONNAIE_DISPO[i];
            Somme-=MONNAIE_DISPO[i];   
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("On vous rend [%dx]   %.2lf$.\n",temp,MONNAIE_DISPO[i]);
        
        temp=0;
    }
           printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("~~~Le total rendu est : %.2lf $ ~~~\n",r );
}
int main() 
{
    int choix, somme;
    double Monnaie[9]={5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};
    double PRIX_BOISSON[10]={0.70,0.80,0.60,0.50,0.40,0.60,0.60,1.00,1.20,0.40};
    int PIECE_DISPO[9]={1,2,1,3,5,3,2,5,6};
    char BOISSONS[10][20]={"Café court","Café long","Café au lait","Chocolat","Lait","Thé au citron","Thé à la menthe","Thé au gingembre","Thé a miel","Eau"};

    AFFICHAGE_BOISSONS();
    printf("Saisir votre numéro de votre choix:  ");
    scanf("%d",&choix);
     printf("\n");
    //ACHAT_BOISSON(Monnaie,PRIX_BOISSON,choix,somme);
    //ACHAT_BOISSON_2(Monnaie,PIECE_DISPO,PRIX_BOISSON,choix,somme);
    ACHAT_BOISSON_3(Monnaie,PIECE_DISPO,PRIX_BOISSON,choix,somme);
   // REMP_NOMS_BOISSONS(BOISSONS,choix);
    

    return 0;
}


