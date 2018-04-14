#ifndef FILA_H
#define FILA_H

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;	
}NO;

typedef struct 
{
	NO *ini;
	NO *fim;
}FILA;

void push(FILA *f, elem chave);
void pop(FILA *f);

#endif