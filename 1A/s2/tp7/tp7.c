#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void CHARGEMENT_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
    int Value;
    FILE* Info;

    Info = fopen("mat.txt" , "r");
    for (int i = 0; i < NB_L; i++) 
    {
        for (int j = 0; j < NB_C; j++) 
        {
            fscanf(Info, "%d", &Value);
            MAT[i][j] = Value;
        }
    }
}

void AFFICHAGE_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
    for (int i = 0; i < NB_L; i++) 
    {
        for (int j = 0; j < NB_C; j++) 
        {
        printf("%d ", MAT[i][j]);
        }
    printf("\n");
    }
}

int Min(int a, int b, int c)
{
    if (a < b && a < c) 
    {
        return a;
    }
    if (b < a && b < c) 
    {
        return b;
    }
    else {return c;}
}

int PGCS ( int nb_L, int nb_C, int MAT[nb_L][nb_C])
{
    int i,j,T,min,xi,xy;
    int temp[nb_L][nb_C];

    for (j=0;j<=nb_C -1; j++){temp[0][j]=1;}
    for (i=0; i<=nb_L-1; i++){temp[i][0]=1;}

    T=1; 
    for(i=1; i<=nb_L-1;i++)
    {
        for(j=1; j<=nb_C-1;j++)
        {
        if( MAT[i][j-1]== MAT[i][j] && MAT[i-1][j]==MAT[i][j] && MAT[i-1][j-1]==MAT[i][j])
        {
            min=Min(temp[i][j-1], temp[i-1][j], temp[i-1][j-1])+1;
            temp[i][j]=min;  
            if(T<min)
            { 
                T=min;
            xi=i;
            xy=j;}
        }
        else 
        {
            temp[i][j]=1;
        }
        }
    }
    xi += 1;
    xy += 1;
    AFFICHAGE_MAT(nb_L,nb_C,temp); 
    printf("%d=(%d,%d) \n",T,xi,xy);
    return 0;  
}

void GENERATION_FIC()
{
    int Sizex, Sizey, r;
    srand(time(NULL));
    printf("Entrez le nombre de ligne et de colone\n");
    scanf("%d %d", &Sizex, &Sizey);
    printf("Ligne = %d et colone = %d\n", Sizex, Sizey);

    for (int i = 0; i <= Sizex-1; i++) 
    {
        for (int j = 0; j <= Sizey-1; j++) 
        {
            r = rand()%4;
            if (r==0) 
            {
                printf(" 0");
            } 
            else 
            {
                printf(" 1");
            }
        }
        printf("\n" );
    }
}

int main(int argc, char const *argv[])
{
    int NB_L;
    int NB_C;

    int a, b, c;

    printf("Entrez le nombre de ligne de la matrisse : ");
    scanf("%d", &NB_L);
    printf("Entrez le nombre de colone de la matrisse : ");
    scanf("%d", &NB_C);

    int MAT[NB_L][NB_C];

    CHARGEMENT_MAT(NB_L, NB_C, MAT);
    AFFICHAGE_MAT(NB_L, NB_C, MAT);

    printf("Entrez les valeurs de A B et C : \n");
    scanf("%d %d %d", &a, &b, &c);

    printf("Le minimum est : %d\n",Min(a,b,c));
    PGCS(NB_L, NB_C, MAT);
    GENERATION_FIC();
    return 0;
}
