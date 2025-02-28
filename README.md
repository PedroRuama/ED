Estrutura de Dados
### Trabalho de Estrutura de Dados
> Rodrigo Garcia de Gáspari Valdejão - 831409  
> Alisson Costa Gurgel de Medeiros - 831645  
> João Henrique Marchesano Cukier - 822428  
> Pedro Ruama Nunes dos Santos  – 831660  
# Guia do Jogo de Cartas
	
## Índice
1. [Objetivo do Jogo](#objetivo-do-jogo)
2. [Configuração Inicial](#configuração-inicial)
3. [Como Jogar](#como-jogar)
4. [Condições de Vitória](#condições-de-vitória)
5. [Estratégias](#estratégias)
6. [Pontos chave do código](#pontos-chave-do-código)
   - [main.c](#mainc)
     - [Cálculo do valor total da carta](#cálculo-do-valor-total-da-carta)
     - [Lógica da rodada](#lógica-da-rodada)
     - [Distribuição de cartas aos jogadores](#distribuição-de-cartas-aos-jogadores)
     - [Determinação do vencedor final](#determinação-do-vencedor-final)
   - [carta.h](#carta-h)
   - [lista.h](#lista-h)

## Objetivo do Jogo
O jogo é disputado em cinco rodadas entre dois jogadores. Em cada uma delas, eles podem escolher uma carta para jogar e o vencedor da rodada é determinado pelo valor da carta multiplicado pelo valor do naipe. No final, quem vencer mais rodadas vence o jogo! 

## Configuração Inicial
1. Pegue um baralho padrão de 52 cartas (sem coringas).
2. Embaralhe bem as cartas.
3.  Distribua 5 cartas para cada jogador.
4.  As cartas restantes podem ser deixadas de lado, sem uso.
  
## Como Jogar
1. O jogo ocorre em 5 rodadas.
2. Em cada rodada, os jogadores escolhem uma carta de sua mão e a revelam ao mesmo tempo.
3. O valor da carta é determinado da seguinte forma:
    - Número da carta (Ás = 1; 2 a 10 são seus próprios valores; Valete = 11, Dama = 12, Rei = 13).
    - O valor do n-aipe segue esta regra:
      - ♦ Ouros = 1    
      - ♠ Espadas = 2
      - ♥ Copas = 3
      - ♣ Paus = 4
    - O valor total da carta é calculado como: número da carta multiplicado pelo valor do naipe
    - 
4. O jogador com a maior pontuação na rodada vence essa rodada.
5. Em caso de empate (dois jogadores com o mesmo valor total), ninguém ganha a rodada.
6. As cartas jogadas são descartadas e não voltam para o jogo.
7. O jogo continua até que todos os jogadores tenham jogado todas as suas cartas.

## Condições de Vitória
- O jogador que vencer mais rodadas ao longo do jogo é o vencedor!
- Também existe o caso do jogo dar empate, quando os dois jogadores possuem o mesmo número de vitórias!
## Estratégias
- Guardar cartas fortes para momentos decisivos pode ser uma boa estratégia.
- Fique atento às cartas já jogadas para prever as melhores jogadas futuras.
- Lembre-se que o naipe pode ser um multiplicador poderoso, então uma carta pequena com um naipe forte pode ser melhor do que uma carta alta com um naipe fraco!

# Pontos chave do código

## main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"
#include "lista.h"
```
No main.c temos os seguintes códigos importantes para o funcionamento do jogo:
### Cálculo do valor total da carta
> A função calcularValor é essencial, pois define a pontuação de cada carta com base no número e no naipe.
> Esse cálculo determina quem vence cada rodada
> 
> Estruturas de dados envolvidas: Struct Carta → Uma estrutura que contém os atributos valor e naipe.
```c
int calcularValor(Carta carta) {
    return carta.valor * carta.naipe;
}
```
### Lógica da rodada
> A função jogarRodada gerencia todo o processo de uma rodada
> Exibe as cartas disponíveis para o jogador.
> Permite que cada jogador escolha uma carta.
> Calcula o vencedor da rodada e atualiza a contagem de vitórias.
>
> Estruturas de dados envolvidas:
> - Acessa e manipula as listas (posicaoNaLista, removerPosicao).
> - Lista jogador1 e jogador2 → Representam a mão de cada jogador.
> - Vetor vetorVitorias[2] → Guarda a quantidade de rodadas vencidas por cada jogador.
```c
void jogarRodada(int rodada, lista jogador1, lista jogador2, int vetorVitorias[]) {
    int valorCartaJ1, valorCartaJ2;
    printf("\n--- Rodada %d ---\n", rodada + 1);

    for (int i = 0; i < 2; i++) {
        printf("Jogador %d, sua mao: ", i + 1);
        if (!i) mostrarMao(&jogador1, rodada);
        else mostrarMao(&jogador2, rodada);
        
        if (rodada == 4) printf("Você so tem uma carta (1): ");
        else printf("Escolha a carta (1 a %d): ", 5-rodada);
        
        int escolha;
        scanf("%d", &escolha);

        if (!i) {
            valorCartaJ1 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador1, escolha-1)));
            printf("O valor total de sua carta eh: %d\n", valorCartaJ1);
            removerPosicao(&jogador1, escolha-1);
        } else {
            valorCartaJ2 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador2, escolha-1)));
            printf("%d\n", valorCartaJ2);
            removerPosicao(&jogador2, escolha-1);
        }
    }

    if (valorCartaJ1 > valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 1!\n");
        vetorVitorias[0]++;
    }
    else if (valorCartaJ1 < valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 2!\n");
        vetorVitorias[1]++;
    }
    else printf("A rodada deu empate!\n");
}

```
### Distribuição de cartas aos jogadores
> A função jogarRodada gerencia todo o processo de uma rodada
> Exibe as cartas disponíveis para o jogador.
> Permite que cada jogador escolha uma carta.
> Calcula o vencedor da rodada e atualiza a contagem de vitórias.
> Garante que cada jogador receba 5 cartas aleatórias. Usa topoPilha(&baralho) para pegar uma carta e retiraPilha(&baralho) para removê-la do baralho.
>  Estruturas de dados envolvidas:
> - Pilha baralho → Representa o baralho e permite pegar cartas do topo.
> - Lista j1 e j2 → Recebem as cartas distribuídas para os jogadores.
>   
> No loop principal de rodadas:
>   - Lista j1 e j2 → Manipuladas dentro de jogarRodada.
>   - Vetor numVitorias[2] → Atualizado a cada rodada.
```c
void jogarRodada(int rodada, lista jogador1, lista jogador2, int vetorVitorias[]) {
    int valorCartaJ1, valorCartaJ2;
    printf("\n--- Rodada %d ---\n", rodada + 1);

    for (int i = 0; i < 2; i++) {
        printf("Jogador %d, sua mao: ", i + 1);
        if (!i) mostrarMao(&jogador1, rodada);
        else mostrarMao(&jogador2, rodada);
        
        if (rodada == 4) printf("Você so tem uma carta (1): ");
        else printf("Escolha a carta (1 a %d): ", 5-rodada);
        
        int escolha;
        scanf("%d", &escolha);

        if (!i) {
            valorCartaJ1 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador1, escolha-1)));
            printf("O valor total de sua carta eh: %d\n", valorCartaJ1);
            removerPosicao(&jogador1, escolha-1);
        } else {
            valorCartaJ2 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador2, escolha-1)));
            printf("%d\n", valorCartaJ2);
            removerPosicao(&jogador2, escolha-1);
        }
    }

    if (valorCartaJ1 > valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 1!\n");
        vetorVitorias[0]++;
    }
    else if (valorCartaJ1 < valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 2!\n");
        vetorVitorias[1]++;
    }
    else printf("A rodada deu empate!\n");
}

```

### Distribuição de cartas aos jogadores
> A função jogarRodada gerencia todo o processo de uma rodada
> Exibe as cartas disponíveis para o jogador.
> Permite que cada jogador escolha uma carta.
> Calcula o vencedor da rodada e atualiza a contagem de vitórias.
> Garante que cada jogador receba 5 cartas aleatórias. Usa topoPilha(&baralho) para pegar uma carta e retiraPilha(&baralho) para removê-la do baralho.
>  Estruturas de dados envolvidas:
> - Pilha baralho → Representa o baralho e permite pegar cartas do topo.
> - Lista j1 e j2 → Recebem as cartas distribuídas para os jogadores.
>   
> No loop principal de rodadas:
>   - Lista j1 e j2 → Manipuladas dentro de jogarRodada.
>   - Vetor numVitorias[2] → Atualizado a cada rodada.
```c
void jogarRodada(int rodada, lista jogador1, lista jogador2, int vetorVitorias[]) {
    int valorCartaJ1, valorCartaJ2;
    printf("\n--- Rodada %d ---\n", rodada + 1);

    for (int i = 0; i < 2; i++) {
        printf("Jogador %d, sua mao: ", i + 1);
        if (!i) mostrarMao(&jogador1, rodada);
        else mostrarMao(&jogador2, rodada);
        
        if (rodada == 4) printf("Você so tem uma carta (1): ");
        else printf("Escolha a carta (1 a %d): ", 5-rodada);
        
        int escolha;
        scanf("%d", &escolha);

        if (!i) {
            valorCartaJ1 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador1, escolha-1)));
            printf("O valor total de sua carta eh: %d\n", valorCartaJ1);
            removerPosicao(&jogador1, escolha-1);
        } else {
            valorCartaJ2 = calcularValor(retornarCartaDoIterador(posicaoNaLista(&jogador2, escolha-1)));
            printf("%d\n", valorCartaJ2);
            removerPosicao(&jogador2, escolha-1);
        }
    }

    if (valorCartaJ1 > valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 1!\n");
        vetorVitorias[0]++;
    }
    else if (valorCartaJ1 < valorCartaJ2) {
        printf("O vencedor da rodada foi o Jogador 2!\n");
        vetorVitorias[1]++;
    }
    else printf("A rodada deu empate!\n");
}

