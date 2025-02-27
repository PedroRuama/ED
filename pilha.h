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