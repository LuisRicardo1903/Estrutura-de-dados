#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct nodo {
	int matricula;
	char nome[50];
	struct nodo *prox;
}Celula;

Celula *inserir(int matricula, char *nome, Celula *l) {
	Celula *p, *pR, *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->matricula = matricula;
	strcpy(novo->nome, nome);
	novo->prox = NULL;

	if (!l) return novo;

	for (pR = NULL, p = l ; p ; pR = p, p = p->prox) {
		if (matricula == p->matricula) {
			printf("Matricula ja cadastrada\n");
			free(novo);
			return l;
		} 
		if (matricula < p->matricula) {
			//eh o primeiro
			if (p == l) { //igual a if (!pR)
				novo->prox = l; // ou novo->prox = p;
				return novo;
			} /*else*/
			pR->prox = novo;
			novo->prox = p;
			return l;
		}
	}
	//eh o ultimo
	pR->prox = novo;
	return l;
}

void exibir(Celula *l) {
	Celula *p;

	if (!l) {
		printf("Lista vazia\n");
		return;
	}
	for (p = l; p ; p = p->prox) {
		printf("%d %s\n", p->matricula, p->nome);
		printf("-------------------------------\n");
	}
	printf("\n");
}

int contarNos(Celula *l) {
	Celula *p;
	int contador = 0;

	if (!l) {
		printf("Lista vazia\n");
		return contador;
	}
	for (p = l; p ; p = p->prox,  contador++);

	return contador;
}

Celula *excluir(int matricula, Celula *l) {
	Celula *p, *pR;

	if (!l) {
		printf("Lista vazia\n");
		return NULL;
	}
	for (pR = NULL, p = l; p ; pR = p, p = p->prox) {
		if (matricula == p->matricula) {
			if (p == l) { //eh o primeiro
				l = l->prox;
			} else 	if (!p->prox) { //eh o ultimo
				pR->prox = NULL;
			} else { //eh o meio
				pR->prox = p->prox;
			}
			free(p);
			return l;	
		}
	}
	//printf("Valor nao localizado na lista\n");
	return l;
}

Celula *popularLista_Arquivo(Celula *l, char *nomeArquivo) {
	FILE *procurador = fopen(nomeArquivo,"r");
	int matricula;
	char nome[50];

	if (!procurador) return NULL;

	do {
		fscanf(procurador,"%d %s", &matricula, nome);
		l = inserir(matricula, nome, l);

	} while(!feof(procurador));

	fclose(procurador);

	return l;
}

void salvarLista_Arquivo(Celula *l, char *nomeArquivo) {
	FILE *procurador = fopen(nomeArquivo, "w");
	Celula *p;

	for (p = l; p; p = p->prox) {
		fprintf(procurador, "\n%d %s", p->matricula, p->nome);
		fflush(procurador);
	}
	fclose(procurador);
}

Celula *cadastrar(Celula *l) {
	int matricula;
	char nome[50];

	printf("Digite matricula: ");
	scanf("%d", &matricula);
	fflush(stdin);
	printf("Digite nome: ");
	scanf("%s", nome);
	fflush(stdin);

	l = inserir(matricula, nome, l);

	return l;
}

int main() {
	Celula *lista = NULL;
	int opcao;

	lista = popularLista_Arquivo(lista, "matriculas.txt");

	do {
		printf("1 - Cadastrar aluno\n");
		printf("2 - Listar alunos\n");
		printf("3 - Excluir aluno\n");
		printf("4 - Localizar aluno\n");
		printf("5 - Finalizar\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		fflush(stdin);

		switch (opcao) {
			case 1: lista = cadastrar(lista);
			        break;
			case 2: printf("L I S T A  D E  A L U N O S\n\n");
					exibir(lista);
			        break;
			case 3: break;
			case 4: break;
			case 5: salvarLista_Arquivo(lista, "matriculas.txt");
			        break;
			default : printf("Opcao invalida!\n");
		}
	} while (opcao != 5);
	return 1;
}







