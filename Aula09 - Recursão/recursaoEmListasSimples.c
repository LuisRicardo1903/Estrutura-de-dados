#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int dado;
    struct no *prox;
}Celula;

void exibirR(Celula *l) {
    if (l) {
        printf("%d\n", l->dado);
        exibirR(l->prox);
    }
}

Celula *inserirR(int valor, Celula *l) {
    if (l && valor > l->dado) {
        l->prox = inserirR(valor, l->prox);
        return l;
    } else {
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->dado = valor;

        if (l) novo->prox = l;
        else novo->prox = NULL;

        return novo;
    }
}

int contarNosR(Celula *l){
    if(l){
        return 1 + contarNosR(l->prox);
    }
    return 0;
}

Celula *localizarEnderecoR(int valor, Celula *l) {

    if(l){
        if (valor == l->dado) return l;

        return localizarEnderecoR(valor, l->prox);
    }
    return NULL;
}

int somarR(Celula *l){
    if(l){
        return l->dado + somarR(l->prox);
    }
    return 0;
}

Celula *destruirR(Celula *l){
    if(l){

        l->prox = destruirR(l->prox);

        free(l);

        return NULL;
    }
    return NULL;

}

Celula *removerR(int valor, Celula *l){
    if(l){
        if(valor == l->dado){
                Celula *tmp = l->prox;
                free(l);
                return tmp;
        } else {
            l->prox = removerR(valor, l->prox);
            return l;
        }
    }
    return NULL;

}


int main() {
    Celula *lista = NULL;
    lista = inserirR(5, lista);
    lista = inserirR(10, lista);
    lista = inserirR(3, lista);
    lista = inserirR(8, lista);

    exibirR(lista);

    int totalNosR = contarNosR(lista);
    printf("Total de Nos: %d\n", totalNosR);

    int numero;
    printf("Digite um valor a ser pesquisado: ");
    scanf("%d", &numero);

    Celula *endereco = localizarEnderecoR(numero, lista);

    printf("Valor lozalizado em: %p\n", endereco);

    printf("A soma do conteudo da lista eh: %d\n", somarR(lista));

    lista = destruirR(lista);
    exibirR(lista);

    lista = removerR(numero, lista);
    exibirR(lista);

    return 1;
}

//
