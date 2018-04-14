#ifndef ABB_H
#define ABB_H

typedef int elem;

typedef struct no{
	struct no *dir, *esq;
	elem chave;
}NO;
	
typedef NO* t_arvore;


void cria_arvore(t_arvore *A);
void insere(t_arvore *A, int chave);
int busca(t_arvore A, int chave);
void encontraMaxMin(NO* A, NO **R);
void apaga(t_arvore *A, int C);
void visitado(t_arvore A);
void emOrdem(t_arvore A);
void preOrdem(t_arvore A);
void posOrdem(t_arvore A);


#endif