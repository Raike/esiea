#include<stdio.h>

int ESIEA(int a, int b)
{
    while (a != b)
    {
        if( a >= b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int ESIEA_REC(int a, int b)
{
        if( a > b)
        {
            ESIEA_REC(a-b,b);
        }
        else
        {
            ESIEA_REC(a,b- a);
        }
    return a;
}

int main()
{
    printf("%d", ESIEA(50, 10));
    printf("%d", ESIEA_REC(50, 10));
    return 0;
}