#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loadWord (char word[])
{
    printf("Please enter a word (50char max) :\n" );
    if (scanf("%s" , word) != 1) 
    {   
        printf("Input error\n"); 
        exit(-1); 
    }
    printf("You have entered the word : %s\n" , word);
}

void loadSentence (char sentence[])
{
    printf("Please enter a sentence (50char max) :\n" );
    if (scanf("\n%30[^\n]" , sentence) != 1) 
    {   
        printf("Input error\n"); 
        exit(-1); 
    }
    printf("You have entered the sentence : %s\n", sentence);
}

void toUpperCase(char sentence[])
{
    int i=0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            sentence[i] += + 'A' - 'a';
        }
            i ++ ; 
        
    }
    printf("\nThe new sentence is (Major): %s\n", sentence);
}   

void toLowerCase(char sentence[])
{
    int i=0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z')
        {        
            sentence[i] += - 'A' + 'a';
        }
        i ++ ;
    }
    printf("\nThe new sentence is (Minor): %s\n", sentence);
}

void mirror ( char sentence[])
{
    int len;
    char tmp=0;
    len = strlen(sentence)-1;
    printf("\n");
    int k=len;
    printf("Mirror:");
    for (int i = 0; i < len/2; i++)
    {
              tmp = sentence[i];                                                          
              sentence[i] = sentence[k];                                                       
              sentence[k] = tmp;
              k--;
    }

    printf(" %s\n",sentence);
}

int main()
{
    char word [51];
    char sentence [51];
    loadWord (word);
    printf("\n");
    loadSentence (sentence);
    toUpperCase (sentence);
    toLowerCase (sentence);
    mirror(sentence);
    return 0;
}
