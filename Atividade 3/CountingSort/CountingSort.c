#include <stdio.h>
#include <stdlib.h>

void CountingSort(int A[],int k,int n){
    int i,j,p;
    int C[k];//array auxiliar
    int B[k];//array de saida
    
    for(i = 0; i <= k; i++){ //zera todos os elementos do array auxiliar
        C[i] = 0;
    }
    for(j = 0; j <= (n - 1); j++){ //adiciona 1 em cada indice do auxiliar equivalente ao elemento em A
        C[A[j]] = C[A[j]] + 1;
    }
    
    /*soma cada par do array atualiando o segundo numero para representar quantos numeros sao menores do
     que cada elemento x*/
    for(i = 1; i <= k; i++){
        C[i] = C[i] + C[i-1];
    }
    
    /*comecando pela direita os elementos de A sao colocados em B com o indice equivalente ao elemento
     em C - 1*/
    for(j = (n - 1); j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for(p = 0; p <= (n - 1); p++){
        printf("%d,", B[p]);
    }
    
}

int main(){
    int k = 10;
    int n = 10;
    int A[10] = {5,2,9,0,1,3,7,6,8,4};
    
    CountingSort(A, k, n);
}
