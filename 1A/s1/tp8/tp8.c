#include <stdio.h>
#include <math.h>

void decimal_to_binary_horner (int decimal, char binary[])
{
    int var = 0;
    int size = 0;

    while(decimal !=0)
    {
        binary[size] = decimal %2;
        decimal = decimal /2;
        size ++;
    }

    printf("En base (2) (horner): ");
	for (int i = size-1; i >= 0; i--)
	{
		printf("%d ",binary[i]);
	}
	printf("\n");
}

void decimal_to_binary_power(int decimal,char binary[])
{
    int n=0;
    int i;
    int max;
    int p = pow(2,0);
    while(decimal >= p)
    {
        n++;
        p= pow(2,n);
    }
    p= pow(2,(n-1));
    n-=1; 
    max = n;
    binary[n]=1;
    printf("\nPuissance max = %d\n",p );
    printf("rang de la puissance %d\n",n );
    printf("Resultat de la puissance %d\n\n",p );
    ////////////////////////////////////////
    while (decimal!=0)
    {
        decimal-=p;    
        p = pow(2,0);
        n=0;
        while(decimal >= p)
        {
            n++;
            p= pow(2,n);
        }
    p= pow(2,(n-1));
    n-=1;
    binary[n]=1; 
    }

    printf("En base (2) (power): ");

    for (int j = max; j >=0 ; j--)
    {
        printf("%d ",binary[j]);
    }
    printf("\n");

}

int main ()
{
    char binary[33]={0};
    int decimal;
    printf("Entrez la valeur du decimal\n\nEn base (10) : ");
    scanf("%d", &decimal);

    decimal_to_binary_horner (decimal, binary);
    decimal_to_binary_power (decimal, binary);

    return 0;
}