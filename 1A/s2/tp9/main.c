#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction.h"

int main()
{
    system("clear");

    int caractere;
    int i = 1;

    FILE* fichier = NULL;
    fichier = fopen("map.txt", "r+");

    if (fichier != NULL)
    {
        for(;;)
        {
            caractere = fgetc(fichier);
            if (caractere == EOF)
            {
                break;
            }
            caractere = caractere - 48;
            //printf("C = %d\n", caractere);
                switch (i)
                {
                case 1:
                    ANVACER(caractere);
                break;
                case 2:
                    RECULER(caractere);
                break;
                case 3:
                    TOURNER_D(caractere);
                break;
                case 4:
                    TOURNER_G(caractere);
                break;
                default:
                    break;
                }
            if (i == 4)
            {
                i = 1;
            }
            else
            {
                i ++;
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier map.txt");
    }

    return 0;
}