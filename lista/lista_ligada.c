#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

//setando os ponteiros da lista como NULL
void inicializa_lista(lista *l){
	l->ini = NULL;
	l->fim = NULL;
}

//retorna 1 se a lista estiver vazia e 0 caso o contrario
int lista_vazia(lista l){
	if(l.fim == NULL)
		return 1;
	return 0;
}

//insere o elemento na ultima posicao da lista
void insere_fim(lista *l, int chave){
	NO* temp = (NO*)malloc(sizeof(NO));
	temp->prox = NULL;
	temp->ant = l->fim;
	temp->chave = chave;
	l->fim = temp;
	if(l->ini == NULL)
		l->ini = temp;
}

//insere o elemento na primeira posicao da lista
void insere_inicio(lista *l, int chave){
	NO* temp = (NO*)malloc(sizeof(NO));
	temp->prox = l->ini;
	temp->ant = NULL;
	temp->chave = chave;
	l->ini = temp;
	if(l->fim == NULL)
		l->fim = temp;
}

//mantem a lista de elementos ordenada, inserindo o novo NO ja na sua posicao correta
void insere_ordenado(lista *l, elem chave){
	NO*temp = malloc(sizeof(NO));
	temp->chave = chave;
	if(!lista_vazia(*l)){
		if(chave == l->ini->chave){ //evitando inserir elemento repetido
			return;
		}
		if(chave < l->ini->chave){
			l->ini->ant = temp;
			temp->ant = NULL;
			temp->prox = l->ini;
			l->ini = temp;
		}	
		else{
			NO* aux = l->ini;
			while(aux->prox != NULL && aux->prox->chave < chave){
				aux = aux->prox;
			}
			if(aux->prox != NULL)
				if(aux->prox->chave == chave){ //tentando inserir uma chave igual
					return ;
				}
			if(aux->prox == NULL){
				temp->prox = NULL;	
				l->fim = temp;
			}else{
				temp->prox = aux->prox;
				aux->prox->ant = temp;	
			}
			aux->prox = temp;
			temp->ant = aux;
		}
	}else{ //inserindo o primeiro elemento
		l->ini = l->fim = temp;
		temp->ant = NULL;
		temp->prox = NULL;
	}
}


NO* procura(lista l, int chave){
	NO* temp;
	temp = l.ini;
	while(temp != NULL){
		if(temp->chave == chave)
			return temp;
		temp = temp->prox;
	}
	return NULL;
}

void remove_lista(lista *l, elem chave){
	NO* temp = procura(*l, chave);
	if(temp == NULL)
		return; //tentando remover algo que nao esta inserido na lista
	if(temp == l->ini){
		if(temp->prox != NULL){
			temp->prox->ant = NULL;
			l->ini = temp->prox;
			free(temp);
		}else{
			l->ini = NULL;
			l->fim = NULL;
			free(temp);
		}
	}
	else if(temp == l->fim){
		if(temp->ant != NULL){
			temp->ant->prox = NULL;
			l->fim = temp->ant;
			free(temp);
		}else{
			l->ini = NULL;
			l->fim = NULL;
			free(temp);
		}
	}else{
		if(temp->ant != NULL)
			temp->ant->prox = temp->prox;
		if(temp->prox !=NULL)
			temp->prox->ant = temp->ant;
		free(temp);
	}
}

void print_lista(lista l){
	NO*p = l.ini;
	while(p != NULL){
		printf("%d ",p->chave);
		p = p->prox;
	}
	printf("\n");
}