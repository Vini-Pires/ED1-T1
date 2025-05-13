#ifndef FILA_H
#define FILA_H

#include "main.h"

/**
 * @brief Tamanho máximo da fila de músicas iniciais.
 */
#define MAX_MUSICAS_INICIAIS 4

/**
 * @brief Tamanho máximo para leitura de strings (nome da música e playlist).
 */
#define TAM_BUFFER 100

/**
 * @brief Ordena as músicas por prioridade (ordem decrescente).
 *
 * Compara a prioridade de cada música e reorganiza a lista de modo
 * que as de maior prioridade fiquem no início.
 *
 * @param lista Vetor de músicas.
 * @param total Quantidade de músicas no vetor.
 */
void ordenarPorPrioridade(Musica *lista, int total);

/**
 * @brief Remove o caractere de quebra de linha (‘\n’) do final de uma string.
 *
 * Usada após o uso de `fgets` para evitar que o `\n` fique salvo na string.
 *
 * @param texto Ponteiro para a string a ser modificada.
 */
void removerQuebraLinha(char *texto);

/**
 * @brief Controla a lógica principal da fila de músicas.
 *
 * Responsável por receber as músicas, ordená-las e gerenciar a reprodução,
 * além de permitir a inserção de uma nova música na fila.
 */
void filaenzo();

#endif // FILA_H
