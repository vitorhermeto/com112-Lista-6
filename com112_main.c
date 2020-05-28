#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"
#include "com112_file.h"
#include <time.h>

//menu apenas de escolhas
int menu (){
	int op;
		printf("\n");
		printf("\nEscolha dentre as opcoes: \n 1-Bubble Sort \n 2-Selection Sort \n 3-Insertion Sort \n 4-Merge Sort \n 5-quick Sort \n 6-Relatorio \n 7-Sair \n opcao: ");
		scanf("%d", &op);
		printf("\n");
	
	return op;
}

int relatorio(float tempo, int comp, int mov, int *vetor, int n){
	printf(" 1. Tempo de execucao em segundos: %f \n 2. Numero de comparacoes entre elementos do vetor: %d \n 3. Numero de movimentacoes entre elementos do vetor: %d \n", tempo, comp, mov);
	printf("\n");
	return 0;
}

int main(){
	LimparArquivos();
	int n, i, op;
	float tempo;
    time_t t_ini, t_fim;
	printf("Entre com a quantidade de algarismos a serem ordenados: ");
	scanf("%d",&n);
	EscreverArquivoRelatorio1(n);	
	int vet[n];
	for (i=0;i<n;i++){
		vet[i]=rand() % 100;
	}
	EscreverArquivoEntrada(vet,n);
		//inicia o loop
		do{	
			//substitui pelos valores iniciais do vetor, comparações e movimentações 
			int comp=0, mov=0;
			LerArquivo(vet, n);
			op=menu();
			//opções referentes ao menu
			switch ( op ){
			    case 1 :
				    t_ini=time(NULL);
				    bubble_sort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(op, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
			    break;
			    
			    case 2 :
				    t_ini=time(NULL);
				    selection_sort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(op, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
			    break;
			    
			    case 3 :
				    t_ini=time(NULL);
				    insertionSort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(op, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
			    break;
			    
			    case 4:
				    t_ini=time(NULL);
				    mergeSort(vet, 0, n, &comp, &mov);
					t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(op, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);	
			    break;
			    
			    case 5:
				    t_ini=time(NULL);
				    quickSort(vet, 0, n-1, &comp, &mov);	
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(op, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
			    break;
			    
			    case 6 :
			    	EscreverArquivoRelatorio2(5, tempo, comp, mov);
			    	//bubble
				    t_ini=time(NULL);
				    bubble_sort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(1, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
		   			comp=0, mov=0;
		   			LerArquivo(vet, n);
					
		   			//selection
		   			t_ini=time(NULL);
				    selection_sort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(2, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
		   			comp=0, mov=0;
					LerArquivo(vet, n);
					
		   			//insertion
		   			t_ini=time(NULL);
				    insertionSort(vet, n, &comp, &mov);
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(3, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
		   			comp=0, mov=0;
					LerArquivo(vet, n);
					
		   			//merge
		   			t_ini=time(NULL);
				    mergeSort(vet, 0, n, &comp, &mov);
					t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(4, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
		   			comp=0, mov=0;
					LerArquivo(vet, n);
					
					//quick
		   			t_ini=time(NULL);
				    quickSort(vet, 0, n-1, &comp, &mov);	
				    t_fim=time(NULL);
		   			tempo=difftime(t_fim, t_ini);
		   			EscreverArquivoRelatorio2(5, tempo, comp, mov);
		   			relatorio(tempo, comp, mov, vet, n);
		   			EscreverArquivoSaida(vet, n);
					
					EscreverArquivoRelatorio2(6, tempo, comp, mov);
		   			
	   			break;
			    
			    case 7 :
				printf("\nFim do programa \nOs aquivos criados serao limpos apos a reinicializacao do programa"); 
			    break;
			    
			    default :
	   			printf ("Valor invalido!\n");
			}
			

		}while (op!=7 );

	return 0;	
}

