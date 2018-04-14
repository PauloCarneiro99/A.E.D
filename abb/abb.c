#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void cria_arvore(t_arvore *A){
	*A = NULL;
}

//malloca o novo NO, seta o ponteiro para o filho da direita e para a esquerda como NULL, e seta a chave do NO
void cria_raiz(t_arvore *A, int chave){
	(*A) = (NO*)malloc(sizeof(NO));
	(*A)->chave = chave;
	(*A)->dir = NULL;
	(*A)->esq = NULL;
}

//Acha a posicao na qual o NO deve ser inserida de modo interativo, caminhando pela arvore da seguinte forma, se a
//chave do NO atual for maior que a chave a ser inserida, desco para a dir, caso contrario desco para a esquerda
//quando cheguei em uma posicao nula, sgnifica que tenho que criar o novo NO nessa posicao
void insere(t_arvore *A, int chave){
	NO **p;
	p = A;
	while(*p != NULL){
		if((*p)->chave < chave)
			p = &(*p)->dir;
		else if((*p)->chave > chave)
			p = &(*p)->esq;
		else{
			printf("Chave existente\n");
			return ;
		}
	}
	cria_raiz(p, chave);
}

//caminho pela arvore enquanto nao achei a chave que estava buscando e enquanto o NO aux for diferente de NULL
//retorno aux, se nao achei o NO aux vai estar com valor NULL, caso o contrario retorno um ponteiro para esse NO
int busca(t_arvore A, int chave){
	if(A == NULL) return 0;
	if(A->chave == chave) return 1;
	if(A->chave < chave) return busca(A->dir, chave);
	if(A->chave > chave) return busca(A->esq, chave);
	else return 0;
}

//Funcao que recebe um NO e encontra o maior filho para a esquerda ou o menor filho para a direita
//funcao cahamda na hora da remocao, quando um NO possui dois filhos
void encontraMaxMin(NO* A, NO **R) {
    if ((*R)->dir != NULL)
        encontraMaxMin(A, &(*R)->dir);
    else {
        A->chave = (*R)->chave;
        A = (*R);
        (*R) = (*R)->esq;
        free(A);
    }
}


void apaga(t_arvore *A, elem C){
    NO* p;
    if (*A == NULL)
    	return;
    else{
        if (C < (*A)->chave)
            apaga(&(*A)->esq, C);
        else if (C > (*A)->chave)
            apaga(&(*A)->dir, C);
        else{ //Achou o No que que deve ser apagado
            if ((*A)->dir == NULL){ //nao tem filho para direita entao basta subir com o filho da esquerda e dar free
                p = *A;
                (*A) = (*A)->esq;
                free(p);
            }else{
                if ((*A)->esq == NULL){ //nao tem o filho da esquerda, basta subir o filho da direita e dar free
                    p = *A;
                    (*A) = (*A)->dir;
                    free(p);
                } else //tem os dois filhos, acha substitui o NO pelo maior filho pela esquerda ou pelo menor da direita, assim mantem-se as propriedades da ABB
                    encontraMaxMin(*A, &(*A)->dir);
            }
        }
    }
}

void visitado(t_arvore A){
	printf("%d ", A->chave);
}

void emOrdem(t_arvore A){
	if(A != NULL){
		emOrdem(A->esq);
		visitado(A);
		emOrdem(A->dir);
	}
}

void preOrdem(t_arvore A){
	if(A != NULL){
		visitado(A);
		preOrdem(A->esq);
		preOrdem(A->dir);
	}
}

void posOrdem(t_arvore A){
	if(A != NULL){
		posOrdem(A->esq);
		posOrdem(A->dir);
		visitado(A);
	}
}