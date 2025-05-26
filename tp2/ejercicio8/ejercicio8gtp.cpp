#include <iostream>
#include <vector>
#include <cmath> // Para floor

using namespace std;

// --- Búsqueda Binaria Iterativa en Arreglo (Vector) ---
// Retorna el índice si lo encuentra, -1 si no.
// Precondición: El arreglo 'arr' DEBE estar ordenado.
// Complejidad: O(log N)
int busquedaBinariaArray(const vector<int>& arr, int buscado, int& operaciones) {
    operaciones = 0;
    int bajo = 0;
    int alto = arr.size() - 1;
    int medio;

    while (bajo <= alto) {
        // Calcular el índice medio
        medio = bajo + floor((alto - bajo) / 2.0); // Evita overflow para índices grandes
        operaciones++; // Contar la comparación principal

        cout << "  Buscando... bajo=" << bajo << ", alto=" << alto << ", medio=" << medio << ", arr[medio]=" << arr[medio] << endl;


        if (arr[medio] == buscado) {
            cout << "    -> Encontrado en indice " << medio << endl;
            return medio; // Encontrado
        } else if (arr[medio] < buscado) {
             cout << "    -> Buscado es mayor, ajustando bajo a " << medio + 1 << endl;
            bajo = medio + 1; // Buscar en la mitad derecha
        } else { // arr[medio] > buscado
             cout << "    -> Buscado es menor, ajustando alto a " << medio - 1 << endl;
            alto = medio - 1; // Buscar en la mitad izquierda
        }
    }

    cout << "  -> No encontrado (bajo > alto)" << endl;
    return -1; // No encontrado
}

int main() {
    vector<int> arreglo = {-1, 1, 4, 9}; // Arreglo ordenado
    int ops;
    int buscado;

    cout << "Arreglo: [ -1 1 4 9 ]" << endl;

    // --- Pruebas ---
    buscado = 4;
    cout << "\n--- Buscando " << buscado << " (Binaria) ---" << endl;
    int idx = busquedaBinariaArray(arreglo, buscado, ops);
    cout << "Resultado: " << (idx != -1 ? "Encontrado en indice " + to_string(idx) : "No encontrado") << " (Ops: " << ops << ")" << endl;

     buscado = -1;
    cout << "\n--- Buscando " << buscado << " (Binaria) ---" << endl;
    idx = busquedaBinariaArray(arreglo, buscado, ops);
    cout << "Resultado: " << (idx != -1 ? "Encontrado en indice " + to_string(idx) : "No encontrado") << " (Ops: " << ops << ")" << endl;

    buscado = 0; // No está
    cout << "\n--- Buscando " << buscado << " (Binaria) ---" << endl;
    idx = busquedaBinariaArray(arreglo, buscado, ops);
    cout << "Resultado: " << (idx != -1 ? "Encontrado en indice " + to_string(idx) : "No encontrado") << " (Ops: " << ops << ")" << endl;

    buscado = 10; // No está
    cout << "\n--- Buscando " << buscado << " (Binaria) ---" << endl;
    idx = busquedaBinariaArray(arreglo, buscado, ops);
    cout << "Resultado: " << (idx != -1 ? "Encontrado en indice " + to_string(idx) : "No encontrado") << " (Ops: " << ops << ")" << endl;


    return 0;
}