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
