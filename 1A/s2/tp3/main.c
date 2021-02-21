#include <stdio.h>
#include <stdlib.h>

void racine_carree (double n, double e)
{
    double a = 0;
    double b = n;
    double m = 0;

    while (b - a >= e)
    {
        m = (a + b) / 2;

        if (m * m <= n)
        {
            a = m;
        }
        else
        {
            b = m;
        }
    }
    
    printf("\nRacine Carree = %lf\n",a);
}

void min_TAB(int size, int Tab[])
{
	int reference=Tab[0];
	for (int i = 0; i < size; i++)
	{
		if (Tab[i]<reference)
		{
			reference=Tab[i];
		}
	}
	printf("Le min de Tab est : %d \n",reference);

}

void determ_nbre_seq(int size, int Tab[])
{
    int i = 0;
    int j =0;
    int nb_ss= 0;
    int d = 0;
    int f = 0;
    

    while (i < size)
    {
        j = i;
        while (j != size-1 && Tab[j] < Tab[j+1])
        {
            j ++;
        }
        nb_ss = nb_ss +1;
        if ((j - i) > (f - d))
        {
            d = i;
            f =j;
        }
        i = j + 1;
    }
    printf("NB_SS = %d | D = %d | F = %d\n", nb_ss, d, f);
}

void Recherche_Dicho(int size, int Tab[], int ELT)
{
    int a = 0;
    int b = size;
    int m = 0;

    while (a < b)
    {
        m = (a+b)/2;

        if (Tab[m] >= ELT)
        {
            b = m;
        }
        else
        {
            a = m + 1;
        }
        
    }
    printf("b = %d\n", b);
}

int main()
{
    // FONCTION RACINE CARREE 

    double n = 0;
    double e = 1;

    printf("Donnez le nombre d'on vous recherchez la racine carree puis la précision : ");
    scanf("%lf %lf", &n, &e);

    racine_carree(n, e);

    // FONCTION MIN TAB

    int Tab[10] = {1, 8, 3, 0, 5, 6, 9, 2, 7};
    min_TAB(10, Tab);

    // FONCTION DETERM NBRE SEQ

    int TabS[15] = {1, 2, 5, 3, 12, 25, 13, 8, 4, 7, 24, 28, 32, 11, 14};
    determ_nbre_seq(15, TabS);

    // FONCTION RECHERCHE DICHO 

    int TabM[15] = {1, 2, 2, 3, 3, 3, 6, 7, 8, 9, 10, 11, 12, 13 ,14};
    int ELT = 0;
    printf("Donnez l'ELT : ");
    scanf("%d", &ELT);

    Recherche_Dicho(15, TabM, ELT);

    return 0;
