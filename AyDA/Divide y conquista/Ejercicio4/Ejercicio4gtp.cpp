#include <iostream>
#include <climits> // para INT_MIN y INT_MAX
using namespace std;

// Encuentra la mediana de dos arreglos ordenados de tamaño n (sin mezclarlos)
// Tiempo: O(log n)
double encontrarMediana(int X[], int Y[], int n) {
    int low = 0;
    int high = n;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = n - i;

        int maxLeftX;
        if (i == 0) {
            maxLeftX = INT_MIN;
        } else {
            maxLeftX = X[i - 1];
        }

        int minRightX;
        if (i == n) {
            minRightX = INT_MAX;
        } else {
            minRightX = X[i];
        }

        int maxLeftY;
        if (j == 0) {
            maxLeftY = INT_MIN;
        } else {
            maxLeftY = Y[j - 1];
        }

        int minRightY;
        if (j == n) {
            minRightY = INT_MAX;
        } else {
            minRightY = Y[j];
        }

        // Verificamos si encontramos la partición correcta
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Es par → promedio entre los del medio
            return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        }
        else if (maxLeftX > minRightY) {
            // Estás muy a la derecha en X → movete a la izquierda
            high = i - 1;
        }
        else {
            // Estás muy a la izquierda en X → movete a la derecha
            low = i + 1;
        }
    }

    // No debería pasar si los vectores están bien
    return -1;
}

int main() {
    int X[] = {1, 3, 8, 9, 15};
    int Y[] = {7, 11, 18, 19, 21};
    int n = sizeof(X) / sizeof(X[0]);

    double mediana = encontrarMediana(X, Y, n);
    cout << "La mediana es: " << mediana << endl;

    return 0;
}
