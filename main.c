/**
* @file main.c
* @return Projeto De Estrutura de Dados 1 (SO TRACK BOA)
* @authors
* - Leonardo Tanamura (2614294 - leonardotanamura@alunos.utfpr.edu.br)
* - Vinicius Pires (2553171 - viniciuspires@alunos.utfpr.edu.br)
* - Enzo Livrari (2552795 - enzolivrari@alunos.utfpr.edu.br)
* @brief
* @version 0.1
* @date 2025-05-13
*
* @copyright Copyright (c) 2025
*/

#include "main.h"
#include "pilha.h"
#include "fila_prio.h"
#include "fila_playlist.h"
#include "menu.h"

int main(void) {

  Pilha historico;

  inicializarPilha(&historico);

  exibirMenu(&historico);


  return EXIT_SUCCESS;
}
