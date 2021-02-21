#include <stdio.h>
#include <stdlib.h>
// EX 1
    void ex1 (char c1, double d1)
    {
        double * dp = NULL;
        char * cp = NULL;
        cp = &c1;
        dp = &d1;
        c1 = 'a';
        d1 = 1;
        printf("\nle double est : %f | sont adresse est : %p\n", d1, dp);
        printf("le char est : %c | sont adresse est : %p\n\n", c1, cp);
    }

// EX6

    void swap (int *p1, int *p2)
    {
        int tmp = 0;
        
        printf("AVANT : var1 = %d| var 2 = %d| P1 = %p| P2 = %p\n", *p1, *p2, p1, p2);

        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;

        printf("PENDANT : var1 = %d| var 2 = %d| P1 = %p| P2 = %p\n\n", *p1, *p2, p1, p2);
    }

// EX9

    void loadTab(int size, int tab[])
    {
        printf("entrez les éléments de votre tableau\n");
	    for (int i = 0; i < size ; i++)
	    {
		    scanf("%d", &tab[i]);
	    }
    }

    void showTab(int size, int tab[])
    {
        printf("\nVoici votre tableau :");
	    for (int i = 0; i < size; i++)
        {
            printf("%d ",tab[i]);
        }
        printf("\n\n");
    }

    void getmean(int size, int tab[])
    {
	    double r=0;
	    for (int i = 0; i < size; i++)
	        {
                r += tab[i];
	        }
	    r/=size;
	    printf("La moyenne des éléments du tableau est :%.2f\n",r);
    }

    int main()
        {
            char char1; // EX1
            double double1; // EX1

            int var1 = 2; // EX6
            int var2 = 4; // EX6 

            ex1 (char1, double1); // EX1

            swap (&var1, &var2); // EX6

            int i = 0;
            printf("Saisir la taille du tableau : \n");
            scanf("%d", &i);

            int tab[i];
            loadTab ( i, tab);
            showTab ( i, tab);
            return 0;
        }