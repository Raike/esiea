#include <stdio.h>
#include <stdlib.h>

int Multi(int A, int B)
{
    if (B == 0)
    {
        return 0;
    }
    else if (B % 2 != 0)
    {
        return A * (B -1) + A;
    }
    else if (B % 2 == 0)
    {
        return 2 * A * (B/2);
    }
}

int main()
{
    int A = 0;
    int B = 0;

    printf("Donnez les valeur de A et B :");
    scanf("%d %d", &A, &B);
    printf("Le résulta de la multiplication est : %d", Multi(A,B));

    return 0;
}e