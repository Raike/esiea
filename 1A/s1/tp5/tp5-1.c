#include <stdio.h>

void initArray (int size, int myArray[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        myArray[i] = i * i;
    }
}

void showArray (int size, int myArray[])
{
    int j;
    for ( j = 0; j < size; j++)
    {
        myArray[j] = j * j;
        printf("%d ", j);
    }
    
}

int main()
{
    int iArray[10] = {0};
    initArray (10, iArray);
    showArray (10, iArray);
    return 0;
}
