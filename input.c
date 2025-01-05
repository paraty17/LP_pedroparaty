#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "input.h"

void limpaBuffer()
{
    int lixo;
    while( (lixo = getchar() ) != '\n' && lixo != '\0') {}
}

bool LineFeedPresente(char *input)                 //Line Feed --> '\n' {consultar tabela ASCII}
{
    bool linefeedPresente = false;
    for(int i = 0 ; i < strlen(input); i++)
    {
        if(input[i] == '\n')
        {
            linefeedPresente = true;
        }
    }
    
    return linefeedPresente;
}

void consoleClean(){
    system("Clear");
}

void lerString(int max , char *input , char *msg)   
{
    do
    {
        printf("%s" , msg);
        
        if(fgets(input , max, stdin) == NULL)
        {
            printf(STR_READ_ERROR);
            limpaBuffer();
             
        }
        else
        {    
            break;
        }
         
        
    }while(1);
    input[strcspn(input, "\n")] = '\0';
}

void lerInt(int max , int min , int *input , char *msg)
{
    printf("%s" , msg);
    while(scanf("%d" , input) != 1 || *input < min || *input > max)
    {
        clearConsole;
        printf(INT_READ_ERROR);
        limpaBuffer();
        printf("%s" , msg);
    }

    limpaBuffer();
}

void lerFloat(float max , float min , float *input , char *msg)
{
    printf("%s" , msg);
    while(scanf("%f" , input) != 1 || *input < min || *input > max)
    {
        clearConsole;
        printf(FLOAT_READ_ERROR);
        limpaBuffer();
        printf("%s" , msg);
    }
}

void lerDouble(double max , double min , double *input , char *msg)
{
    printf("%s" , msg);
    while(scanf("%lf" , input) != 1 || *input < min || *input > max)
    {
        clearConsole;
        printf(FLOAT_READ_ERROR);
        limpaBuffer();
        printf("%s" , msg);
    }
}

void lerChar(char *input , char *msg)
{
    printf("%s" , msg);
    while(scanf("%c", input) != 1)
    {
        printf(CHAR_READ_ERROR);
        printf("%s" , msg);
    }
}

void lerChars(char a , char b , char *input , char *msg)
{
    do
    {

        lerChar(input , msg);

        if(!(tolower(*input) == a || tolower(*input) == b))
        {
            puts(CHAR_READ_ERROR);
        }
    } while (!(tolower(*input) == a || tolower(*input) == b));
    
}