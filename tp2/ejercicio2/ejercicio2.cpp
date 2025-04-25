/*Pedir al usuario que ingrese un valor N natural. Crear un arreglo de N enteros,
llenarlo con valores aleatorios entre 1 y 100 e imprimirlo.*/

#include <iostream>
#include <cstdlib> //para usar las funciones rand() y srand()
#include <ctime> //para usar la función time

using namespace std;

int main(){
    
    int n;

    cout << "pasame un valor N natural: "<< endl;
    cin >> n;
    
    int* arreglo = new int[n]; // Crear un arreglo dinámico de tamaño N, arreglo no almacenará un número entero directamente, sino que almacenará una dirección de memoria, new: Es el operador de C++ para solicitar memoria dinámica. Esta memoria se asigna desde el Heap 

    // --- Llenado con Valores Aleatorios ---
    // Inicializar la semilla del generador aleatorio
    srand(time(0));

    cout << "llenando el arreglo con valores random" << endl;
    for (int i = 0; i < n ; i ++){
        arreglo[i] = rand() % 100 + 1; // Llenar el arreglo con valores aleatorios entre 1 y 100, arreglo es el puntero    
    }
    cout << "arreglo lleno" << endl;
    // --- Imprimir el Arreglo ---
    cout << "El arreglo es: " << endl;

    for(int j = 0; j<n; j++){
        cout << arreglo[j] << " "; // Imprimir el arreglo
    }

    delete[] arreglo;
    cout << "Memoria del Heap liberada." << endl;
    arreglo = nullptr; // Buena práctica para evitar punteros colgantes
}