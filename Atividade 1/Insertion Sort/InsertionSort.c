#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 10

void InsertionSort(int *array){
    int i, j;
    int pivo;
    
    for(i = 1; i <= MAX_ELEMENTOS - 1; i++){
        
        pivo = *(array + i);
        j = i - 1;
        
        while(j >= 0 && *(array + j) > pivo){
            
            *(array + (j+1)) = *(array + j);
            j = j - 1;
            
        }
        *(array + (j+1)) = pivo;
    }
}

int main(void){
    
    int array1[MAX_ELEMENTOS] = {4,2,9,5,1,7,8,3,0,6}; //caso aleatório
    int array2[MAX_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9}; //melhor caso (ordenado)
    int array3[MAX_ELEMENTOS] = {9,8,7,6,5,4,3,2,1,0}; //pior caso (ordenado ao contrário)
    int i = 0;
    
    InsertionSort(array1);
    
    printf("{");
    for(i = 0; i <= MAX_ELEMENTOS - 1; i++){
        printf("%d,", array[i]);
    }
    printf("}");
    
    return 0;
}
