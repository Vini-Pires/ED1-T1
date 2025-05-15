#ifndef PILHA_H
#define PILHA_H

#include "main.h"

/**
* @brief Função que limpa os dados do terminal do VsCode
*
* Verifica o sistema operacional e utiliza o comando
* para limpar o console de acordo com isso.
*/
void LimpaTela();

/**
* @brief Estrutura que representa um nó da pilha de músicas
*
* Cada nó armazena uma música e um ponteiro para o próximo
* permitindo a construção de uma pilha encadeada.
*/
typedef struct NoPilha{
  Musica musica;              /**< Dados da música armazenada */
  struct NoPilha* proximo;    /**< Ponteiro para o próximo nó */
} NoPilha;

/**
* @brief Estrutura que representa a pilha de músicas
*
* A pilha armazena um ponteiro para o topo da estrutura
* que é o primeiro elemento(nó) da pilha;
*/
typedef struct Pilha{
  NoPilha* topo;              /**< Ponteiro para o topo da pilha */
} Pilha;

/**
* @brief Inicializa a pilha.
*
* Esta função define os valores iniciais da pilha,
* configurando o topo como NULL.
*
* @param pilha Ponteiro para a estrutura da pilha que será inicializada.
*/
void inicializarPilha(Pilha* pilha);

/**
* @brief Insere um novo elemento no topo da pilha.
*
* Adiciona uma nova música e sua playlist associada ao topo da pilha.
*
* @param pilha Ponteiro para a pilha onde o elemento será inserido.
* @param nomemusic Nome da música a ser adicionada.
* @param playlist Nome da playlist associada à música.
*/
void push(Pilha* pilha, const char* nomemusic, const char* playlist);

/**
* @brief Remove o elemento do topo da pilha.
*
* Remove a música mais recentemente adicionada à pilha.
*
* @param pilha Ponteiro para a pilha da qual o elemento será removido.
*/
void pop(Pilha* pilha);

/**
* @brief Mostra todos os elementos da pilha.
*
* Exibe no console todas as músicas e suas playlists presentes na pilha,
* do topo até a base.
*
* @param pilha Ponteiro para a pilha a ser exibida.
*/
void mostrarPilha(Pilha* pilha);

#endif // PILHA_H
