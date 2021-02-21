#include <stdio.h>

int main() 
{
    printf (" SVP Entrer l operateur : \n 1 => addition \n 2 => soustraction \n 3 => multiplication \n 4 => division \n 5 => modulo \n ");
    int Menu; 
    scanf("%d", &Menu);
    float var1;  // déclaration des varriables
    float var2;
    int var3;
    int var4;

    if (Menu == 1 || Menu == 2 || Menu == 3 || Menu == 4 || Menu == 5) // Vérification que le chiffre saisie est en accord avec le menu
{
    if (Menu ==1 ) //Addition
    {
        printf("Entre les valeur de deux chiffres \n");
        scanf ("%f %f", &var1, &var2);
        var1 += var2;
        printf("le resultat est :");
        printf ("%f\n", var1);
    }

    if (Menu ==2 ) //Soustraction
    {
        printf("Entre les valeur de deux chiffres \n");
        scanf ("%f %f", &var1, &var2);
        var1 -= var2;
        printf("le resultat est :");
        printf ("%f\n", var1);
    }

    if (Menu ==3 ) //Multiplication
    {
        printf("Entre les valeur de deux chiffres \n");
        scanf ("%f %f", &var1, &var2);
        var1 *= var2;
        printf("le resultat est :");
        printf ("%f\n", var1);
    }

    if (Menu ==4 ) //Division
    {
        printf("Entre les valeur de deux chiffres \n");
        scanf ("%f %f", &var1, &var2);
        var1 /= var2;
        printf("le resultat est :");
        printf ("%f\n", var1);
    }

    if (Menu ==5 ) //Modulo
    {
        printf("Entre les valeur de deux chiffres \n");
        scanf ("%d %d", &var3, &var4);
        var3 %= var4;
        printf("le resultat est :");
        printf ("%lf\n", var1);
    }
}
else
{
    printf("EROR : Rentre un nombre entre 1 et 5\n"); // else, affiche une ereur si le nombre saisie de rentre pas dans le menu d
}

}