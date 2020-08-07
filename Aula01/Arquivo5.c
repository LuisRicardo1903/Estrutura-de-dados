#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char letra, linha[100];
    char matricula[10], nome[50];
    FILE *procurador;
    char nomeArquivo[100], nomePesquisa[50];

    printf("Digite nome do Arquivo: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if(!procurador){
        printf("Arquivo nao localizado\n");
        exit(0);
    }
    printf("Arquivo Localizado com exito\n");

    printf("Digite nome a ser procurado: ");
    scanf("%s", nomePesquisa);

    do{
        fscanf(procurador, "%s %s", matricula, nome);
        if(strcmp(nome, nomePesquisa)== 0){
            printf("Localizado com Matricula numero %s\n", matricula);
            exit(0);
        }
    } while (!feof(procurador));

    printf("%s nao localizado\n", nomePesquisa);

    fclose(procurador);

    return 1;
}

