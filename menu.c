#include "menu.h"
#include "main.h"

void limparTela(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibirMenu(Pilha *historico) {
    int opcao;
    do {
        limparTela();
        printf("=====================================\n");
        printf("         Bem-vindo ao SO TRACK BOA!\n");
        printf("=====================================\n\n");
        printf("1 - Adicionar/Remover música\n");
        printf("2 - Mostrar playlists\n");
        printf("3 - Criar playlists\n");
        printf("4 - Músicas recentes (Histórico)\n");
        printf("0 - Sair\n");
        printf("Opção: ");

        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' do buffer

        switch(opcao) {
            case 1:
                limparTela();
                exibirMusica(historico);
                break;
            case 2:
                limparTela();
                printf("Funcionalidade 'Mostrar playlists' ainda não implementada.\n");
                printf("Pressione ENTER para voltar ao menu...");
                getchar();
                break;
            case 3:
                limparTela();
                printf("Funcionalidade 'Criar playlists' ainda não implementada.\n");
                printf("Pressione ENTER para voltar ao menu...");
                getchar();
                break;
            case 4:
                limparTela();
                exibirHistorico(historico);
                break;
            case 0:
                printf("\nEncerrando o programa SO TRACK BOA!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0);
}

void exibirMusica(Pilha *historico) {

    // Aqui você deve chamar a função que gerencia a fila de reprodução e inserção de músicas
    // Como você tem a função filamusic no seu código, vamos chamá-la aqui.

    filamusic(historico);

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}

void exibirHistorico(Pilha *historico) {
    if (historico->topo == NULL) {
        printf("O histórico de músicas está vazio.\n");
    } else {
        mostrarPilha(historico);

        printf("\nDeseja remover a música do topo do histórico?\n");
        printf("1 - Sim\n2 - Não\n");
        int escolha = 0;

        do {
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1) {
                pop(historico);
                printf("Música removida do histórico.\n");
            } else if (escolha == 2) {
                printf("Nenhuma música foi removida.\n");
            } else {
                printf("Opção inválida. Digite 1 para Sim ou 2 para Não.\n");
            }
        } while (escolha != 1 && escolha != 2);
    }

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}

void exibirPlaylists(PLAYLIST *playlists, int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma playlist disponível.\n");
    } else {
        printf("=== Playlists Disponíveis ===\n");
        for (int i = 0; i < quantidade; i++) {
            printf("%d - %s (Total de músicas: %d)\n", i + 1, playlists[i].nome_playlist, playlists[i].qntd_elementos);
        }
    }

    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}
