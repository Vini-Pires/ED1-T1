#include "headers/pilha.h"
#include "headers/main.h"

void LimpaTela(){ // FUNÇÃO PARA LIMPAR O CONSOLE (ORGANIZAÇÃO)
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}

// Inicializa uma pilha vazia
void inicializarPilha(Pilha* pilha){
  pilha->topo = NULL;     // INICIALIZA O TOPO DA PILHA COMO NULL
}

// Função para empilhar uma música
void push(Pilha* pilha, const char* nomemusic, const char* playlist){ // EMPILHA A MÚSICA ATUAL NO HISTÓRICO
  NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha)); // ALOCA MEMÓRIA PARA O NOVO ELEMENTO
  if (novo == NULL){
    printf("Erro ao alocar memória.\n");
    return;
  }

  strcpy(novo->musica.nomemusic, nomemusic);  // COPIA O NOME DA MUSICA PARA O NOVO ELEMENTO
  strcpy(novo->musica.playlist, playlist);    // COPIA O NOME DA PLAYLIST PARA O NOVO ELEMENTO
  novo->proximo = pilha->topo;                // PROXIMO RECEBE O TOPO
  pilha->topo = novo;                         // TOPO RECEBE O NOVO ELEMENTO

  //printf("Música '%s' da playlist '%s' foi adicionada ao histórico de músicas tocadas.\n", nomemusic, playlist);
}

// Função para remover a música do topo da pilha
void pop(Pilha* pilha){
  if (pilha->topo == NULL){       // VERIFICA SE A ESTRUTURA ESTÁ VAZIA
    printf("Pilha vazia.\n");
    return;
  }

  NoPilha* temp = pilha->topo;
  pilha->topo = temp->proximo;    // TOPO RECEBE O PRÓXIMO E VAI PARA O AUXILIAR
  printf("Removendo música: %s\n", temp->musica.nomemusic);
  free(temp); // LIMPAMOS O AUXILIAR COM O ELEMENTO QUE ESTAVA NO TOPO
}

// Função para exibir a pilha de músicas
void mostrarPilha(Pilha* pilha){
  NoPilha* atual = pilha->topo;       // CRIA UM NÓ AUXILIAR QUE RECEBE O TOPO DA PILHA
  printf("=== Histórico de Músicas Tocadas ===\n");
  while (atual != NULL) {
    printf("Música: %s | Playlist: %s\n", atual->musica.nomemusic, atual->musica.playlist);
    atual = atual->proximo; // O ELEMENTO ATUAL RECEBE O PRÓXIMO 1 -> 2 | 2 -> 3 | 3 -> 4
  }
}
