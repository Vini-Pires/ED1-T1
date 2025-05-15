#include "fila_playlist.h"

void inicializePlaylist (PLAYLIST *f, char nome[]) {
  f->bot = NULL;
  f->top = NULL;
  f->qntd_elementos = 0;
  strcpy(f->nome_playlist, nome);
}

bool isEmptyPlaylist (PLAYLIST *f) {
  return f->qntd_elementos == 0;
}

int sizePlaylist (PLAYLIST *f) {
  return f->qntd_elementos;
}

void pushPlaylist (PLAYLIST *f, char musica[]) {
  NO_PLAYLIST *aux = (NO_PLAYLIST*) malloc(sizeof(NO_PLAYLIST));
  if (aux == NULL) {
    perror("Erro de Alocação de memoria {PUSH}\n");
    return;
  }

  strcpy(aux->music.nomemusic, musica);
  aux->music.prioridade = 0;

  f->bot = aux;
  f->qntd_elementos ++;
}

void popPlaylist (PLAYLIST *f) {
  if (isEmptyPlaylist) {
    printf("Playlist Vazia\n");
    return;
  }

  NO_PLAYLIST *aux = f->bot;
  f->bot = aux->prox;
  f->qntd_elementos--;

  free(aux);
  return;
}

void destructPlaylist (PLAYLIST *f) {
  while (isEmptyPlaylist(f) == false) {
    popPlaylist(f);
  }
}
