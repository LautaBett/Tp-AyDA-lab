/*Implemente en C++ los métodos de ordenamiento mergesort y quicksort de forma tal que, dado
un arreglo de elementos comparables, ordenen sus elementos ascendentemente.*/

void MERGE_SORT(array A, int i, int d) {
    if (i < d) {
        int m = (i + d) / 2;
        MERGE_SORT(A, i, m);       // Conquista (mitad izquierda)
        MERGE_SORT(A, m + 1, d); // Conquista (mitad derecha)
        MERGE(A, i, m, d);       // Combina
    }
}

void QUICKSORT(array A, int i, int j) {
    if (i < j) { // Si hay más de un elemento
        int p = PARTICION(A, i, j); // Divide y coloca el pivote
        QUICKSORT(A, i, p - 1);     // Conquista (subarreglo izquierdo)
        QUICKSORT(A, p + 1, j);     // Conquista (subarreglo derecho)
    }
}