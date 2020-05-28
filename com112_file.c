#include <stdio.h>
#include <stdlib.h>
#include "com112_file.h"

void EscreverArquivoEntrada(int *vet, int n){
	int i;
	FILE *file;
	file = fopen("com112_entrada.txt", "a");
	if(file == NULL){
	  printf("\nErro na abertura do arquivo com112_entrada.txt!");
	}else
		printf("\nArquivo com112_entrada.txt criado com sucesso! \n");

	fprintf(file,"%d \n", n);
	for(i=0;i<n;i++){
		fprintf(file,"%d ", vet[i]);
	}
	fprintf(file," \n");
	fclose(file);
}

void EscreverArquivoSaida(int *vet, int n){
	int i;
	FILE *file;
	file = fopen("com112_saida.txt", "a");
	if(file == NULL){
	  	printf("\nErro na abertura do arquivo com112_saida.txt! \n");
	}else
		printf("\nArquivo com112_saida.txt criado com sucesso \n");
	fprintf(file,"%d \n", n);
	for(i=0;i<n;i++){
		fprintf(file,"%d ", vet[i]);
	}
	fprintf(file," \n");
	fclose(file);
}

void EscreverArquivoRelatorio1(int n){
	int i;
	FILE *file;
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file,"\nN�mero de elementos ordenados:%d \n", n);
	fclose(file);
}

void EscreverArquivoRelatorio2(int op, float tempo, int comp, int mov){
	int i;
	FILE *file;
	file = fopen("com112_relatorio.txt", "a");
	if(file == NULL){
	  	printf("\nErro na abertura do arquivo com112_relatorio.txt! \n");
	}else{
		printf("\nArquivo com112_relatorio.txt atualizado com sucesso \n");
		switch (op){
			case 1:
			fprintf(file,"   M�todo Bubble Sort \n");
			fprintf(file,"    Tempo de execu��o: %f \n    N�mero de compara��es: %d \n    N�mero de movimenta��es: %d \n", tempo, comp, mov);
			break;
			
			case 2:
			fprintf(file,"   M�todo Selectin Sort \n");
			fprintf(file,"    Tempo de execu��o: %f \n    N�mero de compara��es: %d \n    N�mero de movimenta��es: %d \n", tempo, comp, mov);
			break;
				
			case 3:
			fprintf(file,"   M�todo Insertion Sort \n");
			fprintf(file,"    Tempo de execu��o: %f \n    N�mero de compara��es: %d \n    N�mero de movimenta��es: %d \n", tempo, comp, mov);
			break;
				
			case 4:
			fprintf(file,"   M�todo Merge Sort \n");
			fprintf(file,"    Tempo de execu��o: %f \n    N�mero de compara��es: %d \n    N�mero de movimenta��es: %d \n", tempo, comp, mov);
			break;
			
			case 5:
			fprintf(file,"   M�todo quick Sort \n");
			fprintf(file,"    Tempo de execu��o: %f \n    N�mero de compara��es: %d \n    N�mero de movimenta��es: %d \n", tempo, comp, mov);
			break;
				
			case 6:
			fprintf(file,"   Relatorio \n");
			break;
			
			case 7:
			fprintf(file,"   Fim do relatorio \n");
			break;
		}
	}
	fclose(file);
}

void LerArquivo(int *vet, int n){
	
	FILE *file;
	file = fopen("com112_entrada.txt", "r");
	char vetor[n];
	int i;
	for (i=0; i<n; i++){
    fscanf(file,"%d",&vet[i]);
	}
}

void LimparArquivos(){
	FILE *file;
	file = fopen("com112_entrada.txt", "w");
	fprintf(file," ");
	fclose(file);
	file = fopen("com112_saida.txt", "w");
	fprintf(file," ");
	fclose(file);
	file = fopen("com112_relatorio.txt", "w");
	fprintf(file," ");
	fclose(file);
}
