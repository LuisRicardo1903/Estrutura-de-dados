/*
Abrir um arquivo com atomos e suas coordenadas tridimensionais, como por exemplo 
As 43  65  89.
O programa deve ler esse arquivo e armazenar esses átomos num vetor dinâmico do tipo Atomo. A leitura do arquivo de entrada dever ser via console.

Revisao de: arquivo, argumentos no main, structs, métodos
*/

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
	Atomo *listaAtomos;
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

	//rewind(arquivoProcurador);

	listaAtomos = malloc(sizeof(Atomo) * qtdLinhas);

	i = 0;
	while (i < qtdLinhas) {
		fscanf(arquivoProcurador,"%s %d %d %d", listaAtomos[i].sigla, &listaAtomos[i].x, &listaAtomos[i].y, &listaAtomos[i].z);
		i++;
	}

	for ( i = 0; i < qtdLinhas; i++) {
		printf("%s\n", listaAtomos[i].sigla);
	}	

	free(listaAtomos);
	fclose(arquivoProcurador);
	return 1;
}