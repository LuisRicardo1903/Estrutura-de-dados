#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dado;
    struct nodo *prox;
}Celula;

Celula *inserir (int valor, Celula *l){
    Celula *novo, *p, *pr;
    //Alocar
    novo = (Celula *) malloc(sizeof(Celula));
    novo -> dado = valor;
    novo -> prox = NULL;

    if(!l){
        return novo;
    }

    for(p=l, pr=NULL; p; pr=p, p=p->prox){
        if(valor < p->dado){
            if(!pr){//1° Elemento
                novo -> prox=p;
                return novo;
            }
            pr -> prox=novo;//No Meio
            novo -> prox = p;
            return l;
        }
    }
    pr->prox = novo;
    return l;
}

void exibir(Celula *l){
    Celula *p;
    if(!l){
        printf("Lista Vazia\n");
        return;
    }
    for(p=l; p; p=p->prox){
        printf("%d\t", p->dado);
    }
    printf("\n");
}

int main(){
    Celula *lista = NULL;
    lista = inserir (1, lista);
    lista = inserir (3, lista);
    lista = inserir (2, lista);
    lista = inserir (1, lista);
    exibir (lista);
    return 1;
}
