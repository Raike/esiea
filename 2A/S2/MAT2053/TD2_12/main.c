#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Determ_long_texte(char * mon_fic)
{
    FILE* fic_in = fopen(mon_fic, "r");

    char c;
    int tt = 0;
    while((c=fgetc(fic_in)) != EOF)
    {
        if(c >= 'a' &&  c <= 'z')
        {
            tt +=1;
        }
        else if(c >='A' && c <= 'Z')
        {
            tt +=1;
        }
    }
    fclose(fic_in);
    return tt;
}

void Charger_Cle(int T, char cle[], char * mon_fic_cle)
{
    FILE* fic_in = fopen(mon_fic_cle, "r");

    char c;
    int i = 0;
    while ((c=fgetc(fic_in)) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            cle[i] = c;
            i ++;
        }
    }
}

void Chiff_vigenere(int T, char cle[], char * nom_fic_clair, char * nom_fic_chiff)
{
    FILE* fic_in = fopen(nom_fic_clair, "r");
    FILE* fic_out = fopen(nom_fic_chiff, "w");

    char c;
    char k; 
    int i = 0; 
    
    while((c = fgetc(fic_in)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            k = cle[i%T] - 'a';
            c = c - 'a';
            c = (c + k) % 26;
            fprintf(fic_out, "%c", c + 'a');
            i ++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            k = cle[i%T] - 'A';
            c = c - 'A';
            c = (c + k) % 26;
            fprintf(fic_out, "%c", c + 'A');
            i ++;
        }
        else if (c == ' ')
        {
            fprintf(fic_out, "%c", c);
        }
    }
}

void Dechiff_vienere(int T, char cle[], char * nom_fic_chiff, char * nom_fic_dechiff)
{
    FILE* fic_in = fopen(nom_fic_chiff, "r");
    FILE* fic_out = fopen(nom_fic_dechiff, "w");

    char c;
    char k;
    int i = 0;

    while((c = fgetc(fic_in)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            k = cle[i%T] + 'a';
            c = c + 'a';
            c = (c - k + 26) % 26;
            fprintf(fic_out, "%c", c - 'a');
            i ++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            k = cle[i%T] + 'A';
            c = c + 'A';
            c = (c - k + 26) % 26;
            fprintf(fic_out, "%c", c - 'A');
            i ++;
        }
        else if (c == ' ')
        {
            fprintf(fic_out, "%c", c);
        }
    }
}

int main(int argc, char ** argv)
{
    int T = Determ_long_texte(argv[1]);
    char cle[T];

    printf("Size = %d\n", T);
    Charger_Cle(T, cle, argv[1]);

    Chiff_vigenere(T, cle, argv[2], argv[3]);

    Dechiff_vienere(T, cle, argv[3], argv[4]);


    return 0;
}