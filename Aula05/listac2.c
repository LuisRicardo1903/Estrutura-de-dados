#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserirC(int valor, Celula *l) {
    Celula *novo, *p, *pR;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = novo;

    if (!l) return novo;

    for (pR = NULL, p = l; p->prox != l ; pR = p, p = p->prox) {
        if (valor < p->dado) { //localizamos
            //primeiro
            if (p == l) { // !pR
                novo->prox = p;
                //percorrer ate o final da lista circular
                for ( ; p->prox != l; p = p->prox);

                p->prox = novo;
                return novo;
            }
            //meio
            pR->prox = novo;
            novo->prox = p;
            return l;
        }
    }
    if (valor < p->dado) { //localizamos
        //primeiro
        if (p == l) {
            novo->prox = p;
            //percorrer ate o final da lista circular
            for ( ; p->prox != l; p = p->prox);

            p->prox = novo;
            return novo;
        }
        //meio
        pR->prox = novo;
        novo->prox = p;
        return l;
    }
    //fim
    p->prox = novo;
    novo->prox = l;
    return l;
}

void exibirC(Celula *l) {
    Celula *p;

    if (!l) printf("Lista vazia!\n\n");
    else {
        for (p = l; p->prox != l; p = p->prox) {
            printf("%d\n", p->dado);
        }
        printf("%d\n", p->dado);
    }
}

int contarNodosC(Celula *l) {
    Celula *p;
    int contaNos = 0;
    
    if (!l) return 0;

    for (p = l; p->prox != l; p = p->prox, contaNos++);
    
    return ++contaNos;
}

Celula *localizarC(int valor, Celula *l) {
    Celula *p;

    if (!l) return NULL;

    for (p = l; p->prox != l; p = p->prox) {
        if (valor == p->dado) return p;
    }
    if (valor == p->dado) return p;

    return NULL;
}

Celula *removerC(int valor, Celula *l) {
    Celula *p, *pR;

    if (!l) return NULL;
    
    for (p = l, pR = NULL; p->prox != l; pR = p, p = p->prox) {
        if (valor == p->dado) {
            //eh primeiro
            if (p == l) {
                pR = l; //copia do inicio da lista para percorre-la
                l = l->prox;
                //leva o p ate o final da lista
                for (; p->prox != pR; p = p->prox);
                
                p->prox = l;
                free(pR);
                return l;
            } else {//meio
                pR->prox = p->prox;
                free(p);
            }
        } 
    } 
    if (valor == p->dado) { //saiu do for e testa para o ultimo
        //primeiro e unico
        if (p == l) {
            free(p);
            return NULL;
        }
        //ultimo
        pR->prox = p->prox;
        free(p);
    }  
    return l;
}

int main( ){
    Celula *listaC = NULL;
    int n, numero;
    srand(time(NULL));

    for (n = rand() % 20; n > 0; n--) {
        numero = rand() % 100;
        //printf("%d\t", numero);
        listaC = inserirC(numero,listaC);
    }
    printf("Lista original!\n");

    exibirC(listaC);
    
    printf("Total de nodos: %d\n\n", contarNodosC(listaC));
    
    printf("Informe numero de pesquisa: ");
    scanf("%d", &numero);

    //printf("%d no endereco %p\n\n", numero, localizarC(numero, listaC));
    
    listaC = removerC(numero, listaC);
    
    printf("Lista alterada!\n");
    
    exibirC(listaC);

    return 1;
}
