#include <stdio.h>
#include <stdlib.h>

void exibirC (Celula *){

    Celula *p;
    if(!l) printf("Lista Vazia\n");
    else {
    for (p=l; p->prox!l=l; p=p->prox)
        printf("%d\n", p->dado);
        }
    }printf("%d\n", p->dado);
}

Celula *localizarC (int valor, Celula *l){
    Celula *p;
    if(!l) return NULL;
    for(p=l; p->prox!=l; p=p->prox){
        if (valor == p->dado)
        return p;
        }
        if (valor == p->dado)
        return p;
    }
int ContarNosC(Celula *l){
    Celula *p;
    int c=0;
    if(!l) return c;
    for (p=l; p->prox!l=l; p=p->prox)
    c++;
    }
    return ++c;
}
