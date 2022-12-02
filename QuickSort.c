#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void quicksort(int v[], int inicio, int fim){
  if(inicio<fim){
    int pivo = particao(v, inicio, fim);
    quicksort(v, inicio, pivo-1);
    quicksort(v, pivo+1, fim);
  }
}

int particao(int v[], int inicio, int fim){
  int aux, pivo, index, i, j;
  index = (rand()%(fim-inicio))+inicio;
  index = (rand()%(fim-inicio))+inicio;
  aux = v[index];
  v[index] = v[fim];
  v[fim] = aux;
  pivo = v[fim];
  i = inicio;
  for(j = inicio; j<fim; j++){
    if(v[j]<=pivo){
      aux=v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
    }
  }
  aux = v[i];
  v[i] = v[fim];
  v[fim] = aux;
  return i;
}

void print(int v[]){
  for(int i = 0; i<MAX; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int main(void){
  int *A;
  A = (int *)malloc(sizeof(int)*MAX);
  int tamanho = 0;
  for(int l = 0; l < 20; l++){
    for (int i = 0; i<MAX; i++){
      A[i] = (int)rand()%10000;
      tamanho++;
    }
    print(A);
    quicksort(A, 0, MAX-1);
    print(A);
    printf("\n");
  } 


  

  return 0;
}
