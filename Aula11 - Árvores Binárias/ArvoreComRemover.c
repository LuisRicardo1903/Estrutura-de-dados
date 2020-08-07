#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
} Arvore;

Arvore *inserirArvore(int valor, Arvore*r) {
    if (r){
        if (valor == r->dado) return r;

        if (valor < r->dado){
            r->esq = inserirArvore(valor, r->esq);
        }
        else r->dir = inserirArvore(valor, r->dir);

        return r;
    } else {
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

void exibirArvore(Arvore *r, int nivel) {
    if (r) {
        exibirArvore(r->dir, nivel + 1);

        int i;
        for(i = 0; i < nivel; i++) {
            printf("   ");
        }
        printf("(%d)%d\n", nivel, r->dado);

        exibirArvore(r->esq, nivel + 1);
    }
}

int contarNos(Arvore *r) {
    if(r) {
        return 1 + contarNos(r->esq) + contarNos(r->dir);
    } else return 0; //Se esta aqui, porque não ha mais nos ou nodos
}

int contarFolhas(Arvore *r){
    if(r) {
        if (!r->esq && !r->dir) return 1;

        return 0 + contarFolhas(r->esq) + contarFolhas(r->dir);

    } else return 0;
}

int contarNaoFolhas(Arvore *r) {
    if(r) {
        if (r->esq || r->dir) return 1 + contarNaoFolhas(r->esq) + contarNaoFolhas(r->dir);
    }

    return 0;
}

void exibirFolhas(Arvore *r) {
    if(r) {
        if(!r->esq && !r->dir) printf("[%d]\t", r->dado);
        exibirFolhas(r->esq);
        exibirFolhas(r->dir);
    }
}

int acharNivel(int valor, Arvore *r) {
    if(r){
        if(valor == r->dado) return 0;

        int veioDoEmpilhamento;

        if(valor < r->dado) {
            veioDoEmpilhamento = acharNivel(valor, r->esq);
        } else {
            veioDoEmpilhamento = acharNivel(valor, r->dir);
        }

        if(veioDoEmpilhamento == -1) return -1;
        else return veioDoEmpilhamento + 1;
    } else return -1;
}

/*Arvore *podar(Arvore *r) {
    if (r) {
        if (!r->esq && !r->dir) {
            free(r);
            return NULL;
        }
        r->esq = podar(r->esq);
        r->dir = podar(r->dir);
        return r;
    }else return NULL;
}
*/
Arvore *removerArvore(int valor, Arvore *r){
    if(r) {
        if(valor == r->dado) {
            //localizado e sera removido
            //verificar se eg folha
            if(!r->esq && !r->dir) {
                free(r);
                return NULL;
            }
            //verificar se tem filho na esq e NAO tem filho na dir
            if(r->esq && !r->dir) {
                Arvore *tmp = r->esq;
                free(r);
                return tmp;
            }
            //verificar se NAO tem filho na esq e tem filho na dir
            if(!r->esq && r->dir) {
                Arvore *tmp = r->dir;
                free(r);
                return tmp;
            }
            //Se chegou aqui tem filho na esquerda e na direita
            if(r->esq && r->dir) {
                Arvore *novoPai = r->dir;
                Arvore *tmp = novoPai->esq;
                novoPai->esq = r->esq;
                free(r);

                for(r = novoPai->esq; r->dir; r = r->dir);

                r->dir = tmp;

                return novoPai;
            }

        } else if(valor < r->dado){
            r->esq = removerArvore(valor, r->esq);
        } else {
            r->dir = removerArvore(valor, r->dir);
        }

        return r;

    } else {
        return NULL;
    }
}

int main(){
    Arvore *raiz = NULL;

    raiz = inserirArvore(10, raiz);
    raiz = inserirArvore(7, raiz);
    raiz = inserirArvore(5, raiz);
    raiz = inserirArvore(20, raiz);
    raiz = inserirArvore(15, raiz);
    raiz = inserirArvore(18, raiz);
    raiz = inserirArvore(9, raiz);

    printf("Total de Nos na arvore: [%d]\n", contarNos(raiz));
    printf("Total de Folhas na arvore: [%d]\n", contarFolhas(raiz));
    printf("As folhas da Arvore sao: ");
    exibirArvore(raiz, 0);
    //exibirFolhas(raiz);
    printf("\nTotal de NAO Folhas na arvore: [%d]\n", contarNaoFolhas(raiz));
    int numero;
    printf("Digite um numero para pesquisar/deletar: ");
    scanf("%d", &numero);
    printf("%d esta no nivel: [%d]\n", numero, acharNivel(numero, raiz));

    //raiz = podar(raiz);
    //printf("Arvore depois da poda...\n");

    raiz = removerArvore(numero, raiz);
    printf("Arvore pos remocao\n");
    exibirArvore(raiz, 0);

    return 1;
    }
