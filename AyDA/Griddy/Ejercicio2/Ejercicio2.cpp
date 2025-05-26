#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tarea {
    int ganancia, plazo;
};

bool cmp(Tarea a, Tarea b) {
    return a.ganancia > b.ganancia; // Mayor ganancia primero
}

int planificarTareas(vector<Tarea>& tareas) {
    sort(tareas.begin(), tareas.end(), cmp);

    int n = tareas.size();
    vector<bool> tiempo(n, false); // Tiempo ocupado o no, pone n timepos en false
    int gananciaTotal = 0;

    for (auto& t : tareas) {
        // Buscar el último tiempo libre antes del plazo
        for (int j = min(n, t.plazo) - 1; j >= 0; j--) { // el min(n, t.plazo) - 1 es para evitar que se salga del vector, 
            if (!tiempo[j]) {   // Si el tiempo está libre
                tiempo[j] = true;  // Marcar como ocupado
                gananciaTotal += t.ganancia;
                break;
            }
        }
    }

    return gananciaTotal;
}

int main() {
    vector<Tarea> tareas = {
        {50, 2},
        {10, 1},
        {15, 2},
        {30, 1}
    };

    int ganancia = planificarTareas(tareas);
    cout << "Ganancia maxima: " << ganancia << endl;

    return 0;
}
