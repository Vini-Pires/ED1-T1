#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tamanho fixo usado para nomes
#define NOME_TAM 100

// Estrutura que representa uma música
typedef struct {
    char nomemusic[NOME_TAM];   // Nome da música
    char playlist[NOME_TAM];    // Nome da playlist
    int prioridade;             // Prioridade da música
} Musica;

#endif // MAIN_H
