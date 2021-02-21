#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void chiff_cesar(int k, char * nom_fic_c, char * nom_fic_s)
{
    FILE* fic_clair = fopen(nom_fic_c, "r");
    FILE* fic_chiff = fopen(nom_fic_s, "w");

    char c;
    char chiff; 

    while ((c=fgetc(fic_clair)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c-97+k) %26;

            fprintf(fic_chiff, "%c", c+97);
        }
    }
    fclose(fic_chiff);
    fclose(fic_clair);
}

void dechiff_cesar(int k, char * nom_fic_s, char * nom_fic_k)
{
    FILE* fic_in = fopen(nom_fic_s, "r");
    FILE* fic_out = fopen(nom_fic_k, "w");

    char c;

    while ((c=fgetc(fic_in)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c-97-k+26) %26;

            fprintf(fic_out, "%c", c+97);
        }
    }
    fclose(fic_in);
    fclose(fic_out);
}

void chiff_cesar_ascii(int k, char * nom_fic_c, char * nom_fic_s)
{
    FILE* fic_clair = fopen(nom_fic_c, "r");
    FILE* fic_chiff = fopen(nom_fic_s, "w");

    char c;

    while ((c=fgetc(fic_clair)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c+k) %128;

            fprintf(fic_chiff, "%c", c);
        }
    }
    fclose(fic_chiff);
    fclose(fic_clair);
}

void dechiff_cesar_ascii(int k, char * nom_fic_s, char * nom_fic_k)
{
    FILE* fic_in = fopen(nom_fic_s, "r");
    FILE* fic_out = fopen(nom_fic_k, "w");

    char c;
    char chiff; 

    while ((c=fgetc(fic_in)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c-k+128) %128;

            fprintf(fic_out, "%c", c);
        }
    }
    fclose(fic_in);
    fclose(fic_out);
}

int main(int argc, char ** argv)
{
    int k;
    printf("Donnez le décalage k : ");
    scanf("%d",&k);
    chiff_cesar(k, argv[1], argv[2]);
    dechiff_cesar(k, argv[2], argv[3]);
    chiff_cesar_ascii(k, argv[1], argv[2]);
    dechiff_cesar_ascii(k, argv[2], argv[3]);
    return 0;
}
