#ifndef RESERVA_H
#define RESERVA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "input.h"
#include "encomendas.h"
#include "structs.h"

// Funções CRUD para Reservas
Reserva *criarReserva(int id_cliente, int id_espaco, const char *data, int duracao, EstadoReserva estado, int numero_participantes) {
    static int next_id = 1;
    Reserva *nova = (Reserva *)malloc(sizeof(Reserva));
    if (!nova) {
        perror("Erro ao alocar memória para Reserva");
        return NULL;
    }
    nova->id = next_id++;
    nova->id_cliente = id_cliente;
    nova->id_espaco = id_espaco;
    strncpy(nova->data, data, 11);
    nova->duracao = duracao;
    nova->estado = estado;
    nova->numero_participantes = numero_participantes;
    nova->equipamentos = NULL;
    nova->total_equipamentos = 0;
    return nova;
}

/**
 * @brief Lista todas as reservas.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Número total de reservas.
 */
void listarReservas(Reserva **reservas, int total) {
    printf("Lista de Reservas:\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d, Cliente ID: %d, Espaço ID: %d, Data: %s, Duração: %d, Estado: %d, Participantes: %d\n",
               reservas[i]->id, reservas[i]->id_cliente, reservas[i]->id_espaco, reservas[i]->data,
               reservas[i]->duracao, reservas[i]->estado, reservas[i]->numero_participantes);
    }
}

/**
 * @brief Atualiza o estado de uma reserva.
 * 
 * @param reserva Ponteiro para a reserva a ser atualizada.
 * @param novo_estado Novo estado da reserva.
 */
void atualizarReserva(Reserva *reserva, EstadoReserva novo_estado) {
    reserva->estado = novo_estado;
}

/**
 * @brief Remove uma reserva da lista de reservas.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Ponteiro para o número total de reservas.
 * @param id ID da reserva a ser removida.
 * 
 * A função busca a reserva pelo ID fornecido, libera os recursos associados (equipamentos e memória), 
 * ajusta a lista de reservas e decrementa o contador total de reservas. 
 * Se o ID não for encontrado, exibe uma mensagem de erro.
 */
void removerReserva(Reserva **reservas, int *total, int id) {
    for (int i = 0; i < *total; i++) {
        if (reservas[i]->id == id) {
            free(reservas[i]->equipamentos);
            free(reservas[i]);
            for (int j = i; j < *total - 1; j++) {
                reservas[j] = reservas[j + 1];
            }
            (*total)--;
            return;
        }
    }
    printf("Reserva com ID %d não encontrada.\n", id);
}

/**
 * @brief Lista todas as reservas com um estado específico.
 * 
 * @param reservas Vetor de ponteiros para reservas.
 * @param total Número total de reservas.
 * @param estado Estado das reservas a serem listadas.
 * 
 * A função percorre a lista de reservas e exibe apenas aquelas que correspondem ao estado fornecido.
 */
void listarReservasPorEstado(Reserva **reservas, int total, EstadoReserva estado) {
    printf("Reservas com estado %d:\n", estado);
    for (int i = 0; i < total; i++) {
        if (reservas[i]->estado == estado) {
            printf("ID: %d, Cliente ID: %d, Espaço ID: %d, Data: %s, Duração: %d, Participantes: %d\n",
                   reservas[i]->id, reservas[i]->id_cliente, reservas[i]->id_espaco, reservas[i]->data,
                   reservas[i]->duracao, reservas[i]->numero_participantes);
        }
    }
}

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
void calcularTaxaOcupacao(Reserva **reservas, int total, int total_espacos) {
    int ocupacao = 0;
    for (int i = 0; i < total; i++) {
        if (reservas[i]->estado == CONFIRMADA || reservas[i]->estado == FINALIZADA) {
            ocupacao++;
        }
    }
    printf("Taxa de ocupação: %.2f%%\n", (ocupacao / (float)total_espacos) * 100);
}

#endif // RESERVA_H