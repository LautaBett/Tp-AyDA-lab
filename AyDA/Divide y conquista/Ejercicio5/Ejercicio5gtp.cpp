#include <iostream>
using namespace std;

int encontrarPico(int arr[], int n) {
    int izq = 0, der = n - 1;

    while (izq < der) {
        int mid = (izq + der) / 2;

        // Comparamos valores del arreglo, no índices
        if (arr[mid] < arr[mid + 1]) {
            // Estamos en la parte creciente
            izq = mid + 1;
        } else {
            // Estamos en la parte decreciente o en el pico
            der = mid;
        }
    }

    // izq == der en este punto, que es el índice del pico
    return izq;
}

int main() {
    int arr[] = {3,4,5,4,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int indicePico = encontrarPico(arr, n);
    cout << "El índice del pico es: " << indicePico << endl;
    cout << "Valor del pico: " << arr[indicePico] << endl;

    return 0;
}
