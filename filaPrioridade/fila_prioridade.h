#ifndef FILA_PRIORIDADE
#define FILA_PRIORIDADE


typedef struct no{
	int peso;
	int v1;
	struct no *prox;
}NO;

typedef struct 
{
	NO* inicio;
	NO*fim;	
}fila;

void cria_fila(fila *l);
void insere(fila* l, int v1, int peso);
int empty(fila *l);
NO* front(fila *l);
void pop(fila *l);
void clear(fila *l);
void print_fila(fila *l);


#endif
