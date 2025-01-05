#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "input.h"
#include "clientes.h"
#include "reservas.h"
#include "menus.h"
#include "logs.h"

#define LOGS_FILE             "logs.txt"
#define CLIENTES_DB_FILE      "clientes.bin"
#define RESERVAS_DB_FILE      "reservas.bin"

void mainMenu() {
    int option;

    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Administrador\n");
        printf("2. Cliente\n");
        printf("3. Organização de Evento\n");
        printf("0. Sair\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                adminMenu();
                break;
            case 2:
                clientesMenu();
                break;
            case 3:
                espacoMenu();
                break;
            case 0:
                printf("A sair do sistema...\n");
                break;
            default:
                puts(ERRO_NUM_INVALIDO);
        }
    } while (option != 0);
}

void adminMenu() {
    int option, option1, option2;
    do {
        printf("\n===== Menu Administrador =====\n");
        printf("1. Gerir Espaços\n");
        printf("2. Gerir Clientes\n");
        printf("3. Gerir Equipamentos\n");
        printf("0. Voltar\n");
        printf("==============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                consoleClean();
                clientesMenu(cliente);
                break;
            case 2:
                do{
                    printf("\n===== Gerir Clientes =====\n");
                    printf("1. Adicionar Clientes\n");
                    printf("2. Listar Clientes\n");
                    printf("3. Atualizar Dados do Cliente\n");
                    printf("4. Apagar Ficha de Cliente\n");
                    printf("5. Gerar Estatísticas do Cliente\n");
                    printf("0. Voltar\n");
                    printf("========================\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &option2);    

                    switch(option2) {
                        case 1:
                            consoleClean();
                            createClientes(clientes);
                            break;
                        case 2:
                            consoleClean();
                            listClientes(clientes);
                            break;
                        case 3:
                            consoleClean();
                            updateClientes(clientes);
                            break;
                        case 4:
                            consoleClean();
                            deleteClientes(clientes);
                            break;
                        case 5:
                            consoleClean();
                            gerarEstatisticasClientes(clientes);
                            break;
                        case 0:
                            consoleClean();
                            break;
                        default:
                            puts(ERRO_NUM_INVALIDO);
                    }
                } while (option2 != 0);                
                break;
            case 3:
                printf("Gerir Equipamentos selecionado.\n");
                break;
            case 0:
                printf("A voltar ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);
}

void clientesMenu() {
    
    int optionClientes;

    do{
                    printf("\n===== Gerir Espaços =====\n");
                    printf("1. Adicionar Clientes\n");
                    printf("2. Listar Clientes\n");
                    printf("3. Atualizar Dados do Cliente\n");
                    printf("4. Apagar Ficha de Cliente\n");
                    printf("5. Gerar Estatísticas do Cliente\n");
                    printf("0. Voltar\n");
                    printf("========================\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &optionClientes);    

                    switch(optionClientes) {
                        case 1:
                            consoleClean();
                            createClientes(clientes);
                            break;
                        case 2:
                            consoleClean();
                            listClientes(clientes);
                            break;
                        case 3:
                            consoleClean();
                            updateClientes(clientes);
                            break;
                        case 4:
                            consoleClean();
                            deleteClientes(clientes);
                            break;
                        case 5:
                            consoleClean();
                            gerarEstatisticasClientes(clientes);
                            break;
                        case 0:
                            consoleClean();
                            break;
                        default:
                            puts(ERRO_NUM_INVALIDO);
                    }
                } while (option1 != 0);
                break;

// Menu da Organização do Evento
void espacoMenu() {
    int option;
    do {
        printf("\n===== Menu Organização de Evento =====\n");
        printf("1. Verificar Reservas\n");
        printf("2. Confirmar ou Cancelar Reservas\n");
        printf("3. Gerir Logística de Equipamentos\n");
        printf("4. Gerar Relatórios de Utilização\n");
        printf("0. Voltar\n");
        printf("======================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Verificar Reservas selecionado.\n");
                break;
            case 2:
                printf("Confirmar ou Cancelar Reservas selecionado.\n");
                break;
            case 3:
                printf("Gerir Logística de Equipamentos selecionado.\n");
                break;
            case 4:
                printf("Gerar Relatórios de Utilização selecionado.\n");
                break;
            case 0:
                printf("A voltar ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);
}

int main() {
    mainMenu();
    return 0;
}
