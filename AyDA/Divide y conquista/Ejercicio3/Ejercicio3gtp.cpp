#include <iostream>
using namespace std;

// Busca el primer índice donde arr[i] >= x
int buscar(int arr[], int n, int x) {
    int izq = 0, der = n - 1, res = n;
    while (izq <= der) {
        int mid = (izq + der) / 2;
        if (arr[mid] >= x) {
            res = mid;
            der = mid - 1;
        } else {
            izq = mid + 1;
        }
    }
    return res;
}


// Búsqueda binaria normal para verificar si un valor está exactamente
bool existeValor(int arr[], int n, int valor) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int mid = (izq + der) / 2;
        if (arr[mid] == valor) return true;
        else if (arr[mid] < valor) izq = mid + 1;
        else der = mid - 1;
    }
    return false;
}

int contarEnRango(int arr[], int n, int x, int y) {
    int inicio = buscar(arr, n, x);
    int fin = buscar(arr, n, y);

    if (!existeValor(arr, n, x)) {
        cout << "El mínimo (" << x << ") no está en el arreglo." << endl;
    }
    if (!existeValor(arr, n, y)) {
        cout << "El máximo (" << y << ") no está en el arreglo." << endl;
    }

    if (inicio <= fin) {
        return fin - inicio + 1;
    }
    return 0;
}

int main() {
    int arr[] = {-10, -5, 2, 3, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int y = 8;

    int cantidad = contarEnRango(arr, n, x, y);

    cout << "Cantidad de elementos entre " << x << " y " << y << ": " << cantidad << endl;

    return 0;
}
