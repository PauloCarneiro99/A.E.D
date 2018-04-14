#include <stdio.h>
#include <stdlib.h>

/*
	Apesar que a implementacao com vetores seria algo mais trivial, reallocando na hora de inserir e remover, modificando apenas o tamanho e o ultimo elemento
	escolhi essa abordagem para que assim as operacoes e estruturas de piha fiquem mais semelhantes as de fila
*/


//seta os ponteiros da pilha para NULL
void cria_pilha(pilha *p){
	p->topo = NULL;
	p->ini = NULL;
}

//retorna quantos elementos estao empilhados
int contador(pilha p){
	int cont = 0;
	NO *aux = p.ini;
	while(aux){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

//retorna 1 caso a pilha esteja vazia e 0 caso o contrario
int pilha_vazia(pilha *p){
	if(p->topo == NULL)
		return 1;
	return 0;
}

//insere o elemnto no final da pilha e atualiza os ponteiros
void push(pilha *p, elem chave){
	NO * temp = malloc(sizeof(NO));
	temp->prox = NULL;
	temp->chave = chave;
	if(pilha_vazia(p)){
		temp->ant = NULL;
		p->topo = temp;
		p->ini = temp;
	}else{
		p->topo->prox = temp;
		temp->ant = p->topo;
		p->topo = temp;
	}
}

//retira o elemento do topo
void pop(pilha *p){
	NO* aux = p->topo;
	if(aux != NULL){
		p->topo = aux->ant;
		if(aux->ant != NULL)
			aux->ant->prox = NULL;
		else
			p->ini = NULL;
		free(aux);
	}
}


//retorna o NO do topo
NO* topo(pilha p){
	return p.topo;
}

//limpa a pilha
void clear(pilha *p){
	while(!pilha_vazia(p))
		pop(p);
}

void imprime_pilha(pilha p){
	NO*aux = p.ini;
	while(aux){
		printf("%d\n",aux->chave);
		aux = aux->prox;
	}
}