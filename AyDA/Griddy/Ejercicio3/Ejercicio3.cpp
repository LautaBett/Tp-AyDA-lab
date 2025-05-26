#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recibe vector con los tiempos de ejecución
int minimizarTiempoEspera(vector<int>& tiempos) {
    sort(tiempos.begin(), tiempos.end()); // Orden ascendente

    int tiempoEspera = 0;
    int acumulado = 0;

    for (int i = 0; i <= tiempos.size(); i++) {
        tiempoEspera += acumulado;       // sumamos el tiempo que esperó este proceso
        acumulado += tiempos[i];         // este proceso suma al total acumulado
    }

    return tiempoEspera;
}

int main() {
    vector<int> tiempos = {5, 10, 3};  // tiempos de ejecución de los procesos

    int resultado = minimizarTiempoEspera(tiempos);
    cout << "Tiempo total de espera minimo: " << resultado << endl;

    return 0;
}
