#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int matricula;
    char nome[50];
    struct nodo *prox;
    }Celula;
Celula *inserir (int matricula, char *nome, Celula *topo) {
    Celula *novo;
    //alocar memoria
    novo = (Celula *)malloc(sizeof(Celula));
    //depositar valores
    novo -> matricula = matricula; //*novo.matricula = matricula;
    strcpy(novo->nome, nome); //strcpy(*novo.nome, nome)
    novo->prox = topo; //*novo.prox = topo
    //atualizar topo;
    return novo;
    }

Celula *remover(Celula *topo){
    Celula *lixo;

    if(!topo){
        printf("Pilha Vazia!\n");
    }else {
        lixo = topo;
        topo = topo->prox;
        free(lixo);
        }
    return topo;
    }

int main(){

    Celula *pilhaMatricula = NULL;
    FILE *procurador;
    char nomeArquivo[100];
    char matricula[10], nome[50];

    printf("Digite o nome do arquivo de matriculas: ");
    scanf("%s", nomeArquivo);
    procurador = fopen(nomeArquivo, "r");
    if (!procurador){
        printf("Arquivo nao Localizado.\n");
        exit(0);
    }

    do {
        fscanf(procurador, "%s %s", matricula, nome);
        pilhaMatricula = inserir(atoi(matricula), nome, pilhaMatricula);

    }while (!feof(procurador));

    pilhaMatricula = remover(pilhaMatricula);
    printf("%p - %d - %p\n", pilhaMatricula, pilhaMatricula->matricula, pilhaMatricula->prox);

    fclose(procurador);

    return 1;
    }
