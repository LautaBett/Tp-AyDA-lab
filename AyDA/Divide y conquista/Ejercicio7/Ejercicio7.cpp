/*Tu plataforma de e-commerce administra un arreglo ordenado S que contiene n cupones,
representados por valores monetarios enteros y distintos. Dado un valor entero x (que representa
un precio objetivo de compra), se desea determinar si existe al menos un par de cupones en el
arreglo cuya suma sea exactamente igual a x
a) Implementar un algoritmo en C++ que permita determinar si existe dicho par de cupones.
b) Calcule la complejidad temporal.*/

//x representa precio objetivo, existen 2 cupones que su suma de x

#include <iostream>
#include <vector>
using namespace std;


bool buscar(const vector<int>& dato, int x) {     //complejidad n cuadrada
    for (int i = 0; i < dato.size(); i++) {
        for (int j = dato.size() -1; j > i; j--) {
            if (dato[i] + dato[j] == x) {
                return true;
            }
        }
    }
    return false;
}

bool buscarOptimizado(const vector<int>& dato, int x) { // comlejidad n
    int i = 0;
    int j = dato.size() - 1;

    while (i < j) {
        int suma = dato[i] + dato[j];
        if (suma == x) {
            return true;
        } else if (suma < x) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}


bool buscarBinaria(const vector<int>& arr, int inicio, int fin, int objetivo) {
    while (inicio <= fin) {
        int mid = (inicio + fin) / 2;
        if (arr[mid] == objetivo) return true;
        else if (arr[mid] < objetivo) inicio = mid + 1;
        else fin = mid - 1;
    }
    return false;
}

bool buscarConDivideYConquista(const vector<int>& arr, int inicio, int fin, int x) {
    if (inicio >= fin) return false;

    int mid = (inicio + fin) / 2;
    int complemento = x - arr[mid];

    // Buscar el complemento en el lado opuesto al actual (sin usar el mismo índice)
    if (buscarBinaria(arr, inicio, mid - 1, complemento) || buscarBinaria(arr, mid + 1, fin, complemento)) {
        return true;
    }

    // Repetir recursivamente en ambas mitades
    return buscarConDivideYConquista(arr, inicio, mid - 1, x) ||
           buscarConDivideYConquista(arr, mid + 1, fin, x);
}


int main() {
    vector<int> cupones = {5, 10, 15, 20, 25, 30}; // arreglo ordenado
    int objetivo = 35;



    if (buscarConDivideYConquista(cupones, 0, cupones.size() - 1, objetivo)) {
        cout << "Existe un par de cupones cuya suma es " << objetivo << endl;
    } else {
        cout << "No existe tal par de cupones." << endl;
    }

    if (buscar(cupones, objetivo)) {
        cout << "Existe al menos un par de cupones cuya suma es " << objetivo << "." << endl;
    } else {
        cout << "No existe un par de cupones que sumen " << objetivo << "." << endl;
    }

    if (buscarOptimizado(cupones, objetivo)) {
        cout << "Existe al menos un par de cupones cuya suma es " << objetivo << "." << endl;
    } else {
        cout << "No existe un par de cupones que sumen " << objetivo << "." << endl;
    }



    return 0;
}
