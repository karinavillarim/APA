#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){ //Funcao para trocar dois elementos de posicao usando um auxiliar
    int s;
    s = *x;
    *x = *y;
    *y = s;
}

int Partition (int array[], int l, int r){
    int pivo = array[r]; //Pivo como ultimo elemento do array
    int i = (l - 1); //Indice comeca antes do array
    
    for (int j = l; j <= r - 1; j++){ //Compara o elemento atual com o pivo
        if (array[j] <= pivo){
            i++; // Incrementa o indice do menor elemento
            swap(&array[i], &array[j]); //Coloca o elemento para o lado esquerdo do pivo
        }
    }
    i++;
    swap(&array[i], &array[r]);
    return i;
}

void QuickSort(int array[], int l, int r){
    if (l < r){
        int q;
        q = Partition(array, l, r);
        
        QuickSort(array, l, q - 1);
        QuickSort(array, q + 1, r);
    }
}
