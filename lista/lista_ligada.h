#ifndef LISTA_H
#define LISTA_H

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;
}NO;

typedef struct 
{
	NO *ini, *fim;
}lista;

void inicializa_lista(lista *l);
int lista_vazia(lista l);
void insere_fim(lista *l, int chave);
void insere_inicio(lista *l, int chave);
void insere_ordenado(lista *l, elem chave);
NO* procura(lista l, int chave);
void remove_lista(lista *l, elem chave);
void print_lista(lista l);


#endif