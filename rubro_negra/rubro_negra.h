#ifndef TREE_H
#define TREE_H

#define preto 0
#define vermelho 1

typedef struct no
{
	int chave;
	int cor;
	struct no * pai;
	struct no *dir, *esq;
} NO;

typedef NO* t_arvore;

void cria_arvore(t_arvore *A);
void cria_raiz(t_arvore *A,NO* pai, int chave);
void recolorir(NO* pai, NO* tio, NO* avo);
NO* rotacao_direita(NO** p, NO **root);
NO* rotacao_esquerda(NO** p, NO** root);
NO* rotacao_esquerda_direita(NO **p, NO ** root);
NO* rotacao_direita_esquerda(NO** p , NO **root);
void insere(t_arvore *root, int chave);
NO* busca(t_arvore A, int chave);
NO* sucessor(t_arvore A, int chave);
NO* predecessor(t_arvore A, int chave);
NO* maximo(t_arvore A);
NO* minimo(t_arvore A);
void visitado(t_arvore A);
void emOrdem(t_arvore A);
void preOrdem(t_arvore A);
void posOrdem(t_arvore A);
void apaga_arvore(t_arvore *A);

#endif