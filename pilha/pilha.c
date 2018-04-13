#include <stdio.h>
#include <stdlib.h>

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

void cria_pilha(pilha *p){
	p->topo = NULL;
	p->ini = NULL;
}

int contador(pilha p){
	int cont = 0;
	NO *aux = p.ini;
	while(aux){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

int pilha_vazia(pilha *p){
	if(p->topo == NULL)
		return 1;
	return 0;
}

void push(pilha *p, elem chave){
	NO * temp = malloc(sizeof(NO));
	temp->prox = NULL;
	temp->chave = chave;
	if(pilha_vazia(p)){
		temp->ant = NULL;
		p->topo = temp;
		p->ini = temp;
	}else{
		p->topo->prox = temp;
		temp->ant = p->topo;
		p->topo = temp;
	}
}

void pop(pilha *p){
	NO* aux = p->topo;
	if(aux != NULL){
		p->topo = aux->ant;
		if(aux->ant != NULL)
			aux->ant->prox = NULL;
		else
			p->ini = NULL;
		free(aux);
	}
}

NO* topo(pilha p){
	return p.topo;
}

void clear(pilha *p){
	while(!pilha_vazia(p))
		pop(p);
}

void imprime_pilha(pilha p){
	NO*aux = p.ini;
	while(aux){
		printf("%d\n",aux->chave);
		aux = aux->prox;
	}
}

int main(int argc, char const *argv[])
{
	
	pilha p;
	cria_pilha(&p);
	push(&p, 5);
	push(&p, 6);
	push(&p, 7);
	push(&p, 8);
	push(&p, 9);
	pop(&p);
	imprime_pilha(p);
	clear(&p);
	return 0;
}