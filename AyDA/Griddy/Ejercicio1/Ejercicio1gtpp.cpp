#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------- 1. Mochila Fraccionaria ----------
struct Objeto {
    double valor, peso;
    bool operator<(const Objeto& otro) const {
        return (valor / peso) > (otro.valor / otro.peso);
    }
};

double mochilaFraccionaria(vector<Objeto>& objetos, double capacidad) {
    sort(objetos.begin(), objetos.end());  //n log n
    double valorTotal = 0.0;

    for (auto& obj : objetos) {     // n
        if (capacidad >= obj.peso) {  //tomo todo el objeto
            capacidad -= obj.peso;
            valorTotal += obj.valor;
        } else {                          // tomo solo una fraccion
            valorTotal += obj.valor * (capacidad / obj.peso);
            break;  //no hay mas capacidad
        }
    }
    return valorTotal;  //complejidad n log n
}

// ---------- 2. Planificación de tareas ----------
struct Tarea {
    int ganancia, plazo;
};

bool cmpTarea(Tarea a, Tarea b) {
    return a.ganancia > b.ganancia;
}

int planificarTareas(vector<Tarea>& tareas) {
    sort(tareas.begin(), tareas.end(), cmpTarea);
    int n = tareas.size();
    vector<bool> tiempo(n, false);
    int gananciaTotal = 0;

    for (auto& t : tareas) {
        for (int j = min(n, t.plazo) - 1; j >= 0; j--) {
            if (!tiempo[j]) {
                tiempo[j] = true;
                gananciaTotal += t.ganancia;
                break;
            }
        }
    }
    return gananciaTotal;
}

// ---------- 3. Minimizar tiempo de espera ----------
int minimizarTiempoEspera(vector<int>& tiempos) {
    sort(tiempos.begin(), tiempos.end());
    int tiempoEspera = 0, acumulado = 0;
    for (int t : tiempos) {
        tiempoEspera += acumulado;
        acumulado += t;
    }
    return tiempoEspera;
}

// ---------- 4. Máximo número de actividades ----------
struct Actividad {
    int comienzo, fin;
};

bool cmpActividad(Actividad a, Actividad b) {
    return a.fin < b.fin;
}

int seleccionarActividades(vector<Actividad>& actividades) {
    sort(actividades.begin(), actividades.end(), cmpActividad);
    int finAnterior = 0, seleccionadas = 0;

    for (auto& act : actividades) {
        if (act.comienzo >= finAnterior) {
            seleccionadas++;
            finAnterior = act.fin;
        }
    }
    return seleccionadas;
}

// ---------- MAIN ----------
int main() {
    // Ejemplo 1: Mochila Fraccionaria
    cout << "1. Mochila Fraccionaria" << endl;
    vector<Objeto> objetos = {{25, 18}, {24, 15}, {15, 10}};
    double capacidad = 20;
    cout << "Valor maximo: " << mochilaFraccionaria(objetos, capacidad) << endl << endl;

    // Ejemplo 2: Planificación de tareas
    cout << "2. Planificación de Tareas" << endl;
    vector<Tarea> tareas = {{50, 2}, {10, 1}, {15, 2}, {30, 1}};
    cout << "Ganancia maxima: " << planificarTareas(tareas) << endl << endl;

    // Ejemplo 3: Minimizar tiempo de espera
    cout << "3. Minimizar Tiempo de Espera" << endl;
    vector<int> tiempos = {5, 10, 3};
    cout << "Tiempo de espera minimo: " << minimizarTiempoEspera(tiempos) << endl << endl;

    // Ejemplo 4: Actividades Compatibles
    cout << "4. Actividades Compatibles" << endl;
    vector<Actividad> actividades = {{1, 3}, {2, 5}, {4, 7}, {6, 9}};
    cout << "Maximo de actividades compatibles: " << seleccionarActividades(actividades) << endl << endl;

    return 0;
}
