#include "../sorts/sorts.h"

int main(void){
int arr[] = {5, 2, 123, 1, 5, 6};
int n = 6;

heapSort(arr,n);

// Imprime o array ordenado
for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
}
}