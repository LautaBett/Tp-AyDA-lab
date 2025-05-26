#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Actividad {
    int comienzo, fin;
};

bool cmpFin(Actividad a, Actividad b) {
    return a.fin < b.fin;  // Ordenar por tiempo de fin
}

int seleccionarActividades(vector<Actividad>& actividades) {
    sort(actividades.begin(), actividades.end(), cmpFin);

    int seleccionadas = 0;
    int finAnterior = 0;

    for (auto& act : actividades) {
        if (act.comienzo >= finAnterior) {
            seleccionadas++;
            finAnterior = act.fin;
        }
    }

    return seleccionadas;
}

int main() {
    vector<Actividad> actividades = {
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 9}
    };

    int total = seleccionarActividades(actividades);
    cout << "Maximo numero de actividades compatibles: " << total << endl;

    return 0;
}
