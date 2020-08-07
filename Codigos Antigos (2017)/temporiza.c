#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int qtdComparacoes, qtdTrocas;
clock_t tempoInicio, tempoFim;

void populaVetor(int v[], unsigned long long int n) {
	unsigned long long int i;	
	srand(time(NULL));
	for (i = 0; i < n; i = i + 1) {
		v[i] = rand() % 100;
	}
}

void exibirVetor(int v[], unsigned long long int n) {
	unsigned long long int i;	

	for (i = 0; i < n; i = i + 1) {
		printf("%llu - %d\n", i, v[i]);
	}	
	printf("\n\n");
}


void ordenaSelecao(int *v, unsigned long long int n) {
	unsigned long long int i, j, posMenor;
	int tmp; //para as trocas

	qtdComparacoes = 0;
	qtdTrocas = 0;
	tempoInicio = clock();

	for (i = 0; i < n-1; i++) {
		posMenor = i;
		for (j = i+1; j < n; j++) {
			qtdComparacoes++;
			if (v[j] < v[posMenor]) posMenor = j;
		}
		if (i != posMenor) {
			tmp = v[i];
			v[i] = v[posMenor];
			v[posMenor] = tmp;
			qtdTrocas++;
		}
	}
	tempoFim = clock();
	printf("Selecao\nQuantidade Comparacoes: %llu\nQuantidade Trocas: %llu\n", qtdComparacoes, qtdTrocas);
	printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);
}

void ordenaPente(int *v, unsigned long long int n) {
	unsigned long long int i, distancia = n;
	int houveTrocas;
	int tmp; //para as trocas

	qtdComparacoes = 0;
	qtdTrocas = 0;
	tempoInicio = clock();

	do {
		distancia /= 1.3;
		if (distancia <= 0) distancia = 1;
		houveTrocas = 0;
		for (i = 0; i + distancia < n; i++) {
			qtdComparacoes++;
			if (v[i] > v[i + distancia]) {
				houveTrocas = 1;
				tmp = v[i];
				v[i] = v[i + distancia];
				v[i + distancia] = tmp;
				qtdTrocas++;
			}
		}
	} while (distancia != 1 || houveTrocas);
	
	tempoFim = clock();
	printf("Pente\nQuantidade Comparacoes: %llu\nQuantidade Trocas: %llu\n", qtdComparacoes, qtdTrocas);
	printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);
}

int main() {
	unsigned long long int quantidade, i;
	quantidade = 100;
	
	int vetorSelecao[quantidade];
	int vetorPente[quantidade];

	populaVetor(vetorSelecao, quantidade);

	for (i = 0; i < quantidade; i++) {
		vetorPente[i] = vetorSelecao[i];
	}
	//exibirVetor(vetorPente, quantidade);
	printf("\n\n");
	
	ordenaSelecao(vetorSelecao, quantidade);
	ordenaPente(vetorPente, quantidade);
	exibirVetor(vetorPente, quantidade);
	system("pause");
	
	return 1;
}
