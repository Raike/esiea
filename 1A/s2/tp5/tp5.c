/*#include <stdio.h>
#include <stdlib.h>

void REMPLISSAGE_TAB (int size, int TAB[size]) 
{
    for (int i = 0; i < size; i++)
    {
        TAB[i] = rand() % 100; 
    }
}

void AFFICHAGE_TAB (int size, int TAB[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", TAB[i]); 
    }
    printf("\n");
}

void FUSION(int size, int TAB[], int d, int n, int f)
{
    int r[f-d+1];
    int i1=d; 
    int i2=n+1;
    int k=0;
    while(i1 <= n && i2 <= f)
    {
        if (TAB[i1] < TAB[i2])
        {
            r[k] = TAB[i1];
            i1++;
        }
        else
        {
            r[k] = TAB[i2];
            i2++;
        }
    k++;
    }
    while(i1 <= n)
    {
        r[k] = TAB[i1];
        i1++;
        k++;
    }
    while(i2 <= f)
    {
        r[k] = TAB[i2];
        i2++;
        k++;
    }
    for(k=0; k <= f-d; k++)
    {
        TAB[d+k] = r[k];
    }
}

void TRI_FUSION (int size, int TAB[size], int a, int b)
{
    int c = 0;
    if (a != b)
    {
        c = (a + b)/2;
        TRI_FUSION(size, TAB, a, c);
        TRI_FUSION(size, TAB, c + 1, b);
        FUSION(size, TAB, a, c, b);
    }
    AFFICHAGE_TAB(size, TAB);
}

int main()
{
    int TAB[15];
    int size = 15;
    REMPLISSAGE_TAB(15, TAB);
    printf("Tableau early: \n");
    AFFICHAGE_TAB(15, TAB);
    printf("\n");
    TRI_FUSION(size, TAB,0, size-1);
    printf("\nTableau end : \n");
    AFFICHAGE_TAB(size, TAB);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void REMPLISSAGE_TAB(int n,int tab[n])
{
  int M;                 //Nombre random
  for(int i=0;i<n;i++)
  {
    M=rand()%100;            // initialisation du nombre random
     tab[i]=M;
  }
}

void AFFICHAGE_TAB(int n,int tab[n])
{
  for(int i=0;i<n;i++)
  {
    printf("%d ", tab[i]);
  }
  printf("\n" );
}

void FUSION(int n,int tab[n],int g,int m,int d)
{
int r[d-g+1];
int i=g;
int j=m+1;
int l=0;

  while (i<=m && j <=d)
{
    if (tab[i] < tab[j])
    {
      r[l] = tab[i];
      i++;
    }
    else
   {
      r[l] = tab[j];
      j++;
   }
l++;
}
while (i <=m)
{
    r[l] = tab[i];
    i++;
    l++;
}
while (j<=d)
{
    r[l] = tab[j];
    j++;
    l++;
}
    for(int w =0; w<= d-g; w++)
    {
      tab[g+w]=r[w];
    }
  }


void TRI_FUSION(int n, int tab[n], int g,int d)
{
  int c=0;
  if(g!=d)
  {
   c=(g+d)/2;
    TRI_FUSION(n,tab,g,c);
    TRI_FUSION(n,tab,c+1,d);
    FUSION(n,tab,g,c,d);

}}

 int main()
   {
   printf("Saisir la taille du tableau:  " );
   int n;
   int g=0;
   int d=n-1;
   int m = (d+g)/2;
   scanf("%d",&n);
   int TAB[n];
   REMPLISSAGE_TAB(n,TAB);
   AFFICHAGE_TAB(n,TAB);
   TRI_FUSION(n,TAB,0,n-1);
   AFFICHAGE_TAB(n,TAB);

  return 0;
}