#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
    int dado;
    struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *l) {
    Celula *novo, *p, *pR;

    //alocar
    novo = (Celula *)malloc(sizeof(Celula));
    //depositar
    novo->dado = valor;
    novo->prox = NULL;
    //primeira vez = lista vazia
    if (!l) return novo;
    //percorrer e engatar
    for (pR = NULL, p = l; p ; pR = p, p = p->prox) {
        if( valor == p->dado) {
                    printf("Valor ja inserido\n");
                    return l;
        }
        if (valor < p->dado) {
            if (!pR) { //serah inserido no inicio da lista
                novo->prox = p; //ou novo->prox = l;
                return novo;
            }
            //serah inserido no meio da lista
            pR->prox = novo;
            novo->prox = p;
            return l;
        }
    }
    //serah inserido no final da lista
    pR->prox = novo;
    return l;
}

void exibir(Celula *l) {
    Celula *p;

    if (!l) {
        printf("Lista vazia!\n");
    } else {
        for (p = l; p ; p = p->prox) {
            printf("%p -> %d\n", p, p->dado);
        }
        printf("\n");
    }

}

int contarNodos(Celula *l) {
    Celula *p;
    int contador = 0;

    for (p = l; p; p = p->prox, contador++);

    return contador;
}

int estaNaLista(int valor, Celula *l){
    Celula *p;

    if (!l) return 0;

    for (p = l; p ; p = p->prox) {
        if (valor == p->dado) return 1; //valor localizado
    }
    return 0; //nao localizado
}

Celula *localizarEndereco(int valor, Celula *l) {
    Celula *p;

    if (!l) return NULL;

    for (p = l; p ; p = p->prox) {
        if (valor == p->dado) return p;
    }
    return NULL;
}

char *localizarPosicao(int valor, Celula *l) {
    Celula *p;

    if (!l) return "LISTA VAZIA\n";

    for (p = l; p ; p = p->prox) {
        if (valor == p->dado) {
            if (p == l) return "inicio\n";
            if (!p->prox) return "fim\n";
            return "meio\n";
        }
    }
    return "NAO LOCALIZADO\n";
}

Celula *excluir (int valor, Celula *l){
    Celula *p, *pR;

    if (!l) {
        printf("Lista Vazia \n");
        return NULL;
    }
    for (pR = NULL, p = l; p ; pR = p, p=p->prox){
        if (valor == p->dado){
            if (p == l) {
                l = l->prox;
            }else if (!p->prox) {
                pR-> prox = NULL;
            }else {
                pR->prox = p->prox;
            }
            free(p);
            return l;
        }
    }
    printf("Valor nao localizado na lista! \n");
    return l;
}
int main() {
    Celula *lista = NULL;
    int n;
    int numero;
    srand(time(NULL));

    for (n = rand() % 20; n > 0 ; n--) {
        numero = rand() % 100;
        lista = inserir(numero, lista);
    }
    exibir(lista);
    int qtdNodos = contarNodos(lista);
    printf("Total de nodos: %d\n", qtdNodos);
    printf("Digite um valor a pesquisar: ");
    scanf("%d", &numero);
    if ( estaNaLista(numero, lista) ) {
        printf("%d localizado na lista\n", numero);
    } else {
        printf("%d NAO localizado na lista\n", numero);
    }

    printf("Endereco do %d eh %p\n", numero, localizarEndereco(numero, lista));

    printf("%d esta no... %s\n", numero, localizarPosicao(numero, lista));

    return 1;
}
