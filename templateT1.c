/**
 * @file templateT1.c
 * @author Felipe_Daniel_Nerling
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 *
  * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void quickSort(int *A, int start, int end, int *swapcont);

void swap (int *a, int *b);
int partition(int arr[], int low, int high, int *swapcont);


int main(){

	int i;
	int tamanhoVetor = 1000000;
    int vetor[tamanhoVetor];

    for (i = 0 ; i < tamanhoVetor ; i++)
        vetor[i] = (tamanhoVetor-i);

	/*printf("\nVetor original: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", vetor[i]);*/

	printf("\nVetor tamanho = %d\n\n", tamanhoVetor);

	// bubble sort
	int *bubbleVec = (int *)malloc(tamanhoVetor * sizeof(int));;
	copia(vetor, bubbleVec, tamanhoVetor);
    clock_t begin = clock();
    printf("\nBubble sort: \n");
	bubbleSort(bubbleVec, tamanhoVetor);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", bubbleVec[i]);*/
	printf("\n");
    free(bubbleVec);
	// selection sort
    int *SelectVec = (int *)malloc(tamanhoVetor * sizeof(int));;
	copia(vetor, SelectVec, tamanhoVetor);
    begin = clock();
    printf("\nSelection sort: \n");
	selectionSort(SelectVec, tamanhoVetor);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", SelectVec[i]);*/
	printf("\n");
    free(SelectVec);
	// insertion sort
    int *InsertVec = (int *)malloc(tamanhoVetor * sizeof(int));;
	copia(vetor, InsertVec, tamanhoVetor);
    printf("\nInsertion sort: \n");
    begin = clock();
	insertionSort(InsertVec, tamanhoVetor);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", InsertVec[i]);*/
	printf("\n");
    free(InsertVec);
	// quick sort
    int *QuickVec = (int *)malloc(tamanhoVetor * sizeof(int));
	copia(vetor, QuickVec, tamanhoVetor);
    printf("\nQuick sort: ");
    begin = clock();
    int swapcont = 0;
	quickSort(QuickVec, 0, tamanhoVetor-1, &swapcont);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTrocas: %d\nTempo: %f\n", swapcont, time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", QuickVec[i]);*/
	printf("\n");
    free(QuickVec);
	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void bubbleSort(int *A, int size){
   // implementação do Bubble
   int i, j, t, cont = 0;   
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {   
                swap((A + j), (A + i)); 
                cont++;
            } 
        } 
    }printf("Trocas: %d", cont);   
}

void printArray(int n, int* ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b){
   long temp=*(b);
   *b=*a;
   *a=temp;
};

void insertionSort(int *A, int size){
    // Implementação do Insertion
    int i,j, min, t;
    int cont=0;
    for (i = 1; i < size; i++) {   
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1]; 
            cont++;  
        }   
        A[j]=min;
    }printf("Trocas: %d", cont); 
}

void selectionSort(int *A, int size){
    // Implementação do Selection
    int cont = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        //find min index
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;

            }
        }
        //swap
        if (min_index != i) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
            cont++;
        }
    }printf("Trocas: %d", cont); 
}

void quickSort(int *A, int start, int end, int *swapcont){
    // Implementação do Quick
    int cont = 0;
    if (start < end) {
        // Encontra o índice de partição, arr[p] está agora no lugar correto
        int pi = partition(A, start, end, swapcont);
        // Recursivamente ordena os elementos antes e depois da partição
        quickSort(A, start, pi - 1, swapcont);
        quickSort(A, pi + 1, end, swapcont);
    }
}

int partition(int arr[], int low, int high, int *swapcont) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1);    // O índice do menor elemento
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*swapcont)++;
    return (i + 1);
}