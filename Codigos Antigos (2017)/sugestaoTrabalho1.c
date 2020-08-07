
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]) {

	FILE *arquivo, *arquivoTemporario;
    int i;
    char caracter;
    char *letraDeProcura;
    char *letraDeTroca;


    if (argc < 2) {
        printf("\nErro na passagem de parâmetros\n");
        exit(1);
    }

    // Imprimindo o Argv[1] e Argv[2]
    printf("\nArgv[1] - arquivo de busca: %s\n\n",argv[1]);

   	//declarando os argv
   	letraDeProcura = argv[2];
   	letraDeTroca = argv[3];

   	printf("Procura: %s\n", letraDeProcura);
   	printf("Troca  : %s\n", letraDeTroca);

   	arquivo = fopen(argv[1],"r");
   	if (!arquivo) {
   		printf("Erro ao abrir arquivo!!!\n\n");
        exit(0);
    }

    //criando arquivo temporario
    arquivoTemporario = fopen("backup.txt","w");


    // definindo o caracter ele vai ler o 1° caracter do arquivo
    caracter = fgetc(arquivo);

	//enquanto o caracter lido for diferente do final ele continua executando
   	while(caracter!=EOF){	   
   		printf("%c",caracter);

        // comparação
        if(caracter == letraDeProcura[0]) {
        	//troca
            fputc(letraDeTroca[0], arquivoTemporario);

        } else {
        	//copiando no arquivo temporario
            fputc(caracter, arquivoTemporario);
        }
    	// muda a posição para o próximo caracter
    	caracter = fgetc(arquivo);
    }

    fclose(arquivo);
    fclose(arquivoTemporario);

	remove(argv[1]); //remove o arquivo de entrada
    rename("backup.txt",argv[1]); // renomeia o arquivo temporario para entrada

    return 1;
  }

