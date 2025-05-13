/**
 * @file main.c
 * @return Projeto De Estrutura de Dados 1 (SO TRACK BOA)
 * @authors
 * - Leonardo Tanamura (2614294 - leonardotanamura@alunos.utfpr.edu.br)
 * - Vinicius Pires (ra - you@domain.com)
 * - Enzo Livrari (2552795 - enzolivrari@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2025-05-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "main.h"
#include "pilha.h"

int main(){

    int opcao;

    Pilha historico;
    inicializarPilha(&historico);

    push(&historico, "Bohemian Rhapsody", "Rock Clássico");
    push(&historico, "Shape of You", "Pop");
    push(&historico, "Blinding Lights", "Hits 2020");       // APAGAR ISSO DAQUI DEPOIS ENZO, COLOQUEI PRA TE AUXILIAR
                                                            // VOCÊ TEM QUE COLOCAR ISSO EM BAIXO TODA VEZ QUE UMA MUSICA
                                                            // FOR COMEÇAR A TOCAR
    LimpaTela();
    do{
        printf("=====================================\n");
        printf("  Bem-vindo ao SO TRACK BOA!\n");
        printf("=====================================\n\n");
        printf("1 - Adicionar/Remover música\n");
        printf("2 - Mostrar playlists\n");
        printf("3 - Criar playlists\n");
        printf("4 - Músicas recentes\n");
        printf("0 - Sair\n");
        printf("Opcão: ");
        do{
            setbuf(stdin, NULL);
            scanf("%i", &opcao);
            if(opcao < 0 || opcao > 5){
                printf("Você não digitou uma opção válida, tente novamente!\n");
            };
        }while(opcao < 0 || opcao > 5);
        switch(opcao){
            case 4:
                int yorn;
                do{
                    mostrarPilha(&historico);
                    printf("Deseja apagar a música que está no topo?\n");
                    printf("1 - Sim\n2 - Não/Sair\n");
                    scanf("%i", &yorn);
                    if(yorn < 1 || yorn > 2){
                        printf("Digite uma opção vaĺida!\n");
                    }
                } while(yorn < 1 || yorn > 2);
                if(yorn == 1){
                    LimpaTela();
                    pop(&historico);
                    break;
                }
                LimpaTela();
                break;
            case 0:
                printf("Encerrando o programa SO TRACK BOA!\n\n");
        }
    }while(opcao != 0);

    return EXIT_SUCCESS;
}