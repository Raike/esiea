#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int nb_serie = 1;
    int time_S1 = 0;
    int rep_S1 = 0;

    system ("clear");
    printf("Welcome to Time Manager\n\n");

    printf("Combient de temps vas durée votre premiere serie (en mins) : ");
    scanf("%d", &time_S1);
    printf("Combient de répétition contien cette série : ");
    scanf("%d", &rep_S1);

    return 0;
}