#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef __GRAPH__H__
#define __GRAPH__H__

typedef struct Graph
{
    int **Matrice;
    int vertices;
    int **successors_list;
    int *nb_successors_vertices;
    int nb_;
    int arc;
}Graph;

void Menu(Graph *g, Graph *gC);
void ReadGraph(Graph *g, Graph *gC);
void Print(Graph *g, Graph *gC);
void Carre(Graph *g,Graph *gC);
void Sucessor(Graph *g, Graph *gC);
void NewGraph(Graph *g, Graph *gC);

#endif //__GRAPH__H__
