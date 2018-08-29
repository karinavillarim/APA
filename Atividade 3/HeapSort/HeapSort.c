#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y){ //Funcao para trocar dois elementos de posicao usando um auxiliar
    int s;
    s = *x;
    *x = *y;
    *y = s;
}

void MaxHeapify(int A[], int comprimento, int i){ //Faz o Heap Maximo
    int L = (2*i) + 1; //equacao do filho da esquerda
    int R = (2*i) + 2; //equacao do filho da direita
    int maior = i;
    
    //compara qual dos filhos eh maior, o da esquerda ou direita
    if(L < comprimento && A[L] > A[maior]){
        maior = L;
    }
    if(R < comprimento && A[R] > A[maior]){
        maior = R;
    }
    //se o maior nao for o pai ele troca de lugar com o maior de seus filhos
    if(maior != i){
        swap(&A[i], &A[maior]);
        MaxHeapify(A, maior, comprimento);
    }
}

void BuildMaxHeap(int A[], int comprimento){
    int i;
    
    //calcula qual eh o ultimo pai que possui filhos da arvore binaria para comecar o MaxHeapify
    for(i = floor(comprimento/2) - 1; i >= 0; i--){
        MaxHeapify(A, comprimento, i);
    }
}


void HeapSort(int A[], int comprimento){
    int i;
    BuildMaxHeap(A, comprimento);
    for (i = (comprimento - 1); i >= 0; i--){
        swap(&A[0], &A[i]);
        MaxHeapify(A, i, 0);
    }
}

int main(){
    int comprimento = 10;
    int A[10] = {5,2,9,0,1,3,7,6,8,4};
    int p;
    
    HeapSort(A, comprimento);
    
    for(p = 0; p <= (comprimento - 1); p++){
        printf("%d,", A[p]);
    }
}
