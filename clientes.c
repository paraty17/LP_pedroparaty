#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "clientes.h"
#include "input.h"
#include "reservas.h"
#include "structs.h"

/**
 * @brief Cria um novo cliente e adiciona à lista.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 * @param file Nome do arquivo para persistir os dados.
 * @return Índice do cliente criado ou -1 se o cliente já existir.
 */
int createCliente(Clientes *clientes){
    int clientID = lerInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE);

    if (searchClientes(*clientes, clientID) == -1){

        clientes->clientes[clientes->contador].clientID = clientID;

        lerString(clientes->clientes[clientes->contador].nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);

        clientes->clientes[clientes->contador].nif = lerInt(MIN_NUM_NIF, MAX_NUM_NIF, MSG_OBTER_NIF);
        
        clientes->clientes[clientes->contador].tel = lerInt(MSG_OBTER_TEL);
        
        clientes->clientes[clientes->contador].mail = lerString(MSG_OBTER_MAIL);
        
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        snprintf(clientes->clientes[clientes->contador].data_registo, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        
        clientes->clientes[clientes->contador].total_reservas = 0;

        return clientes->contador++;
    }
    return -1;
}

/**
 * @brief Gerencia a criação de vários clientes.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 * @param file Nome do arquivo para persistir os dados.
 * @param reservas Estrutura de reservas associada.
 */
void createClientes(Clientes *clientes, char *file, Reservas reservas){
    if (clientes->contador == clientes->tam) {
        expandClientes(Clientes);
    }
    if (reservas.counter > 0) {
        if (clientes->contador < clientes->tam) {
            if(createClientes(clientes, reservas) == -1){
                puts(ERRO_CLIENTE_EXISTE);
            } else {
                addClientesFX(*clientes, file);
            }
        } else {
            puts(ERRO_LISTA_CHEIA);
        }
    } else {
        puts(ERRO_RESERVA_INEXISTENTE);
    }
}

/**
 * @brief Lê os detalhes de um cliente específico.
 * 
 * @param cliente Estrutura do cliente a ser lida.
 */
void readClientes(Cliente cliente){
    printf("\nID de Cliente: %p", cliente.clientID);
    printf("\nNome: %p", cliente.nome[50]);
    printf("\nNIF: %p", cliente.nif);
    printf("\nTelefone: %p", cliente.tel);
    printf("\nE-Mail: %p", cliente.mail[30]); 
    printf("\nData de Registo: %p", cliente->data_registo);
}

/**
 * @brief Lista todos os clientes registrados.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 */
void listClientes(Clientes clientes){
    if (clientes.contador > 0){
        int i;
        for (i = 0; i < clientes.contador; i++){
            readClientes(clientes.clientes[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

/**
 * @brief Atualiza os dados de um cliente específico.
 * 
 * @param cliente Ponteiro para o cliente a ser atualizado.
 */
void updateClientes(Cliente *cliente){
    lerString((*cliente).nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);
    lerInt((*cliente).nif = lerInt MAX_TAM_TEL, MSG_OBTER_NIF);     
    lerInt((*cliente).tel = lerInt MAX_TAM_TEL, MSG_OBTER_NIF);  
    lerString((*cliente).mail, MAX_MAIL_LENGTH, MSG_OBTER_MAIL);
}

/**
 * @brief Atualiza os dados de um cliente em uma lista de clientes.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 */
void updateClientes(Clientes *clientes, char *file){
    int clientID = searchClientes(*clientes, lerInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));

    if(clientID != -1){
        updateClientes(&(*clientes).clientes[clientID]);
        
        updateClientesFX(*clientes, clientID, file);
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTENTE);
    }
}

/**
 * @brief Remove um cliente da lista.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 * @param file Nome do arquivo para persistir os dados.
 */
void deleteClientes(Clientes *clientes, char *file){
    int i, clientID = searchClientes(*clientes, lerInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));

    if(clientID != -1){
        for (i = clientID; i < clientes->contador -1; i++){
            clientes->clientes[i] = clientes->clientes[i + 1];
        }

        apagarDadosCliente(*clientes, file);

        clientes->contador--;
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTENTE);
    }
}

/**
 * @brief Apaga os dados de um cliente específico.
 * 
 * @param cliente Ponteiro para o cliente a ser apagado.
 */
void apagarDadosCliente(Cliente *cliente){
    cliente->clientID = 0;
    strcpy(cliente->nome, "");
    cliente->nif = 0;
    cliente->tel = 0;
    strcpy(cliente->mail, "");
}

/**
 * @brief Procura um cliente pelo ID.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 * @param clientID ID do cliente a ser buscado.
 * @return Índice do cliente encontrado ou -1 se não encontrado.
 */
int searchClientes(Clientes clientes, int clientID){
    int i;
    for (i = 0; i < clientes.contador; i++) {
        if (clientes.clientes[i].clientID == clientID) {
            return i; 
        }
    }
    return -1;
}

/**
 * @brief Exibe os detalhes de um cliente buscado pelo ID.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 */
void searchClientes(Clientes clientes){
    int clientID = searchClientes(clientes, lerInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));

    if(clientID != -1){
        readClientes(clientes.clientes[clientID]);
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTENTE);
    }
} 

/**
 * @brief Expande a capacidade da lista de clientes.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 */
void expandClientes(Clientes *clientes) {
    Cliente *temp = (Cliente*) realloc(clientes->clientes, sizeof (Clientes) * (clientes->tam * 2));
    if (temp != NULL) {
        clientes->tam *= 2;
        clientes->clientes = temp;
    }
}

/**
 * @brief Libera a memória alocada para a estrutura de clientes.
 * 
 * @param clientes Ponteiro para a estrutura de clientes.
 */
