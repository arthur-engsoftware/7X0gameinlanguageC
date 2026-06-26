#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bancodedados.h"
#include "funcao.h"

int main() {

    srand(time(NULL)); // garante números aleatórios diferentes a cada execução
    int dado = rand() % 20;
    exibirOpcoesDraft(BancoDeCopas, dado);

    return 0;
}
