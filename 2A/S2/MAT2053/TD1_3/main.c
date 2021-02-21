#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void calc_fre_lettre_alpha(float alpha[26], char * nom_fic)
{
    char c;
    int total = 0;

    FILE * fic = fopen(nom_fic, "r");
    while ((c=fgetc(fic)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            alpha[c-97] += 1.0;
            total ++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = alpha[i] / total;
    }
    fclose(fic);
}

int affic_plus_grde_freq(float alpha[26])
{
    float value = alpha[0];
    int temp;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > value)
        {
            value = alpha[i];
            temp = i;
        }
    }
    printf("La plus grande fréquence est : %c = %f\n", temp+97, value);

    return temp;
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

int main (int argc, char ** argv)
{
    float freq[26] = {0.0}; 
    calc_fre_lettre_alpha(freq, argv[1]);

    printf("freq : \n");
    for (int i = 0; i < 26; i++)
    {
        printf(" %c = %f \n", i+97, freq[i]);
    }
    char max_value = affic_plus_grde_freq(freq) + 97;

    int key = max_value - 'e';

    dechiff_cesar(key, argv[1], argv[2]);
    return 0;
}