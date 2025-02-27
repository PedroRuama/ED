#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"
#include "lista.h"

int calcularValor(Carta carta) {
    return carta.valor * carta.naipe;
}

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

int main() {
    srand(time(NULL));

    Pilha baralho;
    inicializaPilha(&baralho);
    embaralharPilha(&baralho);

    lista j1, j2;
    int numVitorias[2];
    numVitorias[0] = 0;
    numVitorias[1] = 0;
    inicializaLista(&j1);
    inicializaLista(&j2);

    for (int i = 0; i < TAMANHO_MAO; i++) {
        Carta carta = topoPilha(&baralho);
        if (carta.valor != -1 && carta.naipe != -1) {
            insereInicio(&j1, carta);
            retiraPilha(&baralho);
        }
    }
    for (int i = 0; i < TAMANHO_MAO; i++) {
        Carta carta = topoPilha(&baralho);
        if (carta.valor != -1 && carta.naipe != -1) {
            insereInicio(&j2, carta);
            retiraPilha(&baralho);
        }
    }

    for (int i = 0; i < 5; i++)
        jogarRodada(i, j1, j2, numVitorias);

    if (numVitorias[0] > numVitorias[1]) {
        printf("\nO grande vencedor foi o Jogador 1!\n");
    } else if (numVitorias[0] < numVitorias[1]) printf("\nO grande vencedor foi o Jogador 2!\n");
    else printf("\nO jogo empatou!!!!!\n");

    destruirPilha(&baralho);
    destroiLista(&j1);
    destroiLista(&j2);

    return 0;
}






