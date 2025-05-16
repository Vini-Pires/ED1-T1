#ifndef MENU_H
#define MENU_H

#include "main.h"
#include "pilha.h"
#include "fila_playlist.h"

/**
 * @brief Exibe o menu principal do programa e gerencia as opções do usuário.
 *
 * Esta função apresenta as opções disponíveis para o usuário,
 * lê a opção selecionada e chama as funções correspondentes
 * para manipular músicas, playlists e histórico.
 *
 * @param historico Ponteiro para a pilha que armazena o histórico de músicas tocadas.
 */
void exibirMenu(Pilha *historico);

/**
 * @brief Função para adicionar ou remover músicas na fila de reprodução.
 *
 * Esta função permite ao usuário inserir uma nova música na fila de prioridades,
 * atualiza o histórico e gerencia a ordem de reprodução conforme prioridades.
 *
 * @param historico Ponteiro para a pilha que armazena o histórico de músicas tocadas.
 */
void exibirMusica(Pilha *historico);

/**
 * @brief Exibe as playlists criadas no sistema.
 *
 * Percorre todas as playlists disponíveis e exibe seus nomes e músicas.
 * Pode ser expandida para manipular playlists (criar, editar, remover).
 *
 * @param playlists Array de playlists existentes.
 * @param quantidade Número total de playlists existentes no array.
 */
void exibirPlaylists(PLAYLIST *playlists, int quantidade);

/**
 * @brief Exibe o histórico das músicas tocadas.
 *
 * Mostra as músicas armazenadas na pilha de histórico, do mais recente ao mais antigo.
 *
 * @param historico Ponteiro para a pilha que armazena o histórico de músicas tocadas.
 */
void exibirHistorico(Pilha *historico);

/**
 * @brief Limpa a tela do terminal.
 *
 * Detecta o sistema operacional e executa o comando adequado
 * para limpar o console, melhorando a experiência do usuário.
 */
void limparTela(void);

#endif
