#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int v[], int n);
void quicksort(int v[], int inicio, int fim);
void merge(int v[], int n);
void mergesort(int v[], int n);
void insertionsort(int v[], int n);
void seletionsort(int v[], int n);
void trocar(int *v1, int *v2);
void heapify(int v[], int n, int i);
void heapsort(int v[], int n);
void inicializarAleatoriamente(int v[], int n);
void inicializarOrdemCrescente(int v[], int n);
void inicializarOrdemDecrescente(int v[], int n);

int main(){

    srand(time(NULL));
    int n = 100000, i;
    int v[n];
    double start, stop, elapsed;
    start = (double) clock() / CLOCKS_PER_SEC;

    //inicializarOrdemDecrescente(v, n);
    //inicializarOrdemCrescente(v,n);
    inicializarAleatoriamente(v,n);

    //bubblesort(v,n);
    quicksort(v,0,n);
    //mergesort(v,n);
    //insertionsort(v,n);
    //seletionsort(v,n);
    //heapsort(v,n);

    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo total em segundos: %f\n", elapsed);

    return 0;
}


void inicializarAleatoriamente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = rand();
}

void inicializarOrdemCrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i;
}

void inicializarOrdemDecrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = n-i;
}


void bubblesort(int v[], int n)
{
    int i, j;

    for(i = n - 1; i > 0; i--) {

        for(j = 0; j < i; j++) {

            if(v[j] > v[j+1])

            {

                int aux;
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

            }
        }
    }
}

void quicksort(int v[], int inicio, int fim)
{
    int i=inicio, j=fim-1, aux=0, pivo;
    pivo = v[(inicio+fim)/2];

    while(i <= j){

        while(v[i] < pivo && i < fim)
            i++;

        while(v[j] > pivo && j > inicio)
            j--;

        if(i <= j){

            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;

        }
    }

    if(j > inicio)
        quicksort(v, inicio, j+1);

    if(i < fim)
        quicksort(v, i, fim);
}


void merge(int v[], int n) {

    int i=0, j=(n/2), k=0;
    int *aux, meio=j;

    aux = (int *)malloc(n*sizeof(int));

    if (aux == NULL)
        return 0;

    while (i<meio && j<n) {

        if (v[i] < v[j]) {

            aux[k] = v[i];
            i++;

        }else {

            aux[k] = v[j];
            j++;

        }

        k++;

    }

    if (i<meio) {

        while (i<meio) {

            aux[k] = v[i];
            i++;
            k++;

        }
    }else {

        while (j<n) {

            aux[k] = v[j];
            j++;
            k++;

        }

    }

    for (i=0 ; i<n ; i++)
        v[i] = aux[i];

    free(aux);
}


void mergesort(int v[], int n) {

    int meio;

    if (n > 1) {

        meio = n/2;
        mergesort(v,meio);
        mergesort(v+meio,n-meio);
        merge(v,n);

    }

}


void insertionsort(int v[], int n) {

    int i, j, aux;

    for (i=1 ; i<n ; i++) {

        aux = v[i];
        j = (i-1);

        for ( ; (j>=0 && aux < v[j]) ; j--)
            v[j+1] = v[j];

        v[j+1] = aux;

    }


}


void seletionsort(int v[], int n) {

    int i, j, menor, aux;

    for (i=0 ; i<n ; i++) {

        menor = i;

        for (j=(i+1) ; j<n ; j++) {

            if (v[j] < v[menor])
                menor = j;

        }

        if (v[menor] != v[i]) {

            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }


}


void trocar(int *v1, int *v2) {
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}


void heapify(int v[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && v[esq] > v[maior])
        maior = esq;

    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i) {
        trocar(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}


void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i >= 0; i--) {

        trocar(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}

