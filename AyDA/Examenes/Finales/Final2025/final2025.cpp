#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Función auxiliar que cuenta cuántas veces aparece 'valor' entre A[l..r]
int contarFrecuencia(const vector<int>& A, int l, int r, int valor) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (A[i] == valor)
            count++;
    }
    return count;
}

// Función principal recursiva que aplica Divide y Conquista
// Devuelve el par (número más frecuente, frecuencia) en el intervalo A[l..r]
pair<int, int> masFrecuente(const vector<int>& A, int l, int r) {
    // CASO BASE: si hay un solo elemento, ese es el más frecuente (1 vez)
    if (l == r) return {A[l], 1};

    // Dividimos el intervalo a la mitad
    int mid = (l + r) / 2;

    // Llamamos recursivamente a la mitad izquierda y derecha
    auto [izqValor, izqFreq] = masFrecuente(A, l, mid);
    auto [derValor, derFreq] = masFrecuente(A, mid + 1, r);

    // IMPORTANTE: volvemos a contar cuántas veces aparece cada candidato
    // en el intervalo total A[l..r]
    int freqIzq = contarFrecuencia(A, l, r, izqValor);
    int freqDer = contarFrecuencia(A, l, r, derValor);

    // Retornamos el que tenga mayor frecuencia total en el intervalo
    if (freqIzq >= freqDer)
        return {izqValor, freqIzq};
    else
        return {derValor, freqDer};
}

// Función envoltorio que inicia la recursión sobre todo el arreglo
int numeroMasFrecuente(const vector<int>& A) {
    if (A.empty()) return -1; // Caso especial si el arreglo está vacío
    return masFrecuente(A, 0, A.size() - 1).first;
}

int main() {
    // Ejemplo de uso con arreglo ordenado
    vector<int> A = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4};

    // Mostramos el resultado
    cout << "Número más frecuente: " << numeroMasFrecuente(A) << endl;

    return 0;
}

