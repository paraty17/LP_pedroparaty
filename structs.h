#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_CLIENTES 100 // provisorio

#define MIN_NUM_CLIENTE 0
#define MAX_NUM_CLIENTE 1000
#define MSG_OBTER_NUM_CLIENTE "Insira um número de cliente [0-1000]: "
#define MAX_NOME_CLIENTE 50
#define MSG_OBTER_NOME "Insira o nome do cliente: "
#define MSG_OBTER_NIF "Insira o seu NIF: "
#define MIN_NUM_NIF 1000000000
#define MAX_NUM_NIF 9999999999
#define MSG_OBTER_TEL "Insira o seu contacto telefónico: "
#define MSG_OBTER_MAIL "Insira o seu e-mail: "
#define MAX_MAIL_LENGTH 65
#define MAX_TAM_TEL 10

#define ERRO_CLIENTE_NAO_EXISTENTE "O cliente não existe na lista."
#define ERRO_LISTA_VAZIA "A lista de clientes está vazia."
#define ERRO_LISTA_CHEIA "A lista de clientes está cheia."
#define ERRO_CLIENTE_EXISTE "O número de cliente já se encontra atribuído."
#define ERRO_RESERVA_INEXISTENTE "Não há registo de reserva."
#define ERRO_NUM_INVALIDO "Insira um número válido."

#define MAX_TIPO_EQUIPAMENTO 50

/**
 * @brief Enumeração para os estados de uma reserva.
 */
typedef enum { Pendente, Confirmada, Finalizada, Cancelada } EstadoReserva;

typedef enum { Colunas , Computadores, Projetores, Câmaras, Palco } TipoEquipamento;

typedef enum { Auditório , SalaDeReunião, ArLivre, Pavilhão } TipoEspaco;

/**
 * @brief Estrutura que representa um cliente.
 */
typedef struct {
    int clientID;
    char nome[sizeof(nome)];
    int tel[MAX_TAM_TEL];
    int nif[MAX_TAM_TEL];
    char mail[MAX_MAIL_LENGTH];
    char data_registo[11];
    int total_reservas;
    
    int countSearchID;
    int countSearchNif;
} Cliente;

typedef struct {
    int contador, tam;
    Cliente *clientes;
} Clientes;

/**
 * @brief Estrutura que representa um equipamento reservado.
 */
typedef struct {
    int equipamentoID;
    char nome[sizeof(nome)];
    TipoEquipamento equipamento; 
    EstadoReserva estado; 
    int totalUsos;
} Equipamento;

typedef struct {
    int contador;
    Equipamento *equipamentos;
} Equipamentos;

/** 
 * @brief Estrutura que representa uma reserva.
 */
typedef struct {
    int reservaID; ///< Identificador único da reserva.
    int id_cliente; ///< ID do cliente associado à reserva.
    int id_espaco; ///< ID do espaço associado à reserva.
    char data[11]; ///< Data da reserva (formato DD-MM-YYYY).
    int duracao; ///< Duração da reserva em horas.
    EstadoReserva estado; ///< Estado atual da reserva.
    int numero_participantes; ///< Número de participantes na reserva.
    TipoEquipamento *equipamentos; ///< Equipamentos reservados.
    int total_equipamentos; ///< Total de equipamentos reservados.
} Reserva;

typedef struct {
    int counter;
    Reserva *reserva;
} Reservas;

typedef struct {
    int espacoID;
    char nome[sizeof(nome)];
    int capacidade;
    TipoEspaco espaco;
} Espaco;

typedef struct {
    int contador;
    Espaco *espaco;
} Espacos;



#endif /* STRUCTS_H */

