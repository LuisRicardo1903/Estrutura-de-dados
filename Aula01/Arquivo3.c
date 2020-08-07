#include <stdio.h>
#include <stdlib.h>

int main(){
    char letra, linha[100];
    FILE *procurador;
    char nomeArquivo[100];

    printf("Digite nome do Arquivo: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if(!procurador){
        printf("Arquivo nao localizado\n");
        exit(0);
    }
    printf("Arquivo Localizado com exito\n");

    do{
        fgets(linha ,100, procurador);
        printf("%s", linha);
    } while (!feof(procurador));

    close(procurador);

    return 1;
}
