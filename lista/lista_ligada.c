#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	struct no *prox, *ant;
	int chave;
}NO;

typedef struct
{
	NO inicio, fim;
}lista;

void inicializa_lista(lista *l){
	l->inicio = NULL;
	l->fim = NULL;
}

int lista_vazia(lista l){
	if(l.fim == NULL)
		return 1;
	return 0;
}

void insere_fim(lista *l, int chave){
	NO* temp = (NO*)malloc(sizeof(NO));
	temp->prox = NULL;
	temp->ant = l->fim;
	temp->chave = chave;
	l->fim = temp;
	if(l->inicio == NULL)
		l->inicio = temp;
}

void insere_inicio(lista *l, int chave){
	NO* temp = (NO*)malloc(sizeof(NO));
	temp->prox = l->inicio;
	temp->ant = NULL;
	temp->chave = chave;
	l->inicio = temp;
	if(l->fim == NULL)
		l->fim = temp;
}

//mantem a lista de elementos ordenada, inserindo o novo NO ja na sua posicao correta
void insere_ordenado(lista *l, int chave){
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
				if(aux->prox->chave == chave){ //tentando inserir uma chave igual, somente altero os pesos
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
	temp = l.inicio;
	while(temp != NULL){
		if(temp->chave == chave)
			return temp;
		temp = temp->prox;
	}
	return NULL;
}

void remove(lista *l, NO* n){
	if(l->inicio == n)
		l->inicio = n->prox;
	if(l->fim == n)
		l->fim = n->ant;
	if(n->prox != NULL)
		n->prox->ant = n->ant;
	if(n->ant != NULL)
		n->ant->prox = n->prox;
	free(n);
}

void remove_lista(lista *l, elem chave){
	NO* temp = busca(*l, chave);
	if(temp == NULL)
		return; //tentando remover algo que nao esta inserido na lista
	l->tam -= 1;
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