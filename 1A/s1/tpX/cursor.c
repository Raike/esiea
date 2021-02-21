#include<stdio.h> 
#include<string.h>

void cursor_position(int Ypos, int Xpos)
{
    printf("\033[%d;%dH",Ypos+1,Xpos+1);
}

int main()
{
    system("clear");
    cursor_position(20,50);
    printf("salut");
    return 0;
}