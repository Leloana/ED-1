#include "sorts.h"

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {    
        // laço interno para percorrer o array
        for (j = 0; j < n - i - 1; j++) {
            // troca os elementos adjacentes se eles estiverem na ordem errada
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    // laço externo para percorrer o array
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        // laço interno para encontrar o menor elemento restante no array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // troca o menor elemento com o primeiro elemento não ordenado
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
// Função de particionamento
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
// Função QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    // laço externo para percorrer o array
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // move os elementos maiores para a direita do array
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Função para mesclar dois subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // cria subarrays temporários
    int L[n1], R[n2];
    
    // copia os dados para os subarrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // mescla os subarrays temporários em arr[l..r]
    i = 0; // índice inicial do subarray da esquerda
    j = 0; // índice inicial do subarray da direita
    k = left; // índice inicial do subarray mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Função Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // ordena as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // mescla as duas metades
        merge(arr, left, mid, right);
    }
}
// função para construir um max-heap
void heapify(int arr[], int n, int i) {
    int largest = i; // inicializa o maior como raiz
    int left = 2 * i + 1; // índice do filho esquerdo
    int right = 2 * i + 2; // índice do filho direito
    
    // se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // se o filho direito for maior que a raiz
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // se o maior não for a raiz
    if (largest != i) {
        // troca a raiz com o maior
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // chama a função heapify recursivamente no subárvore afetado
        heapify(arr, n, largest);
    }
}
// Função Heap Sort
void heapSort(int arr[], int n) {
    // constrói o heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // extrai um por um os elementos do heap
    for (int i = n - 1; i >= 0; i--) {
        // move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // chama a função heapify no heap reduzido
        heapify(arr, i, 0);
    }
}
