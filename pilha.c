#include "pilha.h"
#include <stdlib.h>

void inicializaPilha(Pilha *p) {
    p->topo = 0;
    p->vetor = (Carta*)malloc(TAMANHO_MAXIMO_PILHA*(sizeof(Carta)));
    if (!p->vetor) { 
        exit(1); 
    }
    for (int i = 0; i < 52; i++) {
        p->vetor[i].valor = (i%13)+1;
        if (0 <= i && i <= 12) p->vetor[i].naipe = 1;
        else if (13 <= i && i <= 25) p->vetor[i].naipe = 2;
        else if (26 <= i && i <= 38) p->vetor[i].naipe = 3;
        else if (39 <= i && i <= 51) p->vetor[i].naipe = 4;
        p->topo = TAMANHO_MAXIMO_PILHA;
    }
}

void embaralharPilha(Pilha *p) {
    for (int i = TAMANHO_MAXIMO_PILHA - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = p->vetor[i];
        p->vetor[i] = p->vetor[j];
        p->vetor[j] = temp;
    }
}

int vaziaPilha(Pilha *p) {
    return p->topo == 0;
}

int cheiaPilha(Pilha *p) {
    return p->topo == TAMANHO_MAXIMO_PILHA;
}

unsigned tamanhoPilha(Pilha *p) {
    return p->topo;
}

void inserePilha(Pilha *p, Carta item) {
    if(p->vetor != NULL && !cheiaPilha(p)) {
        p->vetor[p->topo] = item;
        p->topo++;
    }
}

void retiraPilha(Pilha *p) {
    if(p->vetor != NULL && !vaziaPilha(p)) {
        p->topo--;
    }
}

Carta topoPilha(Pilha *p) {
    if(p->vetor != NULL && !vaziaPilha(p)) {
        return p->vetor[p->topo-1];
    }
    Carta erro;
    erro.valor = -1;
    erro.naipe = -1;
    return erro;
}

void destruirPilha(Pilha *p) {
    free(p->vetor);
    p->vetor = NULL;
}