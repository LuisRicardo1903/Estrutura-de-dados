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

/*Celula *remover(Celula *topo){
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
*/
void exibir(Celula *topo){
    Celula *p;
    if (!topo){
        printf("Pilha Vazia\n");
    } else {
        for (p = topo; p != NULL; p = p->prox){
            printf("(%d) %s\n------------\n", p->matricula, p->nome);
        }
        printf("\n");
    }
}

void procurar (int matricula, Celula *topo){
    Celula *p;
    if (!topo){
        printf("Pilha Vazia\n");
    } else {
        for (p = topo; p != NULL; p = p->prox){
            if(matricula == p->matricula){
            printf("(%p) - [%d] %s", p, p->matricula, p->nome);
            return; //ATENCAO
            }
        }
        printf("Matricula nao localizada\n");
    }
}

Celula *procurarComRetorno(int matricula, Celula *topo){
    Celula *p;
    if (!topo){
        return topo;
    } else {
        for (p = topo; p != NULL; p = p->prox){
            if(matricula == p->matricula){
            return p; //ATENCAO
            }
        }
        return NULL;
    }
}

void atualizarArquivo(char *nomeArquivo, Celula *topo){
    FILE *procurador;
    Celula *p;
    if(topo == NULL){
        printf("Arquivo nao atualizado, pilha vazia");
        return;
    }
    procurador = fopen(nomeArquivo, "w");
    for (p = topo; p != NULL; p = p->prox){
            fprintf(procurador, "%d %s\n", p->matricula, p->nome);
            fflush(procurador);
    }
    fclose(procurador);
}

int main(){
    Celula *pilhaMatricula = NULL;
    Celula *resposta;
    FILE *procurador;
    int novaMat;
    char nomeArquivo[100];
    char matricula[10], nome[50];

    printf("Digite o nome do arquivo de matriculas: ");
    scanf("%s", nomeArquivo);
    procurador = fopen(nomeArquivo, "r");
    if (!procurador){
        printf("Arquivo nao Localizado.\n");
        exit(0);
        }
    do{
        fscanf(procurador, "%s %s", matricula, nome);
        pilhaMatricula = inserir(atoi(matricula), nome, pilhaMatricula);
    }while (!feof(procurador));

    //pilhaMatricula = remover(pilhaMatricula);
    //printf("%p - %d - %p\n", pilhaMatricula, pilhaMatricula->matricula, pilhaMatricula->prox);

    printf("Conteudo da Pilha: \n");
    exibir(pilhaMatricula);

    //procurar(14002, pilhaMatricula);
    resposta = procurarComRetorno(14002, pilhaMatricula);
    if(resposta){
        resposta->matricula = 11111;
        strcpy(resposta->nome, "Chiquinho");
    }else printf("Matricula nao localizada\n");

    printf("conteudo da pilha\n");
    exibir(pilhaMatricula);

    fclose(procurador);

    atualizarArquivo(nomeArquivo, pilhaMatricula);

    return 1;
    }