```
### Determinação do vencedor final
> Após todas as rodadas, o código verifica quem ganhou mais rodadas:

```c
if (numVitorias[0] > numVitorias[1]) {
    printf("\nO grande vencedor foi o Jogador 1!\n");
} else if (numVitorias[0] < numVitorias[1]) printf("\nO grande vencedor foi o Jogador 2!\n");
else printf("\nO jogo empatou!!!!!\n");

```

## carta.h
> O arquivo carta.h define a estrutura básica das cartas do jogo.
```c
#ifndef CARTA_H
#define CARTA_H

typedef struct carta {
    int valor;  // De 1 a 13 (Ás a Rei);
    int naipe;  // 1 = Ouros, 2 = Espadas, 3 = Copas, 4 = Paus;
} Carta;

#endif
```


## lista.h
> No arquivo lista.h, temos a definição de uma lista encadeada para armazenar as cartas dos jogadores.
> Estruturas de dados envolvidas:
> - struct no → Define um nó da lista encadeada, contendo uma Carta e um ponteiro para o próximo nó.
> - struct lista → Define a lista propriamente dita, armazenando um ponteiro para o primeiro nó e o tamanho da lista.
```c
#ifndef LISTA_H
#define LISTA_H

#define TAMANHO_MAO 5
#include "carta.h"

