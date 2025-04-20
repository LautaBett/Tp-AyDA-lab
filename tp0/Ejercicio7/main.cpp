#include <iostream>
using namespace std;

// Función para calcular la frecuencia de un número en el arreglo
int Frecuencia(int arreglo[], int num, int tamano) {
    int frecuencia = 0;
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == num)
            frecuencia++;
    }
    return frecuencia;
}

// Función para encontrar el elemento más repetido y su frecuencia
int MasRepetido(int arreglo[], int tamano) {
    int maxFrecuencia = 0;
    for (int i = 0; i < tamano; i++) {
        int frecuencia = Frecuencia(arreglo, arreglo[i], tamano);
        if (maxFrecuencia < frecuencia)
            maxFrecuencia = frecuencia;
    }
    return maxFrecuencia;
}

// Función para ingresar el arreglo por teclado
void ingresarArreglo(int arreglo[], int tamano) {
    cout << "Ingrese los " << tamano << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamano; i++) {
        cin >> arreglo[i];
    }
}

// Función para mostrar el arreglo
void mostrarArreglo(int arreglo[], int tamano) {
    cout << "Arreglo ingresado: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Función para mostrar si existe un elemento mayoría
void mostrarMayoria(int arreglo[], int tamano) {
    int mayorFrecuencia = MasRepetido(arreglo, tamano);
    if (mayorFrecuencia > tamano / 2) {
        cout << "El elemento mayoria existe, y aparece " << mayorFrecuencia << " veces." << endl;
    } else {
        cout << "El elemento mayoria no existe" << endl;
    }
}


int obtenerTamano() {
    int tamano;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tamano;
    return tamano;
}

int main() {
    int tamano = obtenerTamano();
    int arreglo[tamano];
    ingresarArreglo(arreglo, tamano);
    mostrarArreglo(arreglo, tamano);
    mostrarMayoria(arreglo, tamano);
    return 0;
}