void freeClientes(Clientes *clientes) {
    free(clientes->clientes);
}

/**
 * @brief Gera estatísticas sobre os clientes.
 * 
 * @param clientes Vetor de ponteiros para clientes.
 * @param total Número total de clientes.
 */
void gerarEstatisticasClientes(Cliente **clientes, int total) {
    printf("Total de Clientes: %d\n", total);
    for (int i = 0; i < total; i++) {
        printf("Cliente ID: %d, Total de Reservas: %d\n", clientes->clientID, clientes[i]->total_reservas);
    }
}

/**
 * @brief Obtém o contador de clientes armazenado no arquivo.
 * 
 * @param file Nome do arquivo que contém os dados.
 * @return O valor do contador de clientes.
 */
int getCounterCompFX(char *file) {
    int counter = 0;
    FILE *fp = fopen(file, "rb");
    if (fp != NULL) {
        fread(&counter, sizeof (int), 1, fp);
        fclose(fp);
    }
    return counter;
}

/**
 * @brief Carrega clientes de um arquivo binário.
 * 
 * @param clientes Estrutura de clientes a ser preenchida.
 * @param file Nome do arquivo de onde os dados serão carregados.
 */
void loadClientes(Clientes clientes, char* file) {
    int success = 0;
    FILE *fp = fopen(file, "rb");

    if (fp != NULL) {
        fread(&clientes->contador, sizeof (int), 1, fp);

        if (clientes->contador> 0) {
            clientes->clientes = (Clientes*) malloc(clientes->contador* sizeof (Clientes));

            for (int i = 0; i < clientes->contador; i++) {
                fread(&clientes->clientes[i], sizeof (Clientes), 1, fp);

            }

            sizeof(Clientes) = clientes->contador;

            success = 1;
        }

        fclose(fp);
    }

    if (!success) {
        fp = fopen(file, "wb");
        if (fp != NULL) {
            clientes->clientes = (Clientes*) malloc(MAX_CLIENTES * sizeof (Clientes));
            clientes->contador = 0;
            sizeof(Clientes) = MAX_CLIENTES;

            fclose(fp);
            success = 1;
        }
    }
}

/**
 * @brief Atualiza o contador de clientes no arquivo.
 * 
 * @param counter Novo valor do contador.
 * @param file Nome do arquivo onde o contador será atualizado.
 */
void updateCounterCompFX(int counter, char *file) {
    FILE *fp = fopen(file, "r+b");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&counter, sizeof (int), 1, fp);
    fclose(fp);
}

/**
 * @brief Adiciona um cliente ao arquivo binário.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 * @param file Nome do arquivo onde os dados serão armazenados.
 */
void addClientesFX(Clientes clientes, char *file) {
    updateCounterCompFX(clientes.contador, file);

    FILE *fp = fopen(file, "ab");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&clientes.clientes[clientes.contador- 1], sizeof (Clientes), 1, fp);

    fclose(fp);
}

/**
 * @brief Atualiza os dados de um cliente específico no arquivo.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 * @param index Índice do cliente a ser atualizado.
 * @param file Nome do arquivo onde os dados serão atualizados.
 */
void updateClientesFX(Clientes clientes, int index, char *file) {
    FILE *fp = fopen(file, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fseek(fp, sizeof (int), SEEK_SET);

    fseek(fp, sizeof (Clientes) * index, SEEK_CUR);

    fwrite(&clientes.clientes[index], sizeof (Clientes), 1, fp);

    fclose(fp);
}

/**
 * @brief Remove todos os clientes do arquivo.
 * 
 * @param clientes Estrutura contendo todos os clientes.
 * @param file Nome do arquivo a ser atualizado.
 */
void deleteClientesFX(Clientes clientes, char* file) {
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&clientes.contador, sizeof (int), 1, fp);
    for (int i = 0; i < clientes.contador; i++) {
        fwrite(&clientes.clientes[i], sizeof (Clientes), 1, fp);
    }

    fclose(fp);
}

/**
 * @brief Pesquisa um cliente pelo NIF (Número de Identificação Fiscal) e apresenta as suas informações.
 * 
 * Esta função procura um cliente na lista de clientes com base no NIF introduzido pelo utilizador. 
 * Se o cliente for encontrado, as suas informações e reservas são exibidas, e o contador de pesquisas por NIF 
 * desse cliente é incrementado. Caso contrário, uma mensagem de erro será exibida.
 * 
 * @param clientes Estrutura contendo a lista de clientes.
 * @param reserva  Estrutura contendo as reservas associadas.
 */
void searchClientesNif(Clientes clientes, Reservas reserva) {
    int nif = searchClientesNif(clientes, lerInt(MIN_NUM_NIF, MAX_NUM_NIF, MSG_OBTER_NIF));

    if (nif != -1) {
        listClientes(clientes.clientes[nif], reserva);
        clientes.clientes[nif].countSearchNif++;

    } else {
        puts(ERRO_CLIENTE_NAO_EXISTENTE);
    }
}

/**
 * @brief Procura um cliente pelo NIF (Número de Identificação Fiscal) na lista de clientes.
 * 
 * Esta função percorre a lista de clientes para localizar um cliente com o NIF especificado.
 * Se o cliente for encontrado, o índice correspondente é devolvido. Caso contrário, devolve -1.
 * 
 * @param clientes Estrutura contendo a lista de clientes.
 * @param nif      O Número de Identificação Fiscal (NIF) do cliente a procurar.
 * @return O índice do cliente na lista, ou -1 caso o cliente não seja encontrado.
 */
int searchClientesNIF(Clientes clientes, int nif) {
    int i;
    for (i = 0; i < clientes.contador; i++) {
        if (clientes.clientes[i].nif == nif) {
            return i;
        }
    }
    return -1;
}

