#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PANIER 9

void affichage_map()
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("map.txt", "r"); // Ouverture du fichier map.txt
 
    if (fichier != NULL) // Boucle de lecture des caractères un à un
    {
        for(;;)
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            if (caractereActuel == EOF)
                break;
            printf("%c", caractereActuel); // On l'affiche
        }; // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
        fclose(fichier); // Fermeture du fichier map.txt
    }
}

void cursor_code() //Place le cursor au niveau du "saisir code :"
{
    printf("\033[%d;%dH",27,21);
    printf(" ");
}

void cursor_code_reset() //Rsset les éléments graphique au niveau du code
{
    printf("\033[%d;%dH",27,21);
    printf("     ");
}

void cursor_eror() //Place le cursor pour l'affichage des errors
{
    printf("\033[%d;%dH",29,6);
    printf(" ");
}

void cursor_eror_reset() // Reset les éléments graphique au niveau de l'affichage des errors
{
    printf("\033[%d;%dH",29,6);
    printf("                                  ");
}

void cursor_tt(double total_price) // Place le cursor au niveau du "Total a payer :"
{
    printf("\033[%d;%dH",27,90);
    printf("%.2f€\n",total_price);
}

void cursor_motant() // Place le cursor au niveau du "Saisir votre montant :"
{
    printf("\033[%d;%dH",28,96);
    printf(" ");
}

void cursor_rendu( double rendu) // Place le curosr au niveau du "Rendu :"
{
    printf("\033[%d;%dH",29,82);
    printf("%.2f€\n", rendu);
    for (int i = 0; i < 8; i++)
    {
        printf("\n");
    }
    
}

int get_rank(char code[]) // Return la valeur numérique du rang de l'éléments dans le tableau 
 {
    // Get the rank of article
    if(code[1]=='0')
        return code[2] - 48;
    else
        return (-38) + code[2];
}

double rendu_price (double total_price, double user_money) // Return le rendu de monais 
{
    double rendu = user_money - total_price;
    return rendu;
}

void croix_placement_f(int rank, int *p_x_tab, int *p_y_tab) // Place la croix la de l'ajout d'un éléments au panier (FRUITS)
{
    *p_x_tab=8;
    *p_y_tab=12;
    char croix[]="❌";

    // LIGNE //

    if (rank >= 5 && rank <= 9)
    {
        *p_y_tab+=4;
    }

    if (rank >= 10)
    {
        *p_y_tab+=8;
    }

    // COLONNE //

    if (rank == 1 || rank == 6 || rank == 11)
    {
        *p_x_tab+=5;
    }
    if (rank == 2 || rank == 7 || rank == 12)
    {
        *p_x_tab+=10;
    }
    if (rank == 3 || rank == 8 || rank == 13)
    {
        *p_x_tab+=15;
    }
    if (rank == 4 || rank == 9 || rank == 14)
    {
        *p_x_tab+=20;
    }
    
    printf("\033[%d;%dH",*p_y_tab,*p_x_tab);
    printf("%s",croix);
}

void croix_placement_l(int rank, int *p_x_tab, int *p_y_tab) // Place la croix la de l'ajout d'un éléments au panier (LEGUMES)
{
    *p_x_tab=42;
    *p_y_tab=12;
    char croix[]="❌";

    // LIGNE //

    if (rank >= 5 && rank <= 9)
    {
        *p_y_tab+=4;
    }

    if (rank >= 10)
    {
        *p_y_tab+=8;
    }

    // COLONNE //

    if (rank == 1 || rank == 6 || rank == 11)
    {
        *p_x_tab+=5;
    }
    if (rank == 2 || rank == 7 || rank == 12)
    {
        *p_x_tab+=10;
    }
    if (rank == 3 || rank == 8 || rank == 13)
    {
        *p_x_tab+=15;
    }
    if (rank == 4 || rank == 9 || rank == 14)
    {
        *p_x_tab+=20;
    }
    
    printf("\033[%d;%dH",*p_y_tab,*p_x_tab);
    printf("%s",croix);
}

