#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int array[], int p, int q, int r){
    int i, j, k; //indice do primeiro subarray, do segundo, do array que sofreu o merge
    int a = q - p + 1;
    int b =  r - q;
    
    int L[a], R[b]; //Divisao do array em duas partes
    
    for (i = 0; i < a; i++)
        L[i] = array[p + i];
    for (j = 0; j < b; j++)
        R[j] = array[q + 1 + j];
    
    for (k = p; k <= r; k++){ //Juntando os subarrays em um so
        if (L[i] < R[j])
        {
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
    }
    
    while (i < a){ //Copiando o resto dos elementos do subarray da esquerda
        array[k] = L[i];
        i++;
        k++;
    }
    
    
    while (j < b){ //Copiando o resto dos elementos do subarray da direita
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int p, int r){
    if (p < r){ //Se o indice da esquerda nao ultrapassou o da direita
        int q;
        q = floor((p + r)/2);
        
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        
        Merge(array, p, q, r);
    }
}
