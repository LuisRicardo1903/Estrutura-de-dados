#include <stdio.h>
#include <stdlib.h>

int main(){
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
    fclose(procurador);
    return 1;
}
