#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void chiff_verman(char * nom_fic_clair, char * nom_fic_chiff, char * nom_fic_cle)
{
    FILE* fic_in = fopen(nom_fic_clair, "rb");
    FILE* fic_out = fopen(nom_fic_chiff, "wb");
    FILE* fic_key = fopen(nom_fic_cle, "wb");

    int octet_alea;
    int octet_clair;
    int octet_chiff;

    while((octet_clair = fgetc(fic_in)) != EOF)
    {
        octet_alea = rand() % 256;
        octet_chiff = octet_alea ^ octet_clair;
        fputc(octet_chiff,fic_out);
        fputc(octet_alea,fic_key);
    }

    fclose(fic_in);
    fclose(fic_out);
    fclose(fic_key);
}

int main(int argc, char ** argv)
{
    srand(time(NULL));

    chiff_verman(argv[1], argv[2], argv[3]);
    return 0;
}