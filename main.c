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
 */

 #include "main.h"
 #include "pilha.h"
 #include "fila.h" // <-- IMPORTANTE: inclui a fila aqui
 
 int main() {
     int opcao;
     Pilha historico;
 
     inicializarPilha(&historico);
 
     LimpaTela();
 
     do {
         printf("=====================================\n");
         printf("  Bem-vindo ao SO TRACK BOA!\n");
         printf("=====================================\n\n");
         printf("1 - Adicionar/Remover música\n");
         printf("2 - Mostrar playlists\n");
         printf("3 - Criar playlists\n");
         printf("4 - Músicas recentes\n");
         printf("0 - Sair\n");
         printf("Opcão: ");
 
         do {
             setbuf(stdin, NULL);
             scanf("%i", &opcao);
             if (opcao < 0 || opcao > 4) {
                 printf("Você não digitou uma opção válida, tente novamente!\n");
             }
         } while (opcao < 0 || opcao > 4);
 
         switch (opcao) {
             case 1:
                 LimpaTela();
                 filamusic(&historico); // <-- Chama a função que usa a fila
                 break;
             case 2:
                 LimpaTela();
                 printf("Funcionalidade 'Mostrar playlists' ainda não implementada.\n\n");
                 break;
             case 3:
                 LimpaTela();
                 printf("Funcionalidade 'Criar playlists' ainda não implementada.\n\n");
                 break;
             case 4: {
                 int yorn;
                 do {
                     mostrarPilha(&historico);
                     printf("Deseja apagar a música que está no topo?\n");
                     printf("1 - Sim\n2 - Não/Sair\n");
                     scanf("%i", &yorn);
                     if (yorn < 1 || yorn > 2) {
                         printf("Digite uma opção válida!\n");
                     }
                 } while (yorn < 1 || yorn > 2);
 
                 if (yorn == 1) {
                     pop(&historico);
                 }
                 LimpaTela();
                 break;
             }
             case 0:
                 printf("Encerrando o programa SO TRACK BOA!\n\n");
                 break;
         }
 
     } while (opcao != 0);
 
     return EXIT_SUCCESS;
 }
 