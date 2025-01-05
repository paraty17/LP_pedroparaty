#ifndef CLIENTES_H
#define CLIENTES_H

#include "structs.h"


void createClientes(Clientes *clientes, char *file, Reservas reservas);

void readClientes(Cliente clientes);

void listClientes(Cliente clientes);

void updateClientes(Clientes *clientes);

void updateClientes(Clientes *clientes, char *file);

void deleteClientes(Clientes *clientes, char *file);

void apagarDadosCliente(Clientes *cliente);

void searchClientes(Cliente clientes);

void listarClientes(Cliente clientes);

void expandClientes(Clientes *clientes);

void freeClientes(Clientes *clientes);

void gerarEstatisticasClientes(Clientes **clientes, int total);

int getCounterCompFX(char *file);

void loadClientes(Clientes *clientes, char* file);

void updateCounterCompFX(int contador, char *file);

void addClientesFX(Cliente clientes, char *file);

void updateClientesFX(Cliente clientes, int index, char *file);

void deleteClientesFX(Cliente clientes, char* file);

void searchClientesNif(Cliente clientes, Reservas reserva);


#endif /* CLIENTES_H */