#include <stdio.h>

void loadArryay(int size, int iArray[])
{
	for (int i = 0; i < size ; i++)
	{
		scanf("%d",&iArray[i]);
	}
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

int main()
{
	int i;
	int iArray[i];
	printf("Saisir la taille du tableau\n");
	scanf("%d",&i);
	printf("\n");
	printf("Saisir %d valeurs pour remplir le tableau\n",i);
	loadArryay(i,iArray);
	showArray(i,iArray);
	return 0;
}