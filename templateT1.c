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

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
// void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
// void quickSort(int *A, int size);

void printArray(int n, int* ptr);
void swap (int *a, int *b);


int main(){

	int i;
	int tamanhoVetor = 1000;
    int vetor[tamanhoVetor];

    for (i = 0 ; i < tamanhoVetor ; i++)
        vetor[i] = (tamanhoVetor-i);

	printf("\nVetor original: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", vetor[i]);

	printf("\nVetor tamanho = %d\n", tamanhoVetor);

	// bubble sort
	int bubbleVec[tamanhoVetor];
	copia(vetor, bubbleVec, tamanhoVetor);
	bubbleSort(bubbleVec, tamanhoVetor);
	printf("\nBubble sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", bubbleVec[i]);
	printf("\n");

	// selection sort

	// insertion sort
    int InsertVec[tamanhoVetor];
	copia(vetor, InsertVec, tamanhoVetor);
	bubbleSort(InsertVec, tamanhoVetor);
	printf("\nInsertion sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", InsertVec[i]);
	printf("\n");

	// quick sort

	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void bubbleSort(int *A, int size){
   // implementação do Bubble
   int i, j, t;   
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {   
                swap((A + j), (A + i)); //Questão 5 - O parâmetro desta função são valores ou ponteiros? Explique. 
            } 
        } 
    }   
}

void printArray(int n, int* ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
};

void insertionSort(int *A, int size){
    // Implementação do Insertion
    int i,j, min, t;
    int contador=0;
    for (i = 1; i < size; i++) {   
        
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1];
           
        }   
        A[j]=min;
    }
}