#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int DETERM_CLE_ISBN(unsigned int TAB[12])
{
    return (10 -((TAB[0] + TAB[2] + TAB[4] + TAB[6] + TAB[8] + TAB[10]) + 3 * (TAB[1] + TAB[3] + TAB[5] + TAB[7] + TAB[9] + TAB[11]))%10) % 10;
}

unsigned int DETERM_CLE_ISEE(unsigned int TAB[15])
{
    return (TAB[0]*100000000000 + TAB[1]*10000000000 + TAB[2]*1000000000 + TAB[3]*100000000 + TAB[4]*10000000 + TAB[5]*1000000 + TAB[6]*100000 +
            TAB[7]*10000 + TAB[8]*1000 + TAB[9]*100 + TAB[10]*10 + TAB[11]) %97;
}

int main(int argc, char ** argv)
{
    printf("indiqué votre code ISBN : \n");
    int unsigned TAB[13];
    int unsigned TAB2[15];

    for (int i = 0; i < 13; i++)
    {
        scanf("%d", &TAB[i]);
    }
    if(DETERM_CLE_ISBN(TAB) == TAB[12])
    {
        printf("code correcte : ");
        for (int i = 0; i < 13; i++)
        {
            printf("%d ", TAB[i]);
        }
        printf("\n");
    }
    else
    {
        printf("code incorrecte\n");
        for (int i = 0; i < 13; i++)
        {
            printf("%d ", TAB[i]);
        }
        printf("\n");
    }

    printf("indiqué votre code INSEE : \n");
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &TAB[i]);
    }

    if(97 - DETERM_CLE_ISEE(TAB2) == TAB[12]*10 + TAB[13])
    {
        printf("code correcte : ");
        for (int i = 0; i < 15; i++)
        {
            printf("%d ", TAB[i]);
        }
        printf("\n");
    }
    else
    {
        printf("code incorrecte\n");
        for (int i = 0; i < 15; i++)
        {
            printf("%d ", TAB[i]);
        }
        printf("\n");
    }

    return 0;
}