//Exercicio 1


//Exercicio 2
int ehSimetrico(Grafo *g) {
	int i, j;

	for (i = 0; i < g->qtdVertices; i++)
		for (j= 0; j < g->qtdVertices; j++)
			if (g->matrizAdj[i][j] && !g->matrizAdj[j][i])
				return 0; //nao eh simetrico

	return 1; //eh simetrico
} else {
    return 0;
}
