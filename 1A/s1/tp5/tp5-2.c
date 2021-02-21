#include <stdio.h>

void loadArryay(int size, int iArray[])
{
    for (int i = 0; i < size ; i++)
    {
        scanf("%d",&iArray[i]);
    }
}

void showArray (int size, int iArray[])
{
    int i;
    for (int j = 0; j < size; j++)
    {
        printf("-");
    }
    printf("\n");
    for ( i = 0; i < size; i++)
    {
        printf("[%d]", iArray[i]);
    }
    printf("\n");
    for (int k = 0; k < 3*size; k++)
    {
        printf("-");
    }
    
}

void getMean (int size, int iArray[])
{
    int i;
    double result;
    for (i = 0; i < size; i++)
    {
        result += iArray[i] ;
    }
    result = result / size;
    printf("\nla moyenne est de = %lf\n",result);
}

int main()
{
    int size;
    printf("Entrez la valeur de la taille du tableau ");
    scanf("%d", &size);
    printf("\nEntrez %d valeur : \n", size);
    int iArray [size];
    loadArryay (size, iArray);
    showArray (size, iArray);
    getMean (size, iArray);
    return 0;
}
