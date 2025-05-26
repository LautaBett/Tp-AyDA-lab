#include <iostream>
#include <vector> // Usado solo para facilitar la impresión en este ejemplo, las funciones de ordenamiento usan arreglos C-style.
#include <algorithm> // Para std::copy, si se usa para duplicar arreglos

// --- Funciones Auxiliares ---
// Función para intercambiar dos elementos (usada por Quicksort)
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// --- Implementación de Mergesort ---

// Función para combinar dos subarreglos ordenados: arr[l..m] y arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    // Crear arreglos temporales
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2]; // Usar asignación dinámica si n1 o n2 pueden ser muy grandes

    // Copiar datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Intercalar los arreglos temporales de vuelta en arr[l..r]
    int i = 0; // Índice inicial del primer subarreglo
    int j = 0; // Índice inicial del segundo subarreglo
    int k = l; // Índice inicial del subarreglo combinado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Mergesort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encuentra el punto medio para evitar overflow
        int m = l + (r - l) / 2;

        // Ordena la primera y segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Combina las mitades ordenadas
        merge(arr, l, m, r);
    }
}

// --- Implementación de Quicksort ---

// Esta función toma el último elemento como pivote, coloca
// el pivote en su posición correcta en el arreglo ordenado,
// y coloca todos los menores (menores que el pivote)
// a la izquierda del pivote y todos los mayores a la derecha.
// (Esquema de partición de Lomuto)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivote (último elemento)
    int i = (low - 1);     // Índice del elemento más pequeño encontrado hasta ahora

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++; // incrementa el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Coloca el pivote en su lugar
    return (i + 1); // Devuelve el índice de partición
}

// Función principal de Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi es el índice de partición, arr[pi] está ahora en el lugar correcto
        int pi = partition(arr, low, high);

        // Ordena separadamente los elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// --- Función Main para Pruebas ---
int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7, 22, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {12, 11, 13, 5, 6, 7, 22, 3, 9}; // Copia para Quicksort
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Arreglo original: ";
    printArray(arr1, n1);

    // Prueba de Mergesort
    std::cout << "\nOrdenando con Mergesort...\n";
    mergeSort(arr1, 0, n1 - 1);
    std::cout << "Arreglo ordenado con Mergesort: ";
    printArray(arr1, n1);

    std::cout << "\n----------------------------------\n";

    std::cout << "\nArreglo original (para Quicksort): ";
    printArray(arr2, n2);

    // Prueba de Quicksort
    std::cout << "\nOrdenando con Quicksort...\n";
    quickSort(arr2, 0, n2 - 1);
    std::cout << "Arreglo ordenado con Quicksort: ";
    printArray(arr2, n2);

    // Otro ejemplo
    int arr3[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int arr4[n3];
    std::copy(arr3, arr3 + n3, arr4);


    std::cout << "\n\nArreglo original 2: ";
    printArray(arr3, n3);

    std::cout << "\nOrdenando con Mergesort...\n";
    mergeSort(arr3, 0, n3 - 1);
    std::cout << "Arreglo ordenado con Mergesort: ";
    printArray(arr3, n3);

    std::cout << "\n----------------------------------\n";

    std::cout << "\nArreglo original 2 (para Quicksort): ";
    printArray(arr4, n3);

    std::cout << "\nOrdenando con Quicksort...\n";
    quickSort(arr4, 0, n3 - 1);
    std::cout << "Arreglo ordenado con Quicksort: ";
    printArray(arr4, n3);


    return 0;
}