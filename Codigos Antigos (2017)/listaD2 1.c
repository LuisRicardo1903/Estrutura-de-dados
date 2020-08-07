#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *ant, *prox;
} CelulaD;

CelulaD *inserirD(int valor, CelulaD *l) {
	CelulaD *novo, *p, *r;
	novo = (CelulaD *)malloc(sizeof(CelulaD));
	novo->dado = valor;
	novo->ant = NULL;
	novo->prox = NULL;
	
	if (!l) return novo;
	
	//garante que a lista esteja no inicio
	for (;l->ant; l = l->ant);
	
	for (r = NULL, p = l; p && valor > p->dado; r = p, p = p->prox);
		
	if (!r) { //elemento serah inserido no inicio
		novo->prox = l;
		l->ant = novo;
		return novo;
	} 
	//elemento serah inserido no final
	r->prox = novo;
	novo->ant = r;
	if (p) { //elemento serah inserido no meio
		novo->prox = p;
		p->ant = novo;
	}
	return l;
}

void exibirR(CelulaD *l) {
	if (!l) {
		printf("Lista Vazia\n\n");
	} else {
		for (;l->ant;l = l->ant);
		
		for (;l;l = l->prox){
			printf("%d\t", l->dado);
		}
		printf("%d\n");
	}
}

/*
 * método que recebe um inteiro indicando o inicio de uma sequencia,
 * outro inteiro indicando o final de uma sequencia e uma lista duplamente
 * encadeada. Em seguida, os elementos da sequência na lista devem
 * ser exibidos
 */
void mostraSequenciaD(int inicio, int fim, CelulaD *l) {}

/*
 * método que recebe uma lista duplamentente encadeada e 
 * a transforma em uma lista duplamente encadeada circular.
 * ao final, a lista é retornada
 */
CelulaD *transformaCircularD(CelulaD *l) {}

/*
 * método que recebe uma lista duplamentente encadeada e 
 * libera memória de cada elemento da lista.
 * ao final, NULL é retornado
 */
CelulaD *destroiD(CelulaD *l) {}

/*
 * método que recebe um inteiro indicando o inicio de uma sequencia,
 * outro inteiro indicando o final de uma sequencia e uma lista duplamente
 * encadeada. Os elementos da sequência na lista devem ser removidos.
 * ao final a lista alterada é retornada
 */
CelulaD *apagaSequencia(int inicio, int fim, CelulaD *l){}

int main() {
	CelulaD *listaD = NULL;
	int i;
	srand(time(NULL));
	
	for (i = 0; i < rand() % 15 + 2; i++) {
		listaD = inserirD(rand() % 100, listaD);
	}
	
	exibirR(listaD);
	return 1;
}

