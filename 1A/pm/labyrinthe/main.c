#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affichage_map() // Affiche la map
{
    FILE* map = NULL;
    int caractere = 0;

    map = fopen("map.txt", "r"); 

    if (map != NULL) 
    {
        for(;;)
        {
            caractere = fgetc(map); 
            if (caractere == EOF)
                break;
            printf("%c", caractere); 
        }; 

        fclose(map); 
        printf("\n");
    }
}

void base_player(char player[])
{
    printf("\033[%d;%dH",30,9);
    printf("%s", player);
    
}

void move_update_reset(int x, int y)
{
    printf("\033[%d;%dH",y,x);
    printf("  ");
}

void move_update(int *x, int *y, char player[])
{
    printf("\033[%d;%dH",y,x);
    printf("%s", player);
    x = x;
    y = y;
}

void value_move(int x, int y, char player[])
{
    char temp;
    int value = 0;

        printf("\033[%d;%dH",32,1);
        printf("Déplacé vous avec zqsd : ");

        temp = getchar();

        printf("\033[%d;%dH",32,25);
        printf("    ");

        switch(temp) 
        {
        case 'z':
            move_update_reset(x,y);
            move_update(&x, &y-1, player);
            break;
        case 'q':
            move_update_reset(x,y);
            move_update(&x-2, &y, player);
            break;
        case 's':
            move_update_reset(x,y);
            move_update(&x, &y+1, player);
            break;
        case 'd':
            move_update_reset(x,y);
            move_update(&x+2, &y, player);
            break;
        }
    }

int main()
{
    char player[]="🔴";
    int x = 9;
    int y = 30;
    int * pt_x = &x;
    int * pt_y = &y;

    system("clear");

    affichage_map();

    base_player(player);

    value_move(*pt_x, *pt_y, player);

    printf("DEBUG INFO x = %d / y = %d",x,y);

    while (x == 64 && y == 30)
    {
        value_move(*pt_x, *pt_y, player);
    }
    return 0;
}

/*

void cursor_code() //Place le cursor au niveau du "saisir code :"

    printf("\033[%d;%dH",27,21);
    printf(" ");


*/