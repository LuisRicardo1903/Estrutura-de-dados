#include<stdio.h>
#include<stdlib.h>

typedef struct noD {
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

CelulaD *removerD(int valor, CelulaD *l){
    CelulaD *p, *pR;

    //verificar se existe lista
    if(!l) return NULL;

    //posicionar l no inicio
    for (; l->ant; l = l -> ant);

    //percorrera a lista
    for(p = l, pR=NULL; p; pR = p=p->prox){
        if(valor == p->dado){ //foi encontrado
            if(p==l){
                l = l->prox;
                l->ant = NULL;
            } else if(!p->prox) {
                pR->prox = NULL;
            } else {
                pR->prox = p->prox;
                p->prox->ant = p->ant;
            }
            free(p);
            return l;
        }
    }
    //se chegou aqui. dignifica que o valor não foi encontrado na lista
    return l;
}


int main(){
    CelulaD *listaD = NULL;
    int numero;


    listaD = inserirD(10, listaD);
    listaD = inserirD(5, listaD);
    listaD = inserirD(8, listaD);
    listaD = inserirD(15, listaD);



    printf("Numero para remocao: ");
    scanf("%d", &numero);

    listaD = removerD(numero, listaD);

    exibirD(listaD);

    return 1;



}
