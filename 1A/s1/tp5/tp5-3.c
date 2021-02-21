#include <stdio.h>

double getMean( int size, int iArray[])
{
	double r=0;
	for (int i = 0; i < size; i++)
	{
		r+=iArray[i];
		
	}
	r/=size;
	printf("La moyenne des éléments du tableau est :%.2f\n",r);
	return r;
	}


void showArray (int size, int iArray[])
{
    int i;
    for (int j = 0; j < 3*size; j++)
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
	printf("\n");
}

void loadArryay(int size, int iArray[])
{
	for (int i = 0; i < size ; i++)
	{
		scanf("%d",&iArray[i]);
	}
}

int getMAX(int size,int iArray[])
{
	int reference=0;

	for (int i = 0; i < size; i++)
	{	
		if(iArray[i]>reference)
		{
			reference=iArray[i];
		}
	}
printf("Le MAXIMUM de ce tableau est : %d\n",reference);
}

int getMIN(int size, int iArray[])
{
	int reference=iArray[0];
	for (int i = 0; i < size; i++)
	{
		if (iArray[i]<reference)
		{
			reference=iArray[i];
		}
	}
	printf("Le MINIMUM de ce tableau est : %d \n",reference );

}

 int getMAXIndex(int size, int iArray[])
 {
 	int Index=0;
 	int reference=0;
 	for (int i = 0; i < size; i++)
 	{
 		if (iArray[i]>reference)
 		{
 			reference=iArray[i];
 			Index=i;
 		}
 	}
 	printf("Le max est à la case %d\n",Index+=1);
 }

 int getMINIndex(int size, int iArray[])
 {
 	int Index=0;
 	int reference=iArray[0];
 	for (int i = 0; i < size; i++)
 	{
 		if (iArray[i]<reference)
 		{
 			reference=iArray[i];
 			Index=i;
 		}
 	}
 	printf("Le min est à la case %d\n",Index+=1);
 }

int main(int argc, char const *argv[])
{
	int i;
	int iArray[i];
	printf("Saisir la taille du tableau\n");
	scanf("%d",&i);
	printf("Saisir %d valeurs pour remplir le tableau\n",i);
	loadArryay(i,iArray);
	showArray(i,iArray);
	getMean(i,iArray);
	getMAX(i,iArray);
	getMIN(i,iArray);
	getMAXIndex(i,iArray);
	getMINIndex(i,iArray);
	return 0;
}