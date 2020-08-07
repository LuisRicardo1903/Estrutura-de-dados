#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	char sigla[2]; //sigla do átomo
	int x;	//coordenada x no plano tridimensional
	int y;
	int z;
	struct nodo *prox;
} Atomo;

Atomo *inserir(char sigla[], int x, int y, int z, Atomo *topo) {
    Atomo *novo;
    //alocar memoria
    novo = (Atomo *)malloc(sizeof(Atomo));

    //depositar valores
    strcpy(novo->sigla , sigla);
    novo->x = x;
    novo->y = y;
    novo->z = z;

    //engatar empilhando
    novo->prox = topo;

    return novo;
}

int main(int qtdArgumentos, char *listaArgumentos[]) {
	FILE *arquivoProcurador;
	Atomo *pilhaAtomos = NULL;
	int qtdLinhas, i;
	char linha[100];
	char sigla[2];
	int x, y, z;

	if (qtdArgumentos != 2) {
		printf("Falha na passagem do arquivo de entrada\n");
		exit(0);
	}

	arquivoProcurador = fopen(listaArgumentos[1], "r");
	if (!arquivoProcurador) {
		printf("Arquivo não localizado\n");
		exit(0);
	}

	qtdLinhas = 0;
	while (fgets(linha,100,arquivoProcurador)) {
		qtdLinhas++;
	}
	printf("%d\n\n", qtdLinhas);
	if (qtdLinhas == 0) exit(0);
	fclose(arquivoProcurador);

	arquivoProcurador = fopen(listaArgumentos[1], "r");

	i = 0;
	while (i < qtdLinhas) {
        fscanf(arquivoProcurador,"%s %d %d %d", sigla, &x, &y, &z);
        pilhaAtomos = inserir(sigla, x, y, z, pilhaAtomos);
		i++;
	}

    printf("%s, %d", pilhaAtomos->sigla, pilhaAtomos->x);
	fclose(arquivoProcurador);
	return 1;
}
