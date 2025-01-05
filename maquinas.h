    #ifndef MAQUINAS_H
    #define MAQUINAS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

     
    //Maquinas

    #define NONEXISTENT_ID_ERRORMSG "ID não existe!\n"
    #define ALREADYEXISTENT_ID_ERRORMSG "ID já existe!\n"
    #define MIN_ID_MQ 1
    #define MAX_ID_MQ 999
    #define MSG_ID_MQ "ID da Maquina: "

    #define MAX_NOME_MQ 30
    #define MSG_NOME_MQ "Nome da Maquina: "


    #define MAX_TIPO 9
    #define MIN_TIPO 0
    #define MSG_TIPO "Tipo de Máquina:\n   0.Corte\n   1.Injeção\n   2.Solda\n   3.Fresagem\n   4.Lixamento\n   5.Perfuração\n   6.CNC\n   7.Torneamento\n   8.Impressão\n   9.Embalagem\n"
    
    #define MAX_MAQUINAS 30
    #define MIN_MAQUINAS 1

    #define MACHINES_SCT_FULL_ERRMSG "Erro! Lista de Máquinas cheia!\n"
    #define MACHINES_SCT_EMPTY_ERRMSG "Erro! Lista de Máquinas vazia!\n" 

    //enums e structs
    typedef enum
    {
        TIPO_NAOATRIBUIDO = -1,
        TIPO_CORTE,
        TIPO_INJECAO,
        TIPO_SOLDA,
        TIPO_FRESAGEM,
        TIPO_LIXAMENTO,
        TIPO_PERFURACAO,
        TIPO_CNC,
        TIPO_TORNEAMENTO,
        TIPO_IMPRESSAO,
        TIPO_EMBALAGEM
    } Tipo;


    typedef struct 
    {
        int id_Mq;
        char nome_Mq[MAX_NOME_MQ];
        Tipo t_Mq;

    }Maquina;

    typedef struct
    {
        Maquina array[MAX_MAQUINAS];
        int contador;
    }Maquinas;

    //funcoes

    void lerID_Mq(int *ID_Mq);
    void lerNome_Mq(char* nome_Mq);
    void lerTipo_Mq(Tipo* tipo_Mq);

    int Id_MqToInt(Maquinas maquinas , int id);
    bool Id_Mq_Existe(Maquinas maquinas , int id);
    void trocaMaquinas(Maquina *a , Maquina *b);
    
    char* devolveTipo(Tipo t);
    
    void ordenarporId_Mq(Maquinas *maquinas);
    void imprimirporTipo(Maquinas maquinas);
    void imprimirsemserporTipo(Maquinas maquinas);
    
    void listarMaquinas(Maquinas maquina);
    void createMaquina(Maquinas *maquinas);
    void readMaquina(Maquinas maquinas);
    void updateMaquina(Maquinas *maquina);
    void deleteMaquina(Maquinas *maquina);
    

    void CRUD_Maquinas(Maquinas maquinas);
    
    #endif