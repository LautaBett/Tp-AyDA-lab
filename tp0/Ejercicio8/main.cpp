/**Escribir un programa que permita cargar un arreglo de números enteros a partir de información
provista por el usuario, y luego visualice estos valores pero en el orden inverso al ingresado.
Entrada al programa: dos líneas de texto que indican la cantidad de valores a ingresar y los valores en
sí, separados por un espacio. Por ejemplo:
5
10 2 3 1 7
Salida del programa: los valores, separados por un espacio, en el orden inverso al ingresado.
7 1 3 2 10
*/

#include <iostream>
using std::cout;
using std::endl;

using namespace std;

int obtenerTamano() {
    int tamano;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tamano;
    return tamano;
}

void CargarArreglo(int tamano, int arr[]){

    cout<< "ingrese el arreglo " << endl;
    for(int i = 0; i<=tamano; i++){
        cin >> arr[i];
    }
}

int Darvuelta(int arr[], int tamano){
    int dadoVuelta[tamano];
    int j = 0;
    for(int i = tamano; i>=0; i--){
        dadoVuelta[j] == arr[i];
        j++;
    }
    return dadoVuelta;
}


void mostrarArreglo(int arreglo[], int tamano) {
    cout << "Arreglo ingresado: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main() {
    int tamano = obtenerTamano();
    int arr[tamano];
    CargarArreglo(tamano, arr);
    mostrarArreglo(arr, tamano);
    int dadoVuleta[] = Darvuelta(arr, tamano);
    mostrarArreglo(dadoVuelta, tamano);
}

    cout << "Arreglo ingresado: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;



int main()
{
