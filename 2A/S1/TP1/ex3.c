#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool PALINDROME(char chaine[], int N, int D)
{
    if (N == D)
    {
        return true;
    }
    if (chaine[D] != chaine[N])
    {
        return false;
    }
    if (D < N + 1)
    {
        return PALINDROME(chaine, N - 1, D + 1);
    }
    return true;
}

int main()
{
    char chaine[] = "radar";
    int N = 4; // Position de la derniere lettre de la chaine de caractere 
    int D = 0;
    if (PALINDROME(chaine,N,D) == true)
    {
        printf("cette chaine est un palindrome\n");
    }
    else
    {
        printf("cette chaine n'est pas un palindrome\n");
    }
    
    return 0;
}