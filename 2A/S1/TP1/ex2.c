#include <stdio.h>
#include <stdlib.h>

int NBM(char chaine[], int N)
{
    if (* chaine == '\0')
    {
        return 0;
    }
    
    int X = * chaine;
    
    if (X <= 90)
    {
        return 1 + NBM(chaine + 1, N -1);
    }
    else
    {
        return NBM(chaine + 1, N -1);
    }
}

int main()
{
    char chaine[] = "AndrieuRemi";
    int N = 12;

    printf("Il ya %d majuscules dans cette chaine de caractères\n", NBM(chaine, N));
    return 0;
}