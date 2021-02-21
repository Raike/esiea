#include <stdio.h>

int main() 
{
    int hauteur;
    int espace = 0;
    int fin;
    printf("Quelle est la taille de la pyramide ? \n");
    scanf("%d", &hauteur);

   /* while (hauteur != 0)
    {
        for (int j = 0; j < hauteur; j++)
        {
            printf ("* ");
        }
        printf("\n");
        
        hauteur -= 1;
        espace ++;
        
        for (int a = 0; a < espace; a++)
        {
            printf(" ");
        }
        
    }  
    printf("\n");
    */
   while (hauteur !=0)
   {
       for (int i = 0 ; i < 2*hauteur -1 ; i++)
        {
        printf("*");
        }
        printf("\n");
        hauteur -= 1;
        espace ++;
        
        for (int a = 0; a < espace; a++)
        {
            printf(" ");
        }
   }
   
    return 0;
}
