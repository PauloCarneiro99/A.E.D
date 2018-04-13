#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct no{
	struct no *dir, *esq;
	elem chave;
}NO;

void cria_raiz(NO * raiz, elem chave){
	raiz = malloc(sizeof(NO));
	raiz->dir = NULL;
	raiz->esq = NULL;
	raiz->chave = chave;
}

void insere(NO *raiz, elem chave){
	NO * aux = raiz;
	while(aux){
		if(aux->chave > chave)
			aux = aux->dir;
		else if(aux->chave < chave)
			aux = aux->esq;
		else
			printf("chave repetida\n");
	}
	cria_raiz(aux, chave);
}

NO* busca(NO *raiz, elem chave){
	NO* aux = raiz;
	while(aux != NULL && aux->chave != chave){
		if(aux->chave > chave)
			aux = aux->dir;
		else if(aux->chave < chave)
			aux = aux->esq;
	}
	return aux; //retorna NULL se a chave buscada n estiver inserida, retorna o NO se ela estiver
}


//nao acho que esta funcao esteja funcionando
void apaga_no(NO *raiz, elem chave){
	NO *aux = busca(raiz,chave);
	if(aux == NULL) //chave nao esta inserida
		return;
	if(aux->dir == NULL && aux->esq == NULL) //removendo NO folha
		free(aux);
	else if(aux->dir != NULL || aux->esq != NULL){ //removendo NO semi folha
		NO*temp;
		temp = aux;
		if(aux->dir != NULL){
			aux = aux->esq;
		}else{
			aux = aux->dir;
		}
		free(temp);
	}else{ //removendo no , utilizando a estrategia de pegar o menor filho pela direita
		NO * p = aux;
		p = aux->dir;
		while(p->esq != NULL)
			p = p->esq;
		aux->chave = p->chave;
		free(p);
	}
}

void preOrdem(NO *root){
	if(root != NULL){
		printf("%d ", root->chave);
		preOrdem(root->esq);
		preOrdem(root->dir);
	}
}

void emOrdem(NO *root){
	if(root != NULL){
		emOrdem(root->esq);
		printf("%d ", root->chave);
		emOrdem(root->dir);
	}
}

void posOrdem(NO *root){
	if(root != NULL){
		posOrdem(root->esq);
		posOrdem(root->dir);
		printf("%d ", root->chave);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}