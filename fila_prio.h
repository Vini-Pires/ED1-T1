
#ifndef FILA_H
#define FILA_H

#include "main.h"
#include "pilha.h" // necessário para utilizar a estrutura Pilha

#define MAX_MUSICAS_INICIAIS 4     /**< Número máximo de músicas carregadas inicialmente */
#define TAM_BUFFER 100             /**< Tamanho padrão do buffer para leitura de strings */

/**
 * @brief Ordena a lista de músicas por prioridade.
 *
 * Utiliza o campo de prioridade da estrutura `Musica` para ordenar a lista
 * do maior para o menor valor. Prioridades maiores significam que a música
 * deve ser tocada antes.
 *
 * @param lista Vetor de estruturas `Musica` a ser ordenado.
 * @param total Quantidade total de músicas no vetor.
 */
void ordenarPorPrioridade(Musica *lista, int total);

/**
 * @brief Remove o caractere de quebra de linha de uma string.
 *
 * Essa função verifica a existência de um caractere de nova linha (`\n`)
 * no final da string e, se encontrado, o substitui por um terminador nulo (`\0`).
 *
 * @param texto Ponteiro para a string que será tratada.
 */
void removerQuebraLinha(char *texto);

/**
 * @brief Função principal de execução da fila de músicas.
 *
 * Esta função representa a lógica principal do programa que manipula
 * uma fila de músicas baseada em prioridade. Ela interage com o histórico
 * armazenado em uma pilha, permitindo operações como tocar, exibir e salvar
 * músicas tocadas.
 *
 * @param historico Ponteiro para a pilha usada para armazenar o histórico de músicas tocadas.
 */
void filamusic(Pilha *historico);

#endif // FILA_H
