#ifndef FUNCAO_H
#define FUNCAO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bancodedados.h"

void exibirOpcoesDraft(Copa banco[], int indiceSorteado) {

    printf("=== INICIANDO O DRAFT DO TORNEIO 7x0 ===\n\n");

    printf("\n=========================================\n");
    printf(" SELECAO SORTEADA: %s \n", banco[indiceSorteado].nomeSelecao);
    printf("=========================================\n");
    printf("Escolha um jogador para o seu time:\n\n");

    for (int i = 0; i < 4; i++) {
        printf("[%d] %-20s (%s) - OVERALL: %d\n",
               i + 1,
               banco[indiceSorteado].elenco[i].nome,
               banco[indiceSorteado].elenco[i].posicao,
               banco[indiceSorteado].elenco[i].overall);
    }

    printf("=========================================\n");
}

#endif // FUNCAO_H
