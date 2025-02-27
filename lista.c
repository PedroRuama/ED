#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void inicializaLista(lista *f){
  struct no *n = (struct no*) malloc(sizeof(struct no));
  if (n == NULL) {
    printf("Erro ao alocar memória para a lista\n");
    exit(1); 
  }
  n->next = n->prev = f->sentinela = n;
  f->quantidade = 0;
}

void destroiLista(lista *f){
  while(!vaziaLista(f))
    removerInicio(f);
  free(f->sentinela);
  f->quantidade = 0;
}

int vaziaLista(lista *f){
  return f->sentinela->next == f-> sentinela;
  // return f->quantidade == 0;
}

unsigned tamanhoLista(lista *f){
  return f->quantidade;
}

void insereInicio(lista *f, Carta dado){
  No *n = (No*)malloc(sizeof(No));
  n->item = dado;
  n->next = f->sentinela->next;
  n->prev = f->sentinela;
  f->sentinela->next = n;
  n->next->prev = n;
  f->quantidade++;
}

void insereFim(lista *f, Carta dado){
  No *n = (No*)malloc(sizeof(No));
  n->item = dado;
  n->next = f->sentinela;
  n->prev = f->sentinela->prev;
  f->sentinela->prev = n;
  n->prev->next = n;
  f->quantidade++;
}

int removerInicio(lista *f){
  No *n = f->sentinela->next;
  if(n != f->sentinela){
    n->next->prev = n->prev;
    n->prev->next = n->next;
    free(n);
    f->quantidade--;
    return 1;
  }
  return 0;
}

int removerFim(lista *f){
  No *n = f->sentinela->prev;
  if(n != f->sentinela){
    n->next->prev = n->prev;
    n->prev->next = n->next;
    free(n);
    f->quantidade--;
    return 1;
  }
  return 0;
}

int proximo(Iterador* i) {
  if(!acabou(*i)) {
    i->posicao = i->posicao->next;
    return 1;
  }
  return 0;
}

int acabou(Iterador i) {
  return i.posicao == i.estrutura->sentinela;
}

Iterador posicaoNaLista(lista *f, int pos) {
	Iterador i;
	i.posicao = f->sentinela->next;
	for (int j = 0; j < pos; j++) {
    proximo(&i);
  }
  i.estrutura = f;
  return i;
}

int removerPosicao(lista *f, int pos) {
  No *n = posicaoNaLista(f, pos).posicao;
  if(n != f->sentinela){
  	n->next->prev = n->prev;
  	n->prev->next = n->next;
  	free(n);
  	f->quantidade--;
		return 1;
  }
	return 0;
}

void mostrarMao(lista *f, int rodada) {
  No *n = f->sentinela->next;
  for (int i = 0; i < TAMANHO_MAO - rodada; i++) {
    printf("(%d de ", n->item.valor);
    switch (n->item.naipe) {
      case 1: printf("Ouros"); break;
      case 2: printf("Espadas"); break;
      case 3: printf("Copas"); break;
      case 4: printf("Paus"); break;
    }
    printf(") ");
    n = n->next;
  }
  printf("\n");
}

Carta retornarCartaDoIterador(Iterador i) {
  return i.posicao->item;
}

