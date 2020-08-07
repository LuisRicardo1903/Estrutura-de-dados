#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;


Celula *inserir(int valor, Celula *topo) {
	Celula *novo; //para alocar nova célula

	//alocar memória
	novo = (Celula *)malloc(sizeof(Celula));

	//depositar valor
	novo->dado = valor;

	//engatar
	novo->prox = topo; //o novo elemento conhece o topo
	
	return novo; //novo topo é retornado
}

Celula *remover(Celula *topo) {
	Celula *lixo;

	if (!topo) {
		printf("Pilha vazia\n");
		return topo;
	}

	lixo = topo;
	topo = topo->prox; 

	return topo;
}

int main(int argc, char *argv[]) {
	Celula *pilha = NULL;
	FILE *arquivo;
	char comando;
	char descricao[100];
	int voltagem;

	if (argc != 2) {
		printf("Falha na quantidade de argumentos\n");
		exit(0);
	}

	arquivo = fopen(argv[1], "r");
	if (!arquivo) {
		printf("Arquivo não localizado\n");
		exit(0);
	}

	while (!feof(arquivo)) {
		fscanf(arquivo,"%c %s %d", &comando, descricao, &voltagem);
		if (comando == 'I') pilha = inserir(voltagem, pilha);
		if (comando == 'R') pilha = remover(pilha);
	}

	printf("Topo da pilha: %d e está no endereço: %p\n\n", pilha->dado, pilha);

	fclose(arquivo);
	return 1;
}








