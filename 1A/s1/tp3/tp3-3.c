#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int ligne;
    printf("Entrez le nombre de lignes\n");
    scanf("%d", &ligne);

    for (int i = 0; i < ligne; i++)
    {
        
        for (int j = 0; j < 60; j++)
        {
        
            int ramdom;
            ramdom = rand() % 2;

            if (ramdom == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
        }
        
        }
       
        printf("\n");

    }
    

    return 0;
}
