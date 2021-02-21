#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void charger_cle(char cle[26], char my_key[])
{
    FILE* fic = fopen(my_key, "r");

    char c;
    int i = 0;

    while ((c=fgetc(fic)) != EOF)
    {
        cle[i] = c;
        i ++;
    }
}

void chiff_mono_alpha(char cle[26], char * nom_fichier_clair, char * nom_fichier_chiff)
{
    FILE* fic_clair = fopen(nom_fichier_clair, "r");
    FILE* fic_chiff = fopen(nom_fichier_chiff, "w");

    char c;
    char chiff; 

    while ((c=fgetc(fic_clair)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            chiff = cle[c-'a'];
            fprintf(fic_chiff, "%c", chiff);
        }
    }
}

void dechiff_mono_alpha(char cle[26], char * nom_fichier_chiff, char * nom_fichier_dechiff)
{
    FILE* fic_chiff = fopen(nom_fichier_chiff, "r");
    FILE* fic_dechiff = fopen(nom_fichier_dechiff, "w");
    
    char c;
    char dechiff; 
    int i = 0;

    while((c=fgetc(fic_chiff)) != EOF)
    {
        for (int i = 0; i <= 26; i++)
        {
            if (c != cle[i])
            {
                i ++;
            }
            else
            {
                dechiff = cle[i+'a'];
                fprintf(fic_dechiff,"%c",dechiff);
            }

        }
    }
}

int main(int argc, char ** argv)
{
    char cle[26];

    charger_cle(cle, argv[1]);

    printf("la clé est : ");
    for (int i = 0; i < 26; i++)
    {
        printf("%c", cle[i]);
    }
    printf("\n");

    chiff_mono_alpha(cle, argv[2], argv[3]);
    dechiff_mono_alpha(cle, argv[3], argv[4]);
    return 0;
}