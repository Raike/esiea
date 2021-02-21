#include <stdio.h>
#include <string.h>

/*void get_code (float tab[], char code [])
{
    for (int i = 0; tab[i] != code []; i++)
    {
        
    }
    
}

*/

int main()
{
    float tab [3][3] = {00,1.1,01,2.2,02,3.3};
    printf("code = %f / prix=%f", tab[0][0], tab[0][1]);
    //char code [3] = {01};
    return 0;
}