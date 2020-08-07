#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char sigla[2]; //sigla do átomo
	int x;	//coordenada x no plano tridimensional
	int y;
	int z;
} Atomo;

int main(int qtdArgumentos, char *listaArgumentos[]) {
	FILE *arquivoProcurador;
	Atomo *vetorAtomos;
	int qtdLinhas, i;
	char linha[100];

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

	vetorAtomos = malloc(sizeof(Atomo) * qtdLinhas);

	i = 0;
	while (i < qtdLinhas) {
		fscanf(arquivoProcurador,"%s %d %d %d", vetorAtomos[i].sigla, &vetorAtomos[i].x, &vetorAtomos[i].y, &vetorAtomos[i].z);
		i++;
	}

	for ( i = 0; i < qtdLinhas; i++) {
		printf("%s - %d\n", vetorAtomos[i].sigla, vetorAtomos[i].x);
	}

	free(vetorAtomos);
	fclose(arquivoProcurador);
	return 1;
}
