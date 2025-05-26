/*Se tiene un arreglo T de n enteros distintos, ordenado en forma creciente. Dado un rango definido
por dos valores enteros x e y, con la condición de que x ≤ y, se requiere implementar un algoritmo
en C++ que determine cuántos elementos del arreglo T se encuentran comprendidos entre x e y,
inclusive. La complejidad temporal de su algoritmo debe pertenecer a O(log n).*/

#include <iostream>
using namespace std;

int encontrarIndiceIgualValor(int arr[], int init, int fin, int x, int y) {
    int resu = 0;
    if (init > fin) {
        return resu;
    }

    int mid = (fin - init) / 2 + init;

    if (arr[mid] == x || arr[mid] == y) {
        resu++;
    } else if (arr[mid] > x) {
        return encontrarIndiceIgualValor(arr, init, mid - 1);
    } else if (arr[mid] < y){
        return encontrarIndiceIgualValor(arr, mid + 1, fin);
    }
}

int main() {
    int x = 2;
    int y = 4;

    int arr[] = {-10, -5, 0, 3, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int resultado = encontrarIndiceIgualValor(arr, 0, n - 1);

    if (resultado != -1)
        cout << "Índice encontrado: " << resultado << endl;
    else
        cout << "No existe tal índice." << endl;

    return 0;
}