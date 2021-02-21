#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "graphe.h"

int main()
{
    system("clear");

    FILE* fic = fopen("graphe.txt", "r");

    int sommet_value = fgetc(fic) - 48;

    int Matrice[sommet_value][sommet_value];

    for (int i = 0; i < sommet_value; i++)
    {
        for (int j = 0; j < sommet_value; j++)
        {
            Matrice[i][j] = 0;
        }
    }

    menu(sommet_value, Matrice);

    return 0;
}