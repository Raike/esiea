#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Init_tableau_rand(int T, int TAB[])
{
    int i;
    for ( i =0;  i<T; i++)
    {
        TAB[i] = (rand()%9)+1;
    }
}

void Affiche_tableau(int T, int TAB[])
{
    int i;
    for (i=0; i < T; i++)
    {
        printf("%d ", TAB[i]);
    }
    printf("\n");

}

int main()
{
    srand(time(NULL));
    int  TAB[10];
    Init_tableau_rand(10, TAB);
    Affiche_tableau(10, TAB);
    return 0;

}