#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "graphe.h"

void menu(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    printf("\n\n");
    int choice = -1;

    printf("**MENU**\n\n-> Lire le graphe G (1) \n-> Afficher la matrice (2)\n-> Nombre de chemins (3)\n-> Liste des successeurs (4)\n-> Création d'un nouveau graphe (5)\n-> Quitter (0)\n\n-> Votre choix : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        read_g(sommet_value, Matrice);
        break;
    case 2:
        print(sommet_value, Matrice);
        break;
    case 3:
        chemins(sommet_value, Matrice);
        break;
    case 4:
        successeurs(sommet_value, Matrice);
        break;
    case 5:
        new_graph(sommet_value, Matrice);
        break;
    case 0:
        exit(0);
        break;
    } 
}

void read_g(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    FILE* fic = fopen("graphe.txt", "r");

    fseek(fic, 1, SEEK_SET);

    int temp_1 = 0;
    int temp_2 = 0;
    int n = 0;

    while ((n = fgetc(fic)) != EOF)
    {
        fscanf(fic, "%d %d", &temp_1, &temp_2);
        Matrice[temp_1][temp_2] = 1;
    }
    fclose(fic);
    menu(sommet_value, Matrice);
}

void print(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    printf("La matrice est : \n\n");
    for (int i = 0; i < sommet_value; i++)
    {
        for (int j = 0; j < sommet_value; j++)
        {
            printf("%d ", Matrice[i][j]);
        }
        printf("\n");
    }
    menu(sommet_value, Matrice);
}

void chemins(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    int tt = 0;

    for(int i = 0; i < sommet_value; i++)
    {
        for(int j = 0; j < sommet_value; j++)
        {
            for(int k = 0; k < sommet_value; k++)
            {
                tt += Matrice[i][k] * Matrice[k][j];
            }
        }
    }

    printf("\nIl y a %d chemins de longeur 2", tt);
    menu(sommet_value, Matrice);
}

void successeurs(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    printf("\nListe des successeurs : \n");

    for (int i = 0; i < sommet_value; i++)
    {
        printf("Sommet %d : ", i);
        for (int j = 0; j < sommet_value; j++)
        {
            if (Matrice[i][j] == 1)
            {
                printf("%d ->> %d  ", i ,j);
            }
        }
        printf("\n");
    }
}

void new_graph(int sommet_value, int Matrice[sommet_value][sommet_value])
{
    int nbr_sommet = 0;
    int nbr_arcs = 0;
    int temp_1 = 0;
    int temp_2 = 0;

    FILE* fic = fopen("new_graphe.txt", "w");

    printf("\n=> indiquer le nombre de sommet : ");
    scanf("%d", &nbr_sommet);
    fprintf(fic, "%d\n", nbr_sommet);
    printf("\n=> indiquer le nombre d'arcs du grpahe : ");
    scanf("%d", &nbr_arcs);

    for (int i = 0; i < nbr_arcs; i++)
    {
        scanf("%d %d", &temp_1, &temp_2);
        fprintf(fic, "%d %d\n", temp_1, temp_2);
    }
    menu(sommet_value, Matrice);
}