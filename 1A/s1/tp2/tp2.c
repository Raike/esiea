#include <stdio.h>

int main() 
{
    int valI;
    float valF;
    valI=2;
    valF=3.5;

    printf ("%d\n", valI);
    printf ("%lf\n", valF);

    valI--;
    valF += 3;

    printf ("%d\n", valI);
    printf ("%lf\n", valF);

    valI *= 2;
    valF *= 3;

    printf ("%d\n", valI);
    printf ("%lf\n", valF);

    valI /= ( 5/2);
    valF /= 7;

    printf ("%d\n", valI);
    printf ("%lf\n", valF);

    return 0;
}
