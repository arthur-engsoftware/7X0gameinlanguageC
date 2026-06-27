#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bancodedados.h"
#include "funcao.h"

int main() {

    srand(time(NULL)); // garante números aleatórios diferentes a cada execução

    TimeUsuario meuTime;
    inicializarTime(&meuTime);

    printf("=========================================\n");
    printf(" BEM-VINDO AO DRAFT - MONTE SEU TIME 7x0\n");
    printf("=========================================\n");

    // Loop principal do draft: continua até GOL, ZAG, MEI e ATA estarem preenchidos
    while (!timeCompleto(meuTime)) {

        int dado = rand() % 20;
        exibirDraft(BancoDeCopas, dado);

        mostrarTime(meuTime);

        int escolha;
        printf("\nEscolha um jogador (1-4) para o seu time: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 4) {
            printf("Opcao invalida! Escolha um numero de 1 a 4.\n");
            continue;
        }

        Jogador jogadorEscolhido = BancoDeCopas[dado].elenco[escolha - 1];
        adicionarJogador(&meuTime, jogadorEscolhido);
    }

    printf("\nSEU TIME ESTA COMPLETO!\n");
    mostrarTime(meuTime);

    // Monta o time adversário (IA) automaticamente
    TimeUsuario timeIA;
    inicializarTime(&timeIA);
    montarTimeIA(&timeIA);

    printf("\nTIME DA MAQUINA:\n");
    mostrarTime(timeIA);

    // Simula a partida final
    simularPartida(meuTime, timeIA);

    return 0;
}