struct no{
    Carta item;
    struct no *next, *prev;
};

typedef struct no No;
typedef struct {
    No *sentinela;
    unsigned quantidade;
} lista;

typedef struct iterador{
    No *posicao;
    lista *estrutura;
} Iterador;

void inicializaLista(lista *f);
void destroiLista(lista *f);
int vaziaLista(lista *f);
unsigned tamanhoLista(lista *f);
void insereInicio(lista *f, Carta dado);
void insereFim(lista *f, Carta dado);
int removerInicio(lista *f);
int removerFim(lista *f);
int removerPosicao(lista *f, int pos);
Iterador posicaoNaLista(lista *f, int pos);
int proximo(Iterador* i);
int acabou(Iterador i);
void mostrarMao(lista *f, int rodada);
Carta retornarCartaDoIterador(Iterador i);
//int primeiro(fila *f, int *dado);

#endif
```




## pilha.h
> O arquivo pilha.h define a estrutura de pilha, que é utilizada para armazenar e gerenciar o baralho do jogo. Permitindo operações como inicialização, embaralhamento, inserção e remoção de cartas.
> O código implementa uma pilha baseada em vetor para representar o baralho de cartas.
> Estruturas de dados envolvidas:
> - struct pilha → Define a pilha, que contém um vetor dinâmico de cartas e um índice topo que indica a posição do último elemento.

```c
#ifndef PILHA_H
#define PILHA_H

#define TAMANHO_MAXIMO_PILHA 52

#include "carta.h"

typedef struct pilha {
    unsigned topo;
    Carta *vetor;
} Pilha;

void inicializaPilha(Pilha *p);
void embaralharPilha(Pilha *p);
int vaziaPilha(Pilha *p);
int cheiaPilha(Pilha *p);
unsigned tamanhoPilha(Pilha *p);
void inserePilha(Pilha *p, Carta item);
void retiraPilha(Pilha *p);
Carta topoPilha(Pilha *p);
void destruirPilha(Pilha *p);

#endif
```

### Todas as fuções das APIs foram devidamente implementadas em seus respectivos arquivos lista.c e pilha.c



