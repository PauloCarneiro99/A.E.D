#ifndef PILHA_H
#define PILHA_H

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;	
}NO;

typedef struct 
{
	NO *topo;
	NO* ini;
}pilha;

void cria_pilha(pilha *p);
int contador(pilha p);
int pilha_vazia(pilha *p);
void push(pilha *p, elem chave);
void pop(pilha *p);
NO* topo(pilha p);
void clear(pilha *p);
void imprime_pilha(pilha p);


#endif