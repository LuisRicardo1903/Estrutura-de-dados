#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noD{
    int dado;
    struct noD *ant, *prox;
} CelulaD;

void exibirD(CelulaD *l){
    CelulaD *p;
    if (!l){
        printf("LISTA DUPLA VAZIA!!!\N");
        return;
    }

    for (; l->ant; l = l -> ant); //posicionando l no inicio da lista

    for (p = l; p ; p = p->prox){
        printf("%d\n", p->dado);
    }
}

int contarNosD(CelulaD *l){
    int contador = 0;
    CelulaD *p;
    if (!l){
        return contador;
    }

    for (; l->ant; l = l -> ant); //posicionando l no inicio da lista

    for (p = l; p ; p = p->prox, contador++);

    return contador;
}

CelulaD *inserirD(int valor, CelulaD *l){
    CelulaD *novo, *p, *pR;
    //alocar
    novo = (CelulaD *)malloc(sizeof(CelulaD));
    //depositar valores
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    //verificar se eh a primeira vez
    if(!l) return novo;

    //posicionar no inicio
    for(; l->ant ; l = l->ant);

    for(pR = NULL, p = l; p; pR = p, p = p->prox){
        if(valor < p->dado) {
            //verificar se é no inicio a inserção
            if(p == l) {
                p->ant = novo;
                novo->prox = p;
                return novo;
            }
            //inserção no meio
            pR->prox = novo;
            novo->ant = pR;
            novo->prox = p;
            p->ant = novo;
            return l;
        }
    }

    pR->prox = novo;
    novo->ant = pR;

    return l;

}

int main(){
    CelulaD *listaD = NULL;
    int qtd;
    int numero;

    srand(time(NULL));

    printf("Numeros Sorteados: ");
    for(qtd = rand () % 20; qtd > 0; qtd--){
        numero = rand () %100;
        printf("%d\n", numero);
        listaD = inserirD(numero, listaD);
    }

    printf("Numeros ordenados na lista duplamente encadeada: \n");
    exibirD(listaD);
    printf("Total Elementos %d\n", contarNosD(listaD));

    return 1;

}
