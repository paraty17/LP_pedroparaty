#ifndef INPUT_H
#define INPUT_H
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define clearConsole printf("\e[1;1H\e[2J");

#define STR_READ_ERROR "linha de texto invÃ¡lida\n"
#define INT_READ_ERROR "numero invÃ¡lido\n"
#define FLOAT_READ_ERROR "numero decimal invÃ¡lido\n"
#define CHAR_READ_ERROR "caracter invÃ¡lido\n"

//funÃ§Ãµes de leitura de tipos primitivos (int , char , string, float...);
 
bool LineFeedPresente(char *input);                 //Line Feed --> '\n' {consultar tabela ASCII}


void consoleClean();

void lerString(int max , char *input , char *msg);   

void lerInt(int max , int min , int *input , char *msg);
 
void lerFloat(float max , float min , float *input , char *msg);

void lerDouble(double max , double min , double *input , char *msg);
 
void lerChar(char *input , char *msg);

void lerChars(char a , char b , char *input , char *msg);

#endif

 

