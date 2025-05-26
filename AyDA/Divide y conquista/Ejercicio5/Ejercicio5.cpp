/*En aplicaciones de monitoreo (como salud, clima o rendimiento físico), es común analizar
secuencias de datos para identificar comportamientos que alcanzan un pico y luego decrecen, lo
que se conoce como una secuencia unimodal. Formalmente, una secuencia A = (a1, a2,. . . , an) de
longitud n ≥ 3 se llama unimodal si sus elementos primero aumentan y luego disminuyen, es decir
existe un índice p con 1 ≤ p ≤ n tal que a1 < a2 < · · · < ap y ap > ap+1 > · · · > an. Implemente un
algoritmo en C++ que dado un arreglo unidimensional que almacena una secuencia unimodal
encuentre el índice p. La complejidad temporal del algoritmo debe pertenecer a O(log n). */

#include <iostream>
using namespace std;

int buscar(int arr[], int n) {
    int izq = 0, der = n - 1, res = n;
    while (izq <= der) {
        int mid = (izq + der) / 2;
        int x= mid;
        if (arr[mid] >= x && x > arr[mid+1]) {
            der = mid - 1;
        } else  if (arr[mid]<= x && x < arr[mid+1]){
            izq = mid + 1;
        }else
            res = mid;
    }
    return res;
}



int encontrarIndiceIgualValor(int arr[], int init, int fin) {
    if (init > fin) {
        return -1;
    }

    int mid = (fin - init) / 2 + init;

    if (arr[mid] == mid) {
        return mid;
    } else if (arr[mid] > mid) {
        return encontrarIndiceIgualValor(arr, init, mid - 1);
    } else {
        return encontrarIndiceIgualValor(arr, mid + 1, fin);
    }
}