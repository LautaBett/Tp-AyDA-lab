#include <iostream>
#include <vector>
#include <climits> // Para INT_MIN y INT_MAX
using namespace std;

// Función para encontrar la mediana de dos vectores ordenados
double encontrarMediana(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
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

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        }
        else if (maxLeftX > minRightY) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }

    // En teoría, no deberíamos llegar acá si los vectores están ordenados y tienen el mismo tamaño
    return -1.0;
}

int main() {
    vector<int> X = {1, 3, 8, 9, 15};
    vector<int> Y = {7, 11, 18, 19, 21};

    double mediana = encontrarMediana(X, Y);
    cout << "La mediana es: " << mediana << endl;

    return 0;
}
