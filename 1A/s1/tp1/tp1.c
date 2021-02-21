#include <stdio.h>

int main() 
{
    float n;
    float result = 0;
    printf("Donné a la valeur de n\n");
    scanf("%f", &n);

    for (int i = 0; i <= n; i++)
    {
        result += 1/i;
    }

    printf("la valeur du réesultat est : %f", result);

    return 0;
}
