    #ifndef PRODUTOS_H
    #define PRODUTOS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "maquinas.h"    
     


    ////Produtos

    #define NONEXISTENT_ID_ERRORMSG "ID não existe!\n"
    #define ALREADYEXISTENT_ID_ERRORMSG "ID já existe!\n"
    #define MIN_ID 1
    #define MAX_ID 999
    #define MSG_ID "ID do Produto: "

    #define MAX_NOME 30
    #define MSG_NOME "Nome do Produto: "

    #define MIN_CATEGORIA 0
    #define MAX_CATEGORIA 6
    #define MSG_CATEGORIA "Categoria do produto:\n   0.Sensor\n   1.Cabo\n   2.Placa Protótipo\n   3.Componente\n   4.Display\n   5.Motor\n   6.Shield\n"

    #define MAX_PROCURA 2
    #define MIN_PROCURA 0
    #define MSG_PROCURA "Procura:\n   0.Pequena\n   1.Media\n   2.Alta\n"

    #define PRODUCTS_SCT_FULL_ERRMSG "Erro! Lista de produtos cheia!\n"
    #define PRODUCTS_SCT_EMPTY_ERRMSG "Erro! Lista de produtos vazia!\n" 

    #define MIN_PROCESSOS_ERRORMSG "Numero de processos insuficiente|\n"
    #define MAX_PROCESSOS_ERRORMSG  "Maximo de processos atingido!\n"



    //<enums>
    typedef enum
    {
        CATEGOIRIA_NAOATRIBUIDO = -1,
        CATEGORIA_SENSOR,
        CATEGORIA_CABO ,
        CATEGORIA_PLACA_PROTOTIPO ,
        CATEGORIA_COMPONENTE ,
        CATEGORIA_DISPLAY ,
        CATEGORIA_MOTOR ,
        CATEGORIA_SHIELD

    } Categoria;

    typedef enum 
    {
        PROCURA_NAOATRIBUIDO = -1,
        PROCURA_BAIXA ,
        PROCURA_MEDIA ,
        PROCURA_ALTA
    } Procura;
    //</enums>


    //<structs>
    typedef struct 
    {
        int idMaq;
        int tempo;
    } Processo;

    typedef struct 
    {
        Processo array[5];
        int contador;
    }Processos;


    typedef struct
    {
        int ID;
        char nome[MAX_NOME];
        Categoria c;
        Procura p;
        Processos Processos;

    } Produto;

    typedef struct
    {
        Produto array[100];
        int contador;
    }Produtos;


    //</structs>

    //<funções>
    void lerID(int *ID);
    void lerNome(char* nome);
    void lerCategoria(Categoria *c);
    void lerProcura(Procura *p);
    void lerTempo(int *tempo);
    void lerProcessos(Processos *processos , Maquinas maquinas);
        
    int IDtoInt(Produtos produtos , int ID);        //retorna o indice da array (onde o produto se encontra na array) usando o id do produto
    bool ID_Existe (Produtos *produtos , int ID);
    void trocaProdutos(Produto *a , Produto *b);
 
    char* devolveCategoria(Categoria c);
    char* devolveProcura(Procura p);

    void ordenarporID(Produtos *produtos);
    void ordenarporOrdemAlfabetica(Produtos *produtos);
    void ordenarporProcura(Produtos *produtos);
    void imprimirporCategoria(Produtos produtos);

    void createProduto(Produtos *produtos , Maquinas maquinas);
    void readProduto(Produtos produtos);
    void updateProduto(Produtos *produtos);
    void deleteProduto(Produtos *produtos);
    void listarProdutos(Produtos produtos);

    void CRUD_Produtos(Produtos produtos , Maquinas maquinas);
    //</funções>
    #endif

    

