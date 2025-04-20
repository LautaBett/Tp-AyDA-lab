#include <iostream>
using namespace std;

int ObtenerTamano() {
    int tamano;
    cout << "Ingrese un tamaño para el arreglo: ";
    cin >> tamano;
    return tamano;
}

void CargarArreglo(int arr[], int tamano) {
    cout << "Ingrese los elementos del arreglo separados por espacios: " << endl;
    for (int i = 0; i < tamano; i++) {
        cin >> arr[i];
    }
}

void DarVuelta(int arr[], int tamano) {
    cout << "El arreglo en orden inverso es: ";
    for (int i = tamano - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int tamano = ObtenerTamano();
    int arr[tamano]; // Declarar el arreglo con tamaño dinámico (válido en C++ moderno)

    CargarArreglo(arr, tamano);
    DarVuelta(arr, tamano);

    return 0;
}
