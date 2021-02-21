#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *chargement_aleatoire(int *tab, int nb)
{
    for (int i = 0; i < 20; i++)
    {
        tab[i] = 1 + rand() % 99; // valeur random entre (0 ; 98) + 1 = (1 ; 99)
    }

    return tab;
}

void tabmax_place(int T[], int n, int *max, int *place)
{
    for (int i=0 ; i < n ; i++)
    {
        if(T[i] > *max)
        {
            *max = T[i];
            *place = i;
        }
    }
    printf("Le max est %d a la place %d\nto", *max, *place);
}

int main()
{
    int T[25];
    int nb = 25;
    int max = 0;
    int place = 0;

    srand( time( NULL ) );

    chargement_aleatoire(&T, nb);
    tabmax_place(T, nb, &max, &place);

    return 0;
}