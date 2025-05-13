#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura que representa uma música
typedef struct {
    char nomemusic[100];   // Nome da música
    char playlist[100];    // Nome da playlist
    int prioridade;        // Prioridade da música
} Musica;

#endif
