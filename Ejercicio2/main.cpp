#include <iostream>
using namespace std;

int a = 20;

int main() {
    int b = 10;
    { // Inicio subbloque
        int b = 15;
        cout << "Dentro del subbloque:" << endl;
        cout << "Variable A: " << a << "\n";
        cout << "Variable B: " << b << "\n";
    } // Fin subbloque

    cout << "Fuera del subbloque:" << endl;
    cout << "Variable A: " << a << "\n";
    cout << "Variable B: " << b << "\n";

    return 0;
}
