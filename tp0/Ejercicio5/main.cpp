#include <iostream>
#include <cmath> // Para pow()

using namespace std;

int main() {
    double monto_inicial, tasa_anual = 0.35, monto_final, rentabilidad;
    int dias;

    // Entrada de datos
    cout << "Ingrese el monto inicial: ";
    cin >> monto_inicial;
    cout << "Ingrese el plazo en días: ";
    cin >> dias;

    // Conversión de días a años
    double t = dias / 365.0;

    // Cálculo del monto final con interés compuesto
    monto_final = monto_inicial * pow(1 + (tasa_anual / 12), 12 * t);

    // Cálculo de la rentabilidad
    rentabilidad = monto_final - monto_inicial;

    // Mostrar resultados
    cout << "Monto final acumulado: $" << monto_final << endl;
    cout << "Rentabilidad obtenida: $" << rentabilidad << endl;

    return 0;
}
