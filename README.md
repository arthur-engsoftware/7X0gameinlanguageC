# 7x0 JogoInC ⚽

Um clone simples em **linguagem C** do jogo de draft de futebol [7a0.com.br](https://7a0.com.br/), onde o jogador monta um time escolhendo jogadores de diferentes Copas do Mundo e enfrenta um time montado aleatoriamente pela máquina.

## 📋 Sobre o projeto

O jogo sorteia uma seleção de uma Copa do Mundo (de 1970 a 2026) e mostra 4 jogadores dessa seleção. O usuário escolhe um deles para entrar no seu time. Esse processo se repete até o time do jogador estar completo, com um titular em cada posição:

- **GOL** (Goleiro)
- **ZAG** (Zagueiro)
- **MEI** (Meio-campo)
- **ATA** (Atacante)

Depois que o time do jogador está completo, a máquina monta o seu próprio time automaticamente e a partida é simulada com base no overall (nível) combinado de cada time, com um fator de aleatoriedade.

## 🗂️ Estrutura de arquivos

| Arquivo | Responsabilidade |
|---|---|
| `bancodedados.h` | Define as `structs` (`Jogador`, `Copa`) e **declara** (`extern`) o banco de dados `BancoDeCopas` |
| `bancodedados.c` | Contém a **definição** real do `BancoDeCopas`, com os dados de 20 Copas e seus jogadores |
| `funcao.h` | Define a struct `TimeUsuario` e todas as funções de lógica do jogo (montar time, validar posição, simular partida, etc.) |
| `main.c` | Loop principal do jogo: laço de draft, leitura da escolha do usuário e chamada da simulação final |

## ⚙️ Conceitos de C aplicados

Este projeto é um bom exemplo prático de:

- **Declaração vs. Definição**: `bancodedados.h` apenas *declara* (`extern Copa BancoDeCopas[20];`) que a variável existe; quem efetivamente a *define*, com todos os dados, é o `bancodedados.c`. Isso evita erros de "redefinition" na compilação e "undefined reference" na linkagem.
- **Múltiplos arquivos `.c` compilados juntos**: o projeto não compila com apenas `gcc main.c`, é necessário incluir `bancodedados.c` na linha de compilação.
- **Structs aninhadas**: `Copa` contém um array de 4 `Jogador`.
- **Ponteiros para structs**: funções como `adicionarJogador` e `inicializarTime` recebem `TimeUsuario *` para alterar o time original em vez de uma cópia.
- **`rand()` e `srand()`**: usados tanto para sortear a Copa exibida no draft quanto para a aleatoriedade na montagem do time da IA e no placar da partida.

## ▶️ Como compilar e rodar

> ⚠️ É necessário compilar **os dois arquivos `.c`** juntos (`main.c` e `bancodedados.c`), senão o linker não encontra `BancoDeCopas`.

```bash
gcc main.c bancodedados.c -o jogo
./jogo
```

### Usando VS Code (tasks.json)

Se estiver usando a extensão C/C++ do VS Code com a tarefa "gcc build active file", é preciso editar `.vscode/tasks.json` para incluir os dois arquivos `.c` nos `args` da tarefa de build, já que por padrão ela compila só o arquivo aberto no editor (`${file}`).

## 🎮 Como jogar

1. Execute o programa.
2. A cada rodada, 4 jogadores de uma seleção aleatória são exibidos.
3. Digite o número (1 a 4) do jogador que deseja escolher.
4. Se a posição dele já estiver preenchida no seu time, você verá um aviso e uma nova rodada de draft começará.
5. Quando seu time tiver GOL, ZAG, MEI e ATA preenchidos, a máquina monta o time dela automaticamente e a partida é simulada.
6. O resultado final (vitória, derrota ou empate) é exibido no terminal.

## 🚧 Melhorias futuras

- [ ] Limpar a tela (`system("clear")`) a cada rodada do draft, para não acumular o histórico de seleções anteriores
- [ ] Silenciar as mensagens de "Voce ja possui X" quando for a IA escolhendo o time dela (atualmente aparecem no terminal mesmo sendo escolha automática)
- [ ] Validar entradas não-numéricas no `scanf` (hoje, digitar uma letra trava o loop)
- [ ] Adicionar mais Copas e jogadores ao banco de dados
- [ ] Persistir o histórico de partidas em um arquivo

## 👤 Autor

Projeto desenvolvido por Arthur José como exercício de structs, ponteiros e organização de projetos multi-arquivo em C.
