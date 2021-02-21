#include <stdio.h>
#include <stdlib.h>

void affichage_tab(int tab[], int size)
{
    for (int i = 0; i <= size; i++)
    {
      printf("%d ",tab[i]);
    }
    printf("\n");
}

void tri_rapide(int tab[], int g, int d)
{
    int m=0;
    if (g < d)
    {
      m = PARTITION_LOMUTO(tab, g, d);
      tri_rapide(tab, g ,m - 1);
      tri_rapide(tab, m + 1, d);
    }
}

void tri_rapide_d_g(int tab[], int g, int d)
{
    int m=0;
    if (g < d)
    {
      m = PARTITION_LOMUTO_D_G(tab, g, d);
      tri_rapide_d_g(tab, g ,m - 1);
      tri_rapide_d_g(tab, m + 1, d);
    }
}

void tri_rapide_2(int tab[], int g, int d)
{
    int m=0;
    if (g < d)
    {
      int m = PARTITION_Hoare(tab, g, d);
      tri_rapide_2(tab, g ,m);
      tri_rapide_2(tab, m + 1, d);
    }
}

int PARTITION_LOMUTO(int tab[],int g,int d)
{
    int temp2=0;
    int temp=0;
    int x = tab[d];
    int i = g - 1;
    for(int j = g; j <= d - 1; j++)
  {
    if (tab[j] <= x)
    {
      i++;
      temp=tab[i];
      tab[i]=tab[j];
      tab[j]=temp;
    }
  }
    temp2=tab[i+1];
    tab[i+1]=tab[d];
    tab[d]=temp2;

     printf("Apres LOMUTO : ");
     affichage_tab(tab, 11);

     return i+1;
}

int PARTITION_LOMUTO_D_G(int tab[],int g,int d)
{
     int temp = 0;
     int temp2 = 0;
     int x = tab[g];
     int i = d + 1;
     int rang = 0;

     for(int j = d; j >= g; j --)
     {
        if (tab[j] > x) 
        {
          i --;
          temp = tab[i];
          tab[i] = tab[j];
          tab[j] = temp;
        }
     }
     temp2 = tab[i-1];
     tab[i-1] = tab[g];
     tab[g] = temp2;

     printf("Apres LOMUTO : ");
     affichage_tab(tab, 11);
     return i-1;
}

int PARTITION_Hoare(int tab[],int g, int d)
{
  int temp=0;
  int x= tab[g];
  int i=g-1;
  int j=d+1;

  while(1)
  {
    do{j--;}while(tab[j]>x);
   do {i++;}while(tab[i]<x);
        if(i<j)
        {
          temp=tab[i];
          tab[i]=tab[j];
          tab[j]=temp;
        }

        else 
        {
          printf("Apres HOARE : ");
          affichage_tab(tab,11);
          return j;
          }
  }
}

int main() 
{
    // PARTIE A : LOMUTO

    printf("\nPARTIE A \n\n");

    // QUESTION 1 & 2
    printf("      QUESTION 1\n");
    int tab[]={12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11};
    printf("Avant LOMUTO : ");
    affichage_tab(tab, 11);
    PARTITION_LOMUTO(tab, 0, 11);

    // QUESTION 3
    printf("\n      QUESTION 2\n");
    int tab_3[]={3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    printf("Avant LOMUTO : ");
    affichage_tab(tab_3, 11);
    printf("Valeur de retour = %d\n\n",PARTITION_LOMUTO(tab_3, 0, 11));

    // QUESTION 4
    printf("      QUESTION 4\n");
    int tab_4[]={12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11};
    printf("tri rapide G -> D\n");
    tri_rapide(tab_4, 0, 11);

    // QUESTION 5
    printf("\n      QUESTION 5\n");
    int tab_5[]={12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11};
    printf("tri rapide D -> G\n");
    tri_rapide_d_g(tab_5, 0, 11);

    // PARTIE B : HOARE 
    printf("\n\nPARTIE B \n\n");

    // QUESTION 1
    printf("      QUESTION 1\n");
    int tab_6[]={12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11};
    printf("Avant HOARE : ");
    affichage_tab(tab_6, 11);
    PARTITION_Hoare(tab_6, 0, 11);

    // QUESTION 2
    printf("\n      QUESTION 2\n");
    int tab_7[]={3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    printf("Valeur de retour = %d\n\n",PARTITION_Hoare(tab_7, 0, 11));

    // QUESTION 3
    printf("\n      QUESTION 3\n");
    int tab_8[]={12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11};
    tri_rapide_d_g(tab_8, 0, 11);
    return 0;
}