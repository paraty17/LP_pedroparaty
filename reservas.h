#ifndef RESERVA_H
#define RESERVA_H

#include "clientes.h"

/**
 * @brief Cria uma nova reserva.
 * 
 * @param id_cliente ID do cliente associado.
 * @param id_espaco ID do espaço associado.
 * @param data Data da reserva.
 * @param duracao Duração da reserva em horas.
 * @param estado Estado inicial da reserva.
 * @param numero_participantes Número de participantes na reserva.
 * @return Ponteiro para a reserva criada ou NULL em caso de erro.
 */
Reserva *criarReserva(int id_cliente, int id_espaco, const char *data, int duracao, EstadoReserva estado, int numero_participantes);

/**
 * @brief Lista todas as reservas.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Número total de reservas.
 */
void listarReservas(Reserva **reservas, int total);

/**
 * @brief Atualiza o estado de uma reserva.
 * 
 * @param reserva Ponteiro para a reserva a ser atualizada.
 * @param novo_estado Novo estado da reserva.
 */
void atualizarReserva(Reserva *reserva, EstadoReserva novo_estado);

/**
 * @brief Remove uma reserva da lista.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Ponteiro para o número total de reservas.
 * @param id ID da reserva a ser removida.
 * 
 * A função busca a reserva pelo ID fornecido, libera os recursos associados (equipamentos e memória), 
 * ajusta a lista de reservas e decrementa o contador total de reservas. 
 * Se o ID não for encontrado, exibe uma mensagem de erro.
 */
void removerReserva(Reserva **reservas, int *total, int id);

/**
 * @brief Lista todas as reservas com um estado específico.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Número total de reservas.
 * @param estado Estado das reservas a serem listadas.
 * 
 * A função percorre a lista de reservas e exibe apenas aquelas que correspondem ao estado fornecido.
 */
void listarReservasPorEstado(Reserva **reservas, int total, EstadoReserva estado);

/**
 * @brief Calcula a taxa de ocupação dos espaços com base nas reservas confirmadas ou finalizadas.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Número total de reservas.
 * @param total_espacos Número total de espaços disponíveis.
 * 
 * A função calcula a taxa de ocupação com base nas reservas que estão em estado CONFIRMADA ou FINALIZADA
 * e exibe o resultado como uma porcentagem.
 */
void calcularTaxaOcupacao(Reserva **reservas, int total, int total_espacos);


#endif