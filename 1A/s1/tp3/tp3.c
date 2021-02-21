#include <stdio.h>

int main() 
{
    int harmonic;
    float i = 1;
    float r = 0;
    printf("Rank of the Harmonic serie ? \n");
    scanf("%d", &harmonic);

    while(i < harmonic)
    {
        printf("1/%.f +", i);
        r= r + (1/i);
        i++;

        if (i == harmonic)
        {
            r = r + 1/i;
            printf ("1/%.f", i);
            printf (" = %f\n", r);
        }
    
    }

    return 0;
}
