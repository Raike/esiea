#include <stdio.h>
#include <stdlib.h>

void Tabinfo(int T[])
{
    //nbp
    int nbp = 0;

    for (int i = 0; i < 14; i++)
    {
        if (T[i] >= 0)
        {
            nbp ++;
        }
    }
    printf("nbp = %d \n", nbp);

    //nbn
    int nbn = 0;

    for (int i = 0; i < 14; i++)
    {
        if (T[i] < 0)
        {
            nbn ++;
        }
    }
    printf("nbn = %d \n", nbn);

    //TP
    int TP[nbp];
    int j = 0;

    for (int i = 0; i < 14; i++)
    {
        if (T[i] >= 0)
        {
            TP[j] = T[i];
        }
    }

    //TN
    int TN[nbn];
    j = 0;

    for (int i = 0; i < 14; i++)
    {
        if (T[i] < 0)
        {
            TN[j] = T[i];
        }
    }
}

int main()
{
    int T[14] = {-2,-1,0,1,2,3,4,5,6,7,8,9,-1,-5};

    Tabinfo(T);

    return 0;
}