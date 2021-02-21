#include <stdio.h>
#include <stdlib.h>

void scan(int xSize_tab, int ySize_tab, int Xspawn,int Yspawn, int force, int map_early[xSize_tab][ySize_tab], int map_final[xSize_tab][ySize_tab])
{
    // printf("DEBUG INFO : %d %d %d %d\n\n",Xspawn, Yspawn, force, map_early[4][4]);

    if (map_early[Xspawn - 1][Yspawn] <= force && map_early[Xspawn - 1][Yspawn] != -1 && map_early[Xspawn - 1][Yspawn] != -2 && map_final[Xspawn - 1][Yspawn] == 0)
    {
        map_final[Xspawn - 1][Yspawn] = -1;
        scan(xSize_tab, ySize_tab, Xspawn - 1, Yspawn, force, map_early, map_final);
    }

    if (map_early[Xspawn - 1][Yspawn + 1] <= force && map_early[Xspawn - 1][Yspawn + 1] != -1 && map_early[Xspawn - 1][Yspawn + 1] != -2 && map_final[Xspawn - 1][Yspawn + 1] == 0)
    {
        map_final[Xspawn - 1][Yspawn + 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn - 1, Yspawn + 1, force, map_early, map_final);
    }

    if (map_early[Xspawn][Yspawn + 1] <= force && map_early[Xspawn][Yspawn + 1] != -1 && map_early[Xspawn][Yspawn + 1] != -2 && map_final[Xspawn][Yspawn + 1] == 0)
    {
        map_final[Xspawn][Yspawn + 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn, Yspawn + 1, force, map_early, map_final);
    }

    if (map_early[Xspawn + 1][Yspawn + 1] <= force && map_early[Xspawn + 1][Yspawn + 1] != -1 && map_early[Xspawn + 1][Yspawn + 1] != -2 && map_final[Xspawn + 1][Yspawn + 1] == 0)
    {
        map_final[Xspawn + 1][Yspawn + 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn + 1, Yspawn + 1, force, map_early, map_final);
    }

    if (map_early[Xspawn + 1][Yspawn] <= force && map_early[Xspawn + 1][Yspawn] != -1 && map_early[Xspawn + 1][Yspawn] != -2 && map_final[Xspawn + 1][Yspawn] == 0)
    {
        map_final[Xspawn + 1][Yspawn] = -1;
        scan(xSize_tab, ySize_tab, Xspawn + 1, Yspawn, force, map_early, map_final);
    }

    if (map_early[Xspawn + 1][Yspawn - 1] <= force && map_early[Xspawn + 1][Yspawn - 1] != -1 && map_early[Xspawn + 1][Yspawn - 1] != -2 && map_final[Xspawn + 1][Yspawn - 1] == 0)
    {
        map_final[Xspawn + 1][Yspawn - 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn + 1, Yspawn - 1, force, map_early, map_final);
    }

    if (map_early[Xspawn][Yspawn - 1] <= force && map_early[Xspawn][Yspawn - 1] != -1 && map_early[Xspawn][Yspawn - 1] != -2 && map_final[Xspawn][Yspawn - 1] == 0)
    {
        map_final[Xspawn][Yspawn - 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn, Yspawn - 1, force, map_early, map_final);
    }

    if (map_early[Xspawn- 1][Yspawn - 1] <= force && map_early[Xspawn - 1][Yspawn - 1] != -1 && map_early[Xspawn - 1][Yspawn - 1] != -2 && map_final[Xspawn - 1][Yspawn - 1] == 0)
    {
        map_final[Xspawn - 1][Yspawn - 1] = -1;
        scan(xSize_tab, ySize_tab, Xspawn - 1, Yspawn - 1, force, map_early, map_final);
    }
}

int main()
{
    system("clear");
    
    int xSize_tab = 0;
    int ySize_tab = 0;

    int Ysize_temp = 0;
    int Xsize_temp = 0;

    int Xspawn = 0;
    int Yspawn = 0;

    int force = 0;

    // RECUPERATION DES INFORMATION

    FILE* fichier = NULL;

    fichier = fopen("virus.txt", "r+");

        // Récupération dim tab 2x2

        xSize_tab = fgetc(fichier) - 48;
        ySize_tab = fgetc(fichier) - 48;

        int map_early[xSize_tab][ySize_tab]; // X nombre de Ligne | Y nombre de colone 

        // printf("DEBUG Taille du tab 2x2 : %d | %d\n\n", xSize_tab, ySize_tab);
        // printf("DEBUG Code = ");

        while (Xsize_temp < xSize_tab)
        {
            while (Ysize_temp < ySize_tab)
            {
                map_early[Xsize_temp][Ysize_temp] = fgetc(fichier) - 48;
                // printf("%d",map_early[Xsize_temp][Ysize_temp]);
                Ysize_temp++;
            }
            Ysize_temp = 0;
            Xsize_temp ++;
        }

        Xspawn = fgetc(fichier) - 48;

        Yspawn = fgetc(fichier) - 48;

        force = fgetc(fichier) - 48;

        // printf("\n\nDEBUG Spawn = (%d;%d)\n", Xspawn, Yspawn);
        // printf("\nDEBUG Force = %d\n", force);

    fclose(fichier);

    // TRAITEMENT DES INFORMATION 

    int map_final[xSize_tab][ySize_tab]; 

    Ysize_temp = 0; 
    Xsize_temp = 0;

    // printf("\nDEBUG Code = ");

    while (Xsize_temp < xSize_tab)
        {
            while (Ysize_temp < ySize_tab)
            {
                map_final[Xsize_temp][Ysize_temp] = 0;
                // printf("%d",map_final[Xsize_temp][Ysize_temp]);
                Ysize_temp++;
            }
            Ysize_temp = 0;
            Xsize_temp ++;
        }

    // AFFICHAGE MAP INITIAL 

    printf("DEBUG Map_Initial = \n\n");

    for(int i=0; i<xSize_tab; i++)
    {
        for(int j=0; j<ySize_tab; j++)
        {
            printf(" %d ", map_early[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // SET SPAWN 

    map_final[Xspawn][Yspawn] = -2;

    // RECURSIVITE

    int * Xspawn_pt = &Xspawn;
    int * Yspawn_pt = &Yspawn;
    int * force_pt = &force;
    int * xSize_tab_pt = &xSize_tab;
    int * ySize_tab_pt = &ySize_tab;

    scan(*xSize_tab_pt, *ySize_tab_pt, *Xspawn_pt, *Yspawn_pt, *force_pt, map_early, map_final);

    // AFFICHAGE FINAL MAP 

    printf("DEBUG Map_Final = \n\n");

    for(int i=0; i<xSize_tab; i++)
    {
        for(int j=0; j<ySize_tab; j++)
        {
            if (map_final[i][j] == -1 || map_final[i][j] == -2)
            {
                printf(" ");
            }
            else
            {
                printf(" ");
                printf(" ");
            }
            
            printf("%d", map_final[i][j]);
 
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}