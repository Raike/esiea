#include <stdio.h>
#include <stdlib.h>

int OCCU(int T[], int N, int X)
{
    if (N == 0)
        return 0;
    if(*T == X) 
        return 1 + OCCU(T+1 ,N-1 ,X);
    else
        return OCCU(T+1 ,N-1 ,X);
}

int main()
{
    int T[100];
    for (int i = 0; i <= 100; i++)
    {
        T[i] = rand() % 10;
    }
    int N = 100;
    int X = 0;

    printf("Quelle nombre entre 0 et 9 recherchez vous ?");
    scanf("%d",&X);
    printf("%d apparait %d fois dans ce tableau\n", X, OCCU(T,N,X));
    
    return 0;
}