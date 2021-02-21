#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef FONCTION_H
#define FONCTION_H

void menu(int sommet_value, int Matrice[sommet_value][sommet_value]);
void read_g(int sommet_value, int Matrice[sommet_value][sommet_value]);
void print(int sommet_value, int Matrice[sommet_value][sommet_value]);
void chemins(int sommet_value, int Matrice[sommet_value][sommet_value]);
void successeurs(int sommet_value, int Matrice[sommet_value][sommet_value]);
void new_graph(int sommet_value, int Matrice[sommet_value][sommet_value]);

#endif //fonction.h