#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    char posicao[4]; // "GOL", "ZAG", "MEI", "ATA"
    int overall;
} Jogador;

typedef struct {
    char nomeSelecao[30];
    Jogador elenco[4];
} Copa;

// A definição completa (com os dados de todas as copas) fica em bancodedados.c.
// Aqui só declaramos que ela existe, para quem incluir este header.
extern Copa BancoDeCopas[20];

#endif // BANCODEDADOS_H
