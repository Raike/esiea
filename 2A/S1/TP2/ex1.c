#include <stdio.h>
#include <stdlib.h>

void dureevol(int hd, int md, int sd, int ha, int ma, int sa, int *h, int *m, int *s)
{
    if (sa - sd >= 0)
    {
        *s = sa - sd;
    }
    else
    {
        *s = 60 +(sa - sd);
        *m = -1;
    }

    if (ma - md >= 0)
    {
        *m += ma - md;
    }
    else
    {
        *m += 60 +(ma - md);
        *h = -1;
    }

    *h += ha - hd;
}

int main()
{
    int hd = 0;
    int md = 0;
    int sd = 0;

    int ha = 0;
    int ma = 0;
    int sa = 0;

    int h = 0;
    int m = 0;
    int s = 0;


    printf("Donnez l'heur de départ du vol : ");
    scanf("%d %d %d", &hd, &md, &sd);
    //printf("    DEBUG Heure de départ = %d.%d.%d\n", hd, md, sd);
    printf("Donnez l'heur d'arrivé du vol : ");
    //scanf("%d %d %d", &ha, &ma, &sa);
    printf("    DEBUG Heure de départ = %d.%d.%d\n", ha, ma, sa);


    dureevol(hd,md,sd,ha,ma,sa,&h,&m,&s);
    printf("le vol dure : %dH%dM%dS\n", h,m,s);
    return 0;
}