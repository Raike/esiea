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
	return 0;
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

int getMAX(int size,int iArray[])
{
	int reference=iArray[0];

	for (int i = 0; i < size; i++)
	{	
		if(iArray[i]>=reference)
		{
			reference=iArray[i];
		}
	}
	printf("Le MAXIMUM de ce tableau est : %d\n",reference);
	return 0;
}

int getMIN(int size, int iArray[])
{
	int reference=iArray[0];
	for (int i = 0; i < size; i++)
	{
		if (iArray[i]<=reference)
		{
			reference=iArray[i];
		}
	}
	printf("Le MINIMUM de ce tableau est : %d \n",reference);
	return 0;
}

int getMAXIndex(int size, int iArray[])
 { 
 	int Index=0;
 	int reference=iArray[0];
 	for (int i = 0; i < size; i++)
 	{
 		if (iArray[i]>=reference)
 		{
 			reference=iArray[i];
 			Index=i;
 		}
 	}
 	printf("Le max est à la case %d\n", Index);
	return 0;
 }

 int getMINIndex(int size, int iArray[])
 {
 	int Index=0;
 	int reference=iArray[0];
 	for (int i = 0; i < size; i++)
 	{
 		if (iArray[i]<=reference)
 		{
 			reference=iArray[i];
 			Index=i;
 		}
 	}
 	
 	printf("Le min est à la case %d\n", Index );
	return 0;
 }

 int getMode (int size, int iArray[])
{
   int Occurense[10] = {0};
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
    printf("|");

  	  for (int h = 0; h< size; h++)
	{
		printf("%d|",Occurense[h]);
	}
	printf("\n");
	return 0;
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
void bubbleShort(int size , int iArray[])
{
	int temp;
	int T=iArray[0];
	for (int i = 0; i < size; i++)
	{
		do
		{
			i++;
			temp=T;
			T=iArray[i];
			iArray[i]=temp;
		}
		while(T>iArray[i]);
	}
}

int main(int argc, char const *argv[])
{
	int i;
	int a,b;
	int iArray[i];
	printf("Saisir la taille du tableau\n");
	scanf("%d",&i);
	printf("\n");
	printf("Saisir %d valeurs pour remplir le tableau\n",i);
	loadArryay(i,iArray);
	showArray(i,iArray);
	getMean(i,iArray);
	getMAX(i,iArray);
	getMIN(i,iArray);
	getMAXIndex(i,iArray);
	getMINIndex(i,iArray);
	// printf("|0|1|2|3|4|5|6|7|8|9|\n");
	// getMode(i,iArray);	
	// bubbleShort(i,iArray);
	// showArray(i,iArray);

	return 0;
}