void croix_placement_v(int rank, int *p_x_tab, int *p_y_tab) // Place la croix la de l'ajout d'un éléments au panier (VIANDES)
{
    *p_x_tab=76;
    *p_y_tab=12;
    char croix[]="❌";

    // LIGNE //

    if (rank >= 5 && rank <= 9)
    {
        *p_y_tab+=4;
    }

    if (rank >= 10)
    {
        *p_y_tab+=8;
    }

    // COLONNE //

    if (rank == 1 || rank == 6 || rank == 11)
    {
        *p_x_tab+=5;
    }
    if (rank == 2 || rank == 7 || rank == 12)
    {
        *p_x_tab+=10;
    }
    if (rank == 3 || rank == 8 || rank == 13)
    {
        *p_x_tab+=15;
    }
    if (rank == 4 || rank == 9 || rank == 14)
    {
        *p_x_tab+=20;
    }
    
    printf("\033[%d;%dH",*p_y_tab,*p_x_tab);
    printf("%s",croix);
}

void item_placement(int rank, int *p_h_cart, int *p_l_cart, int *p_x, int *p_y,char t) // Ajoute les éléments graphiquement dans le panier
{
    char fruits[]="🍓🍇🍏🍎🍐🍊🍋🍌🍉🍈🍒🍑🥥🍍🥝";
    char legume[]="🍅🍆🥦🌽🥒🌶🥕🥔🥑🍠🥜🍀🌱🌾🍄";
    char viande[]="🍗🍖🥩🍤🥓🍥🍣🍱🍛🍘🐠🐟🐡🦀🐙";

    char chaine[5];
    rank = rank * 4;
    switch(t) 
    {
        case'F':
        if(*p_h_cart<3)
        {
        
        if (*p_l_cart<3)
        {
            
            for (int i = 0; i < 4; i++)
            {
                chaine[i]=fruits[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            
            *p_l_cart +=1;
            *p_x+=3;
        }
        else
        {
           
            *p_h_cart += 1;
            *p_l_cart =0;
            *p_y-=2;
            *p_x = 51;

            for (int i = 0; i < 4; i++)
            {
                chaine[i]=fruits[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            *p_x+=3;
            *p_l_cart +=1;         
        }
        }
        break;

        case 'V':
        if(*p_h_cart<3)
        {
        
        if (*p_l_cart<3)
        {
            
            for (int i = 0; i < 4; i++)
            {
                chaine[i]=viande[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            
            *p_l_cart +=1;
            *p_x+=3;
        }
        else
        {
           
            *p_h_cart += 1;
            *p_l_cart =0;
            *p_y-=2;
            *p_x = 51;

            for (int i = 0; i < 4; i++)
            {
                chaine[i]=viande[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            *p_x+=3;
            *p_l_cart +=1;         
        }
        }
        break;
        
  case 'L':
        if(*p_h_cart<3)
        {
        
        if (*p_l_cart<3)
        {
            
            for (int i = 0; i < 4; i++)
            {
                chaine[i]=legume[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            
            *p_l_cart +=1;
            *p_x+=3;
        }
        else
        {
           
            *p_h_cart += 1;
            *p_l_cart =0;
            *p_y-=2;
            *p_x = 51;

            for (int i = 0; i < 4; i++)
            {
                chaine[i]=legume[rank];
                rank ++;
            }
            printf("\033[%d;%dH",*p_y,*p_x);
            printf("%s",chaine);
            *p_x+=3;
            *p_l_cart +=1;         
        }
        }
        break;
        
    }
    
    
}

int main()
{
    char t;
    char code[4];

    int rank = 0;
    int current_item_in_cart = 0;

    double current_price = 0;
    double total_price = 0;
    double user_money=0;

    int h_cart =0;
    int *p_h_cart= &h_cart;
    int l_cart =0;
    int *p_l_cart= &l_cart;

    int x =51;
    int *p_x=&x;
    int y =31;
    int *p_y=&y;

    int x_tab =8;
    int *p_x_tab=&x_tab;
    int y_tab =12;
    int *p_y_tab=&y_tab;

    // TAB OF FRUITS
    double tab_f[15] = {
        3.1, 4.1, 2.9, 2.2, 2.0,
        3.1, 1.0, 2.5, 3.8, 2.5,
        2.0, 1.6, 1.8, 3.7, 1.5
        };

    int tab_f_selected[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // TAB OR VEGETABLES
    double tab_l[15] = {
        2.4, 2.1, 1.9, 1.8, 1.7,
        2.1, 1.9, 1.9, 1.9, 3.1,
        2.1, 2.5, 2.8, 2.3, 2.7
        };

    int tab_l_selected[15] =  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // TAB OR MEET 
    double tab_v [15] = {
        3.2, 3.9, 4.3, 3.8, 4.9,
        5.0, 5.1, 2.3, 3.8, 4.0,
        2.1, 2.5, 2.8, 2.3, 2.7
        };

    int tab_v_selected[15] =  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    system("clear"); // clear le terminal 
    affichage_map(); // Affichage graphique 

    while (current_item_in_cart < MAX_PANIER)
    {
        cursor_code_reset(); // Reset les éléments graphique de "code"
        cursor_code(); // Place le cursor dans "Code"
        fgets(code, 5, stdin); // Récupere le code
        cursor_eror_reset(); // Reset les éléments graphique de "error"
        if(strncmp(code, "END", 3) == 0) 
        {
            break;
        }
        switch(code[0])
        {
            case 'F':
                // Appeler la fonction avec le tableau FRUITS
                t='F';
                rank = get_rank(code);
                if (tab_f_selected[rank] == 1) {
                    total_price += tab_f[rank];
                    cursor_tt(total_price);
                    tab_f_selected[rank] = 0;
                    current_item_in_cart++;
                    item_placement(rank, p_h_cart, p_l_cart, p_x, p_y,t);
                    croix_placement_f(rank, p_x_tab, p_y_tab);
                }
                else
                {
                    cursor_eror();
                    printf("Produit déjà séléctionné\n");
                    break;
                }
                break;
            case 'L':
                // Appeler la fonction avec le tableau LEGUMES
                t='L';
                rank = get_rank(code);
                if (tab_l_selected[rank] == 1) {
                    total_price += tab_l[rank];
                    cursor_tt(total_price);
                    tab_l_selected[rank] = 0;
                    current_item_in_cart++;
                    item_placement(rank,p_h_cart, p_l_cart, p_x, p_y,t);
                    croix_placement_l(rank, p_x_tab, p_y_tab);
                }
                else
                {
                    cursor_eror();
                    printf("Produit déjà séléctionné\n");
                    break;
                }
                break;
            case 'V':
                // Appeler la fonction avec le tableau VIANDES
                t='V';
                rank = get_rank(code);
                if (tab_v_selected[rank] == 1) {
                    total_price += tab_v[rank];
                    cursor_tt(total_price);
                    tab_v_selected[rank] = 0;
                    current_item_in_cart++;
                    item_placement(rank,p_h_cart, p_l_cart, p_x, p_y,t);
                    croix_placement_v(rank, p_x_tab, p_y_tab);
                }
                else
                {
                    cursor_eror();
                    printf("Produit déjà séléctionné\n");
                    break;
                }
                break;
            default:
                cursor_eror();
                printf("Erreur code non valide\n");
                break;
        }
    }

    cursor_tt(total_price);

    if (total_price != 0)
    {
        cursor_motant();
        scanf("%lf",&user_money);

        while (user_money < total_price)
        {
            cursor_eror();
            printf("Erreur montant insuffisant\n");
            cursor_motant();
            scanf("%lf",&user_money);
        }

        cursor_rendu(rendu_price(total_price, user_money));

        return 0;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
        printf("\n");
        }
        return 0;
    }
    
}
