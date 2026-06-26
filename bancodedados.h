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

Copa BancoDeCopas[20] = {

    // --- ERA CLÁSSICA ---
    {
        "Brasil 1970",
        {{"Pele", "ATA", 98}, {"Rivelino", "MEI", 92}, {"Tostao", "ATA", 89}, {"Carlos Alberto", "ZAG", 91}}
    },
    {
        "Holanda 1974",
        {{"Cruyff", "MEI", 96}, {"Neeskens", "MEI", 89}, {"Rensenbrink", "ATA", 87}, {"Krol", "ZAG", 88}}
    },
    {
        "Alemanha O. 1974",
        {{"Gerd Muller", "ATA", 94}, {"Beckenbauer", "ZAG", 95}, {"Sepp Maier", "GOL", 90}, {"Overath", "MEI", 87}}
    },
    {
        "Argentina 1986",
        {{"Maradona", "MEI", 97}, {"Valdano", "ATA", 86}, {"Burruchaga", "MEI", 85}, {"Ruggeri", "ZAG", 86}}
    },
    {
        "Brasil 1994",
        {{"Romario", "ATA", 95}, {"Bebeto", "ATA", 89}, {"Dunga", "MEI", 86}, {"Taffarel", "GOL", 87}}
    },
    {
        "Franca 1998",
        {{"Zidane", "MEI", 94}, {"Henry", "ATA", 87}, {"Desailly", "ZAG", 88}, {"Barthez", "GOL", 85}}
    },

    // --- ANOS 2000 A 2010 ---
    {
        "Brasil 2002",
        {{"Ronaldo Fenomeno", "ATA", 96}, {"Rivaldo", "MEI", 92}, {"Ronaldinho Gaucho", "MEI", 90}, {"Marcos", "GOL", 86}}
    },
    {
        "Alemanha 2002",
        {{"Oliver Kahn", "GOL", 91}, {"Michael Ballack", "MEI", 89}, {"Klose", "ATA", 85}, {"Linke", "ZAG", 82}}
    },
    {
        "Italia 2006",
        {{"Cannavaro", "ZAG", 92}, {"Buffon", "GOL", 93}, {"Pirlo", "MEI", 91}, {"Totti", "MEI", 89}}
    },
    {
        "Franca 2006",
        {{"Zidane", "MEI", 93}, {"Henry", "ATA", 90}, {"Vieira", "MEI", 88}, {"Ribery", "ATA", 84}}
    },
    {
        "Espanha 2010",
        {{"Iniesta", "MEI", 92}, {"Xavi", "MEI", 92}, {"Casillas", "GOL", 91}, {"Puyol", "ZAG", 89}}
    },
    {
        "Holanda 2010",
        {{"Robben", "ATA", 90}, {"Sneijder", "MEI", 91}, {"Van Persie", "ATA", 87}, {"Van Bommel", "MEI", 83}}
    },

    // --- ANOS 2014 A 2026 ---
    {
        "Alemanha 2014",
        {{"Thomas Muller", "ATA", 89}, {"Kroos", "MEI", 90}, {"Lahm", "ZAG", 91}, {"Neuer", "GOL", 93}}
    },
    {
        "Argentina 2014",
        {{"Lionel Messi", "ATA", 94}, {"Mascherano", "MEI", 87}, {"Di Maria", "MEI", 86}, {"Romero", "GOL", 83}}
    },
    {
        "Franca 2018",
        {{"Mbappe", "ATA", 90}, {"Griezmann", "MEI", 88}, {"Kante", "MEI", 89}, {"Varane", "ZAG", 87}}
    },
    {
        "Croacia 2018",
        {{"Modric", "MEI", 91}, {"Rakitic", "MEI", 86}, {"Perisic", "ATA", 84}, {"Subasic", "GOL", 83}}
    },
    {
        "Argentina 2022",
        {{"Lionel Messi", "ATA", 96}, {"Di Maria", "ATA", 87}, {"Enzo Fernandez", "MEI", 84}, {"Dibu Martinez", "GOL", 87}}
    },
    {
        "Franca 2022",
        {{"Mbappe", "ATA", 93}, {"Griezmann", "MEI", 89}, {"Giroud", "ATA", 83}, {"Lloris", "GOL", 84}}
    },
    {
        "Marrocos 2022",
        {{"Ziyech", "MEI", 83}, {"Amrabat", "MEI", 84}, {"Hakimi", "ZAG", 86}, {"Bounou", "GOL", 85}}
    },
    {
        "Brasil 2026",
        {{"Vinicius Jr", "ATA", 92}, {"Rodrygo", "ATA", 88}, {"Bruno Guimaraes", "MEI", 86}, {"Alisson", "GOL", 89}}
    }
};

#endif // BANCODEDADOS_H
