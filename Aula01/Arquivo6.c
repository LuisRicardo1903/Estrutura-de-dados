#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int existeMatricula(char *m, char *arq){
    char matricula[10], nome[50];
    FILE *procurador;
    procurador = fopen(arq,"r");
    do{
        fscanf(procurador, "%s %s", matricula, nome);
        if(strcmp(m, matricula) == 0){
            printf("Matricula ja existente\n");
            return 1;
    }
    }while (!feof(procurador));
        fclose(procurador);
        return 0;
}
int main(){
    char letra, linha[100];
    char matricula[10], nome[50];
    FILE *procurador;
    char nomeArquivo[100], nomePesquisa[50];

    printf("Digite nome do Arquivo: ");
    scanf("%s", nomeArquivo);

    fflush(stdin);
    procurador = fopen(nomeArquivo,"r");

    if(!procurador){
        printf("Arquivo nao localizado\n");
        exit(0);
    }
    printf("Arquivo Localizado com exito\n");

    printf("Digite nome a ser procurado: ");
    scanf("%s", nomePesquisa);
    fflush(stdin);

    do{
        fscanf(procurador, "%s %s", matricula, nome);
        if(strcmp(nome, nomePesquisa)== 0){
            printf("Localizado com Matricula numero %s\n", matricula);
            exit(0);
        }
    } while (!feof(procurador));

    printf("\n%s nao localizado\n", nomePesquisa);

    fclose(procurador);

    procurador = fopen (nomeArquivo, "a");


    do{
        printf("Informe a Matricula: ");
        scanf("%s", matricula);
        fflush(stdin);

    } while (existeMatricula(matricula, nomeArquivo));
    //procurador = fopen(nomeArquivo, "a");
    fprintf(procurador, "%s %s\n", matricula,nomePesquisa);

    fclose(procurador);

    return 1;
}

