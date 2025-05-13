#ifndef FILA_H
#define FILA_H

#include "main.h"
#include "pilha.h" // necessário para a estrutura Pilha

#define MAX_MUSICAS_INICIAIS 4
#define TAM_BUFFER 100

void ordenarPorPrioridade(Musica *lista, int total);
void removerQuebraLinha(char *texto);
void filamusic(Pilha *historico);  // Renomeado

#endif // FILA_H
