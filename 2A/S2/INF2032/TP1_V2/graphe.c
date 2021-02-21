#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Menu(Graph *g, Graph *gC)
{
    printf("\n\n");
    int choice = -1;

    printf("**MENU**\n\n-> Lire le graphe G (1) \n-> Afficher la matrice (2)\n-> Nombre de chemins (3)\n-> Liste des successeurs (4)\n-> Création d'un nouveau graphe (5)\n-> Quitter (0)\n\n-> Votre choix : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        ReadGraph(g, gC);
        break;
    case 2:
        Print(g, gC);
        break;
    case 3:
        Carre(g, gC);
        break;
    case 4:
        Sucessor(g, gC);
        break;
    case 5:
        NewGraph(g, gC);
        break;
    case 0:
        exit(0);
        break;
    } 
}

void ReadGraph(Graph *g, Graph *gC)
{
    g->Matrice=(int**)malloc(sizeof(int *)*g->vertices);

    FILE * fic = fopen("graphe.txt", "r");

    fscanf(fic,"%d\n",&g->vertices);
    printf("Nombre de vertices %d\n", g->vertices);


    g->Matrice=(int**)malloc(sizeof(int*)* g->vertices);
    for(int i=0 ;i<g->vertices ;i++)
    {
        g->Matrice[i]=(int*)malloc(sizeof(int)* g->vertices);
    }
    for(int j=0; j< g->vertices;j++)
    {
        for(int i =0; i< g->vertices;i++)
        {
            g->Matrice[j][i]=0;
        }
    }
    while(!feof(fic))
    {
        int a,b=0;
        fscanf(fic,"%d %d\n", &a,&b);
        g->Matrice[a][b]=1;
        g->arc+=0;
        printf("%d %d \n",a ,b);
       
    }
    Menu(g, gC);
}

void Print(Graph *g, Graph *gC)
{
    printf("\nLa Matrice est : \n");
    for(int j=0; j< g->vertices;j++)
    {
        for(int i =0; i< g->vertices;i++)
        {
            printf("%d ", g->Matrice[j][i]);
        }
        printf("\n");
    }
    Menu(g, gC);
}

void Carre(Graph *g, Graph *gC)
{
    int tt = 0;
    gC->vertices=g->vertices;
    gC->Matrice=(int**)malloc(sizeof(int*)* gC->vertices);
    for(int i=0 ;i<gC->vertices ;i++)
    {
        gC->Matrice[i]=(int*)malloc(sizeof(int)* gC->vertices);
    }

    if(g->Matrice==NULL)
        printf("error G");

    if(gC->Matrice==NULL)
        printf("error GC");

    printf("\nLa Matrice carré est de taille : ");
    printf("%d %d\n",g->vertices,gC->vertices);

    for(int n = 0; n < g->vertices; n++)
    {    
        for(int m = 0; m < g->vertices; m++)
        {
            for(int p = 0; p < g->vertices; p++)
            {
               gC->Matrice[n][m]+=(g->Matrice[n][p])*(g->Matrice[p][m]);
            }
        }
    }

    for(int j=0; j< g->vertices;j++)
    {
        for(int i =0; i< g->vertices;i++)
        {
            printf("%d ", gC->Matrice[j][i]);
            tt += gC->Matrice[j][i];
        }
        printf("\n");
    }
    Menu(g, gC);
}

void Sucessor(Graph *g, Graph *gC)
{
    printf("\nLes successeurs sont : \n");
    g->successors_list=(int**)malloc(sizeof(int *)*g->vertices);
    g->nb_successors_vertices=(int*)malloc(sizeof(int)* g->vertices);

    int counter_succ=0;
    for(int j=0; j<g->vertices; j++)
    {
        for(int i=0;i<g->vertices;i++)
        {
            if(g->Matrice[j][i]==1)
            {
                counter_succ+=1;
            }
        }
        g->nb_successors_vertices[j]=counter_succ;
        g->successors_list[j]=(int*)malloc(sizeof(int)* counter_succ);
    }
    int idx=0;
    for (int i = 0; i < g->vertices; i++)
    {
        idx=0;
        printf("Sommet %d : ", i);
        for (int j = 0; j < g->vertices; j++)
        {
            if (g->Matrice[i][j] == 1)
            {
                g->successors_list[j][idx]=i;
                printf("%d ->> %d  ", i ,j);
                idx++;
            }
        }
        printf("\n");
    }
    Menu(g, gC);
}

void NewGraph(Graph *g, Graph *gC)
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
    Menu(g, gC);
}