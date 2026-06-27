#ifndef FUNCAO_H
#define FUNCAO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bancodedados.h"

typedef struct {
    Jogador goleiro;
    Jogador zagueiro;
    Jogador meio;
    Jogador atacante;
    int possuiGol;
    int possuiZag;
    int possuiMei;
    int possuiAta;
} TimeUsuario;

void inicializarTime(TimeUsuario *time) {
    time->possuiGol = 0;
    time->possuiZag = 0;
    time->possuiMei = 0;
    time->possuiAta = 0;
}

void exibirDraft(Copa banco[], int indice) {
    printf("\n====================================\n");
    printf("SELECAO: %s\n", banco[indice].nomeSelecao);
    printf("====================================\n");

    for(int i = 0; i < 4; i++) {
        printf("[%d] %s (%s) OVR:%d\n",
               i + 1,
               banco[indice].elenco[i].nome,
               banco[indice].elenco[i].posicao,
               banco[indice].elenco[i].overall);
    }
    printf("====================================\n");
}

void adicionarJogador(TimeUsuario *time, Jogador jogador) {
    if(strcmp(jogador.posicao,"GOL") == 0) {
        if(!time->possuiGol) {
            time->goleiro = jogador;
            time->possuiGol = 1;
        } else printf("Voce ja possui goleiro!\n");
    }
    else if(strcmp(jogador.posicao,"ZAG") == 0) {
        if(!time->possuiZag) {
            time->zagueiro = jogador;
            time->possuiZag = 1;
        } else printf("Voce ja possui zagueiro!\n");
    }
    else if(strcmp(jogador.posicao,"MEI") == 0) {
        if(!time->possuiMei) {
            time->meio = jogador;
            time->possuiMei = 1;
        } else printf("Voce ja possui meio!\n");
    }
    else if(strcmp(jogador.posicao,"ATA") == 0) {
        if(!time->possuiAta) {
            time->atacante = jogador;
            time->possuiAta = 1;
        } else printf("Voce ja possui atacante!\n");
    }
}

void mostrarTime(TimeUsuario time) {
    printf("\n========== SEU TIME ==========\n");
    printf("GOL: %s\n", time.possuiGol ? time.goleiro.nome : "Vazio");
    printf("ZAG: %s\n", time.possuiZag ? time.zagueiro.nome : "Vazio");
    printf("MEI: %s\n", time.possuiMei ? time.meio.nome : "Vazio");
    printf("ATA: %s\n", time.possuiAta ? time.atacante.nome : "Vazio");
    printf("================================\n");
}

int timeCompleto(TimeUsuario time) {
    return time.possuiGol && time.possuiZag && time.possuiMei && time.possuiAta;
}

int calcularOverall(TimeUsuario time) {
    return time.goleiro.overall + time.zagueiro.overall + time.meio.overall + time.atacante.overall;
}

void montarTimeIA(TimeUsuario *ia) {
    while(!timeCompleto(*ia)) {
        int selecao = rand() % 20;
        int jogador = rand() % 4;
        adicionarJogador(ia, BancoDeCopas[selecao].elenco[jogador]);
    }
}

void simularPartida(TimeUsuario jogador, TimeUsuario maquina) {
    int forcaJogador = calcularOverall(jogador) + rand() % 30;
    int forcaIA = calcularOverall(maquina) + rand() % 30;
    int golsJogador = rand() % 4;
    int golsIA = rand() % 4;

    if(forcaJogador > forcaIA) golsJogador += 2;
    else if(forcaIA > forcaJogador) golsIA += 2;

    printf("\n========== PARTIDA ==========\n");
    printf("VOCE %d x %d MAQUINA\n", golsJogador, golsIA);

    if(golsJogador > golsIA) printf("VOCE VENCEU!\n");
    else if(golsIA > golsJogador) printf("VOCE PERDEU!\n");
    else printf("EMPATE!\n");
}

#endif // FUNCAO_H