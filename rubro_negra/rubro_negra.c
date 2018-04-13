#include <stdio.h>
#include <stdlib.h>
#include "rubro_negra.h"

//inicializando a arvore como vazia
void cria_arvore(t_arvore *A){
	*A = NULL;
}

//mallocando o novo NO e setando seus atributos.odo NO novo eh inserido com a cor vermelha para evitar ao maximo o desbalanceamento da arvore 
void cria_raiz(t_arvore *A,NO* pai, int chave){
	*A = malloc(sizeof(NO));
	(*A)->esq = NULL;
	(*A)->dir = NULL;
	(*A)->cor = vermelho;
	(*A)->chave = chave;
	(*A)->pai = pai;
}

//chamada quando um no eh inserido, o novo no possui cor vermelha, e para respeitar a propriedade que um no vermelho deve possuir um pai preto
//se o pai e o tio do NO forem vermelhos eh possivel recolori-los para vermelho para evitar que a arvore seja desbalanceada
//caso o contrario essa funcao nao eh possivel, torna-se necessario fazer uma rotacao
void recolorir(NO* pai, NO* tio, NO* avo){
	pai->cor = preto;
	tio->cor = preto;
	avo->cor = vermelho;
}

NO* rotacao_direita(NO** p, NO **root){
	NO *q, *temp, *pai;
	q = (*p)->esq;
	temp = q->dir;
	q->dir = *p;
	if(temp != NULL)
		temp->pai = *p;
	(*p)->esq = temp;
	pai = (*p)->pai;
	if((*p)->chave == (*root)->chave)
		*root = q;
	else{
		if((*p)->pai->esq->chave == (*p)->chave){
			(*p)->pai->esq = q;
		}
		else
			(*p)->pai->dir = q;
	}
	(*p)->pai = q;
	q->pai = pai;
	return q;
}

NO* rotacao_esquerda(NO** p, NO** root){
	NO *q, *temp, *pai;
	q = (*p)->dir;
	temp = q->esq;
	q->esq = *p;
	if(temp != NULL)
		temp->pai = *p;
	(*p)->dir = temp;
	pai = (*p)->pai;
	if((*p)->chave == (*root)->chave)
		*root = q;
	else{
		if((*p)->pai->esq->chave == (*p)->chave)
			(*p)->pai->esq = q;
		else
			(*p)->pai->dir = q;
	}
	(*p)->pai = q;
	q->pai = pai;
	return q;
}

NO* rotacao_esquerda_direita(NO **p, NO ** root){
	NO* aux = rotacao_esquerda(p, root);
	aux = rotacao_direita(&aux->pai, root);
	return aux;
}

NO* rotacao_direita_esquerda(NO** p , NO **root){
	NO* aux = rotacao_direita(p, root);
	aux = rotacao_esquerda(&aux->pai, root);
	return aux;
}

void insere(t_arvore *root, int chave){
	NO**p = root;
	NO* pai = NULL;
	while(*p != NULL){
		if(chave > (*p)->chave){
			pai = *p;
			p = &(*p)->dir;			
		} 
		else{
			pai = *p;
		 	p = &(*p)->esq;
		}
	} 	
	cria_raiz(p, pai, chave); //cheguei na posicao que o no deve ser inserido
	while((*p)->chave != (*root)->chave && (*p)->cor == vermelho){ 
	//checando se eh necessario recolorir ou rotacionar os NOs para manter a arvore balanceada e seguindo as propriedades de uma ABB
		NO * pos;
		if((*p)->pai->cor == preto) //se o pai do novo NO for preto nao eh necessario fazer nada
			break;
		if((*p)->pai->pai->esq == (*p)->pai){ // se o pai for filho esquerdo
			NO* aux = (*p)->pai->pai->dir; //pegando o tio
			if(aux != NULL && aux->cor == vermelho){// como o pai e o tio sao vermelhos eh possivel recolori-los mantendo o balancemaneto e respeitando as propriedades
				//recolorir o pai e o tio viram pretos e o avo vira vermelho, atualiza o p para o avo
				recolorir((*p)->pai, aux, (*p)->pai->pai);
				p = &(*p)->pai->pai; //atoalizando o p para seu avo que acaba de ser recolorido para vermelho, roda o loop novamente para ver se alteracoes precisam ser feitas
			}else if(*p == (*p)->pai->dir){ //caso em que os nos estao em posicao de zig zag, necessario fazer uma rotacao dupla e depois recolori os NOs em suas novas posicoes
					pos = rotacao_esquerda_direita(&(*p)->pai, root);
					p = &pos; //atualizando o p
					(*p)->dir->cor = vermelho;
					(*p)->esq->cor = vermelho;
					(*p)->cor = preto;
			}else{//caso de zig zig . Faz uma rotacao simples e recolori os NOs em sua nova posicao
					pos = rotacao_direita(&(*p)->pai->pai, root);
					p = &pos; //atualizando o p
					(*p)->dir->cor = vermelho;
					(*p)->esq->cor = vermelho;
					(*p)->cor = preto;
			}
		}else{
			NO* aux = (*p)->pai->pai->esq;
			if(aux != NULL && aux->cor == vermelho){
				//recolorir o pai e o tio viram pretos e o avo vira vermelho, atualiza o p para o avo
				recolorir((*p)->pai, aux, (*p)->pai->pai);
				p = &(*p)->pai->pai;
			}else if(*p == (*p)->pai->dir){//caso de zig zig portando eh necessario fazer uma rotacao simples e depois recolorir os NOs em suas novas posicoes
					pos = rotacao_esquerda(&(*p)->pai->pai, root);
					p = &pos; //atualizando o p
					(*p)->dir->cor = vermelho;
					(*p)->esq->cor = vermelho;
					(*p)->cor = preto;
			}else{//caso que os NOs estao em posicao de zig zag
					pos = rotacao_direita_esquerda(&(*p)->pai, root); //mudar para zig zag
					p = &pos; //atualizando o p
					(*p)->dir->cor = vermelho;
					(*p)->esq->cor = vermelho;
					(*p)->cor = preto;
			}
		}
	}
	(*root)->cor = preto;
}
//Busca uma chave percorrendo a arvore. Faz log(n) operacoes ja que a arvore esta balanceada e respeita as propriedades de uma arvore binaria de busca
NO* busca(t_arvore A, int chave){
	if(A == NULL) return NULL;
	else if(A->chave > chave) return busca(A->esq, chave);
	else if(A->chave < chave) return busca(A->dir, chave);
	else return A;
}
//o sucessor eh o menor NO que possui a chave maior que a chave buscada
//retorna nulo caso a chave buscada nao esteja inserida na arvore
//caso o NO possua filho a direita o sucessor sera o filho mais a esquerda desse filho a direitaa direita
//caso nao possua filho, checar o oau, se ele for maior que a chave ele eh o sucessor caso o contrario o NO nao possui sucessor
NO* sucessor(t_arvore A, int chave){
	NO* p = busca(A, chave);
	if(p == NULL)
		return p;
	if(p->dir == NULL){
		if(p->pai->chave > chave)
			return p->pai;
		return NULL;
	}
	p = p->dir;
	while(p->esq != NULL) p = p->esq;
	return p;
}
//o predecessor eh o maior no que possui a chave menor que a busca
//retorna nulo caso a chave buscada nao esteja inserida na arvore
//se o NO com a chave buscada possuir filho a esquerda entao o predecessor eh o filho mais a direita possivel desse filho a esquerda
//caso nao tenha filho a esquerda veja se o pai do NO eh menor que ele, se sim o pai eh o predecessor, caso o contrario o NO nao possui predecessor 
NO* predecessor(t_arvore A, int chave){
	NO*p = busca(A, chave);
	if(p == NULL) return p;
	if(p->esq == NULL){
		if(p->pai->chave < chave)
			return p->pai;
		return NULL;
	}
	p = p->esq;
	while(p->dir != NULL) p = p->dir;
	return p;
}
//como a arvore rubro negra mantem as propriedades de uma arvore binaria de busca o maior elemento eh o filho mais a direita da arvore
//retorna NULL caso a arvore esteja vazia
NO* maximo(t_arvore A){
	if(A == NULL)
		return NULL;
	NO* p = A;
	while(p->dir != NULL) p = p->dir;
	return p;
}
//como a arvore rubro negra mantem as propriedades de uma arvore binaria de busca o menor elemento eh o filho mais a esquerda da arvore
//retorna NULL caso a arvore esteja vazia
NO* minimo(t_arvore A){
	if(A == NULL)
		return NULL;
	NO* p = A;
	while(p->esq != NULL) p = p->esq;
	return p;
}

void visitado(t_arvore A){
	printf("%d ", A->chave);
}
//Percurso Em Ordem
void emOrdem(t_arvore A){
	if(A != NULL){
		emOrdem(A->esq);
		visitado(A);
		emOrdem(A->dir);
	}
}

//Percuso em Pre Ordem
void preOrdem(t_arvore A){
	if(A != NULL){
		visitado(A);
		preOrdem(A->esq);
		preOrdem(A->dir);
	}
}

//Percurso em Pos Ordem
void posOrdem(t_arvore A){
	if(A != NULL){
		posOrdem(A->esq);
		posOrdem(A->dir);
		visitado(A);
	}
}

//Funcao que da free em todos os NOs da arvore desalocando a memoria armazenada dinamicamente
//similar ao Percurso Pos Ordem, porem ao inves de printar, da um free, desalocando o NO
void apaga_arvore(t_arvore *A){
	if(*A != NULL){
		apaga_arvore(&(*A)->esq);
		apaga_arvore(&(*A)->dir);
		free(*A);
	}
}