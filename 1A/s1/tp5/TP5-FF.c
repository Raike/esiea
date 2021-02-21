#include <stdio.h>

void getMean(int size, int iArray[])
{
	double r=0;
	for (int i = 0; i < size; i++)
	{
		r+=iArray[i];
	}
	r/=size;
	printf("La moyenne des éléments du tableau est :%.2f\n",r);
}

void showArray(int size, int iArray[])
{
	printf("\nVoici votre tableau :");
	for (int i = 0; i < size; i++)
	{
		printf("%d ",iArray[i]);
	}
	printf("\n\n");
}

void loadArryay(int size, int iArray[])
{
	for (int i = 0; i < size ; i++)
	{
		scanf("%d",&iArray[i]);
	}
}

void getMAX(int size,int iArray[])
{
	int reference=iArray[0];

	for (int i = 0; i < size; i++)
	{	
		if(iArray[i]>reference)
		{
			reference=iArray[i];
		}
	}

	printf("Le MAXIMUM de ce tableau est : %d\n",reference);
}

void getMIN(int size, int iArray[])
{
	int reference=iArray[0];
	for (int i = 0; i < size; i++)
	{
		if (iArray[i]<reference)
		{
			reference=iArray[i];
		}
	}
	printf("Le MINIMUM de ce tableau est : %d \n",reference);

}

void getMAXIndex(int size, int iArray[])
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
 	printf("Le max est à la case %d\n", Index);
}

 void getMINIndex(int size, int iArray[])
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
 	
 	printf("Le min est à la case %d\n", Index );
 }

 void getMode (int size, int iArray[])
{
   	int Occurense[10] = {0};
	int max = 0;
	for (int i = 0; i < size ; i++)
    {
    	for (int j = 0; j < 10 ; j++)
    	{
    		if (iArray[i]==j)
    		{
    			Occurense[j]++;
    		}
    	}
    }

  	for (int h = 0; h< size; h++)
	{
		if (Occurense[h] > max)
		{
			max = h;
		}
		printf("%d|",Occurense[h]);
	}
	printf("\nMode: %d", max);
}

void swap(int iArray[], int index1, int index2)
{
	int T;
	for (int i = 0; i < 10; i++)
	{
		T=iArray[index2];
		iArray[index2]=iArray[index1];
		iArray[index1]=T;
    }
}
void bubbleSort(int size , int iArray[])
{
	
}

int main(int argc, char const *argv[])
{
	int i = 0;
	printf("Saisir la taille du tableau: ");
	scanf("%d",&i);

	int iArray[i];
	
	printf("\nSaisir %d valeurs pour remplir le tableau\n",i);
	loadArryay(i,iArray);
	showArray(i,iArray);
	getMean(i,iArray);
	getMAX(i,iArray);
	getMIN(i,iArray);
	getMAXIndex(i,iArray);
	getMINIndex(i,iArray);
	
	printf("\n|0|1|2|3|4|5|6|7|8|9|\n");
	getMode(i,iArray);	
	
	printf("\n\n###BubbleSort\n");
	bubbleSort(i,iArray);
	showArray(i,iArray);

	return 0;
}