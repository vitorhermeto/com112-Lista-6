#ifndef COM112_SORT_H
#define COM112_SORT_H

void bubble_sort(int *vetor, int n, int *comp, int *mov);

void selection_sort (int *vetor,int n, int *comp, int *mov);

void insertionSort(int *vetor, int n, int *comp, int *mov);

void mergeSort(int *V, int inicio, int fim, int *comp, int *mov);
void merge(int *V, int inicio, int meio, int fim, int *comp, int *mov);

void quickSort(int *a, int inicio, int meio, int *comp, int *mov);

#endif

