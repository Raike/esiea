#include <stdlib.h>
#include <stdio.h>

int PARTITION_LOMUTO(int tab[],int g,int d)
{
  int temp2=0;
  int temp=0;
  int x= tab[d]; //PIVOT
  int i=g-1;
  for(int j=g;j<=d-1;j++)
  {
    if (tab[j]<=x)
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

    printf("\n");
    affichage_tab(tab,11);
    printf("\n");

    return i+1;
}
int PARTITION_LOMUTO_D_G(int tab[],int g,int d)
{
  int temp2=0;
  int temp=0;
  int x=tab[d]; //PIVOT
  int i=d+1;
  for(int j=d;j>g;j--)
  {
    if (tab[j]>=x)
    {
      i--;
      temp=tab[i];
      tab[i]=tab[j];
      tab[j]=temp;
    }
  }
    temp2=tab[i-1];
    tab[i-1]=tab[d];
    tab[d]=temp2;

    printf("\n");
    affichage_tab(tab,11);
    printf("\n");

    return i+1;
}

void QUICK_SORT(int tab[],int g,int d)
{
  int m=0;
  if(g<d)
  {
    m=PARTITION_LOMUTO(tab,g,d);
    QUICK_SORT(tab,g,m-1);
    QUICK_SORT(tab,m+1,d);
  }
}

void affichage_tab(int tab[], int size)
{
    for (int i = 0; i <= size; i++)
    {
      printf("%d ",tab[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
 {
  int tab[]={12,23,6,8,13,9,8,5,20,3,7,11};
  int tab2[]={1,1,1,1,1,1,1,1,1,1,1,1};


  printf("%d \n", PARTITION_LOMUTO(tab,0,11));
  printf("%d \n", PARTITION_LOMUTO(tab2,0,11));
  printf("%d \n", PARTITION_LOMUTO_D_G(tab,0,11));
  printf("\t ~~Affichage QUICK_SORT:~~\n" );
  QUICK_SORT(tab,0,11);

  return 0;
 }