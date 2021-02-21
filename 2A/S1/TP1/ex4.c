#include <stdio.h>
#include <stdlib.h>

int DICHREC (int T[], int N, int X)
{
    if (T[N] > X)
    {
       return DICHREC(T,N - 1, X);
    }
    else if (T[N] < X)
    {
       return DICHREC(T,N + 1, X);
    }
    else
    {
        return N;
    }
}

int DICHRECMULTI (int N, int M, int X,int TT[N][M])
{
    if (TT[N][M] > X)
    {
        if (M == 0)
        {
            return DICHRECMULTI(N - 1,M - 1, X,TT);
        }
        else
        {
            return DICHRECMULTI(N ,M - 1, X,TT);
        }
    }
    else if (TT[N][M] < X)
    {
        if (M == 5)
        {
            return DICHRECMULTI(N + 1,M + 1, X,TT);
        }
        else
        {
            return DICHRECMULTI(N ,M +1, X,TT);
        }
    }
    else
    {
        return N+M;
    }
}

int main()
{
    int T[10] = {0,1,2,3,4,5,6,7,8,9};
    int TT[2][5] = {0,1,2,3,4,5,6,7,8,9};
    int N = 0;
    int M = 0;
    int X = 0;

    printf("Quelle nombre entre 0 et 9 recherchez vous ? ");
    scanf("%d", &X);
    printf("\n%d ce trouve a la position %d dans le tableau a une dimension\n", X, DICHREC(T,N,X));
    printf("\n%d ce trouve a la position %d dans le tableau a deux dimension\n", X, DICHRECMULTI(N,M,X,TT));

    

    return 0;
}