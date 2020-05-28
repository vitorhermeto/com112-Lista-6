#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "com112_sort.h"

void bubble_sort (int *vetor, int n, int *comp, int *mov) {
    int k, j, aux;
    for (k = n - 1; k > 0; k--) {

        for (j = 0; j < k; j++) {
            *comp=*comp+1;
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
                *mov=*mov+1;
            }
        }
    }
}

void selection_sort (int *vetor,int n, int *comp, int *mov) {
  	int i, j, min, aux;
  	for (i = 0; i < (n - 1); i++) {
    	min = i;
    	for (j = i+1; j < n; j++) {
    		*comp=*comp+1;
	      	if (vetor[j] < vetor[min]) {
	      		*mov=*mov+1;
	   			min = j;
      		}
    	}
	    if (i != min) {
	      	aux = vetor[i];
	      	vetor[i] = vetor[min];
	      	vetor[min] = aux;
	    }
	}
}

void insertionSort(int *vetor, int n, int *comp, int *mov) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        j = i;
        if(vetor[j-1]<vetor[j]){
            *comp=*comp+1;
		}
        while (j > 0 && vetor[j - 1] > vetor[j]){
        	*comp=*comp+1;
        	*mov=*mov+1;
            tmp = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = tmp;
            j--;
        }
    }
}

void mergeSort(int *V, int inicio, int fim, int *comp, int *mov){
	int meio;
	if(inicio < fim){
		meio=floor((inicio+fim)/2);
		mergeSort(V, inicio, meio, comp, mov);
		mergeSort(V, meio+1, fim, comp, mov);
		merge(V, inicio, meio, fim, comp, mov);
	}
}
void merge(int *V, int inicio, int meio, int fim, int *comp, int *mov){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1=0, fim2=0;
	tamanho=fim-inicio+1;
	p1=inicio;
	p2=meio+1;
	temp=(int *) malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				*comp=*comp+1;
				if(V[p1]<V[p2]){					
					temp[i]=V[p1++];
				}
				else{
					temp[i]=V[p2++];
				}
				if(p1>meio){
					fim1=1;	
				} 
				if(p2>fim){
					fim2=1;
				}
			}else{
				if(!fim1)
					temp[i]=V[p1++];
				else
					temp[i]=V[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++)
			V[k]=temp[j];
			*mov=*mov+1;
	}
	free(temp);
}
 
void quickSort(int *a, int inicio, int meio, int *comp, int *mov) {
    int i, j, x, y;
     
    i = inicio;
    j = meio;
    x = a[(inicio + meio) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < meio) {
            i++;
        }
        while(a[j] > x && j > inicio) {
            j--;
        }
	*comp=*comp+1;
        if(i <= j) {
	*mov=*mov+1;
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) {
        quickSort(a, inicio, j, comp, mov);
    }
    if(i < meio) {
        quickSort(a, i, meio, comp, mov);
    }
}

