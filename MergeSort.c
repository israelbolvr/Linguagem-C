#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 10000

void print(int[]);
void Mergesort(int[], int, int);
void intercala(int[], int, int, int);

int main(void) {
    time_t t;
    int i, A[N];

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    for (int j = 0; j < N; j++){

        /* Intializes vector with random numbers */
        for (i = 0; i < N; i++)
            A[i] = (int) rand()%MAX;
        print(A);

        Mergesort(A, 0, N - 1);
        print(A);

        /* Checks wether vector is sorted or not */
        i = 0;
        while (i < N-1 && A[i] <= A[i+1])
            i++;
        printf("%s\n\n\n", i == N-1 ? "ok" : "error");
    }

    return 0;
}

void Mergesort(int *v, int l, int r) {
     if (l < r) {
        int m = (l + r) / 2;
        Mergesort(v, l, m);
        Mergesort(v, m, r);
        intercala(v, l, m, r);
     }
}

void intercala(int *v, int l, int m, int r) {
     int*aux, i, j, k, n1, n2;

     
     
}

void print(int v[]){
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}
