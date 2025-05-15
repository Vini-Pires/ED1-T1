#ifndef FILA_H
#define FILA_H

#include "main.h"

typedef struct no_playlist {
  Musica music;
  struct no_playlist *prox;
} NO_PLAYLIST;

typedef struct {
  NO_PLAYLIST *top;
  NO_PLAYLIST *bot;
  int qntd_elementos;
  char nome_playlist[NOME_TAM];
} PLAYLIST;


void inicializePlaylist(PLAYLIST *f, char nome[]);

bool isEmptyPlaylist(PLAYLIST *f);

int sizePlaylist(PLAYLIST *f);

void pushPlaylist(PLAYLIST *f, char nome[]);

void searchPlaylist();

void popPlaylist(PLAYLIST *f);

void destructPlaylist(PLAYLIST *f);

#endif
