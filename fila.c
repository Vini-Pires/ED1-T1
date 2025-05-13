#include "fila.h"
#include <stdio.h>
#include <string.h>

// Ordena as músicas por prioridade decrescente
void ordenarPorPrioridade(Musica *lista, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (lista[j].prioridade > lista[i].prioridade) {
                Musica temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Remove o '\n' do final da string
void removerQuebraLinha(char *texto) {
    size_t tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }
}

// Função principal que executa a lógica da fila de músicas
void filamusic(Pilha *historico) {
    setbuf(stdout, NULL);
    printf("=====================================\n");
    printf("  Bem-vindo ao SO TRACK BOA!\n");
    printf("=====================================\n\n");

    Musica fila[MAX_MUSICAS_INICIAIS + 1]; // +1 para a nova música
    int quantidadeMusicas = MAX_MUSICAS_INICIAIS;
    char entrada[TAM_BUFFER];

    // Leitura das músicas iniciais
    for (int i = 0; i < MAX_MUSICAS_INICIAIS; i++) {
        printf("Digite o nome da música %d: ", i + 1);
        fgets(entrada, TAM_BUFFER, stdin);
        removerQuebraLinha(entrada);
        strncpy(fila[i].nomemusic, entrada, sizeof(fila[i].nomemusic) - 1);
        fila[i].nomemusic[sizeof(fila[i].nomemusic) - 1] = '\0';

        printf("Digite o nome da playlist: ");
        fgets(entrada, TAM_BUFFER, stdin);
        removerQuebraLinha(entrada);
        strncpy(fila[i].playlist, entrada, sizeof(fila[i].playlist) - 1);
        fila[i].playlist[sizeof(fila[i].playlist) - 1] = '\0';

        printf("Digite a prioridade (número inteiro): ");
        scanf("%d", &fila[i].prioridade);
        getchar(); // Limpa o '\n' restante
        printf("\n");
    }

    // Ordena por prioridade
    ordenarPorPrioridade(fila, quantidadeMusicas);

    // Toca a primeira música
    printf("Tocando agora: %s (Prioridade: %d)\n\n", fila[0].nomemusic, fila[0].prioridade);
    push(historico, fila[0].nomemusic, fila[0].playlist);

    // Inserção de nova música na fila
    printf("-- Inserir nova música na fila --\n");
    Musica novaMusica;

    printf("Digite o nome da nova música: ");
    fgets(entrada, TAM_BUFFER, stdin);
    removerQuebraLinha(entrada);
    strncpy(novaMusica.nomemusic, entrada, sizeof(novaMusica.nomemusic) - 1);
    novaMusica.nomemusic[sizeof(novaMusica.nomemusic) - 1] = '\0';

    printf("Digite o nome da playlist da nova música: ");
    fgets(entrada, TAM_BUFFER, stdin);
    removerQuebraLinha(entrada);
    strncpy(novaMusica.playlist, entrada, sizeof(novaMusica.playlist) - 1);
    novaMusica.playlist[sizeof(novaMusica.playlist) - 1] = '\0';

    printf("Digite a prioridade da nova música: ");
    scanf("%d", &novaMusica.prioridade);
    getchar();
    printf("\n");

    // Insere a nova música na posição 1 (após a primeira)
    for (int i = quantidadeMusicas; i > 1; i--) {
        fila[i] = fila[i - 1];
    }
    fila[1] = novaMusica;
    quantidadeMusicas++;

    // Toca a próxima música (nova inserida)
    printf("Próxima na fila: %s (Prioridade: %d)\n\n", fila[1].nomemusic, fila[1].prioridade);
    push(historico, fila[1].nomemusic, fila[1].playlist);

    // Lista as próximas músicas da fila
    printf("Músicas ainda não tocadas:\n");
    for (int i = 2; i < quantidadeMusicas; i++) {
        printf("  %d. %s (Prioridade: %d)\n", i - 1, fila[i].nomemusic, fila[i].prioridade);
    }
}
