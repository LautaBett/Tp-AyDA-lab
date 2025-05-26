/*Supongamos que se tiene un arreglo que contiene datos recolectados por dispositivos wearables,
como pulseras inteligentes o relojes deportivos. Este arreglo almacena mediciones de actividad
física registradas durante un cierto período de tiempo. Los datos pueden corresponder a un único
usuario o a múltiples usuarios. Se desea determinar el valor mínimo y el valor máximo de
actividad física registrados en el conjunto de datos, con el objetivo de detectar posibles patrones
de comportamiento. Por ejemplo, identificar posibles extremos en el comportamiento, como días
con niveles inusualmente bajos o altos de actividad, lo cual puede ser útil para generar
recomendaciones o alertas.
a) Resolver el problema implementando un algoritmo iterativo en lenguaje C++.
b) Resolver el problema utilizando la técnica de divide y conquista, también en C++.
c) Calcular la complejidad temporal de cada uno de los algoritmos implementados en los puntos
a) y b).
d) Realizar un análisis comparativo de eficiencia.*/

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> encontrarMinMaxIterativo(const vector<int>& datos) {
    int minimo = datos[0];
    int maximo = datos[0];

    for (int i = 1; i < datos.size(); i++) {
        if (datos[i] < minimo) {
            minimo = datos[i];
        } else if (datos[i] > maximo) {
            maximo = datos[i];
        }
    }

    return {minimo, maximo};
}


//agarrar el medio, ir para la izquierda y para la derecha buscando menor y mayor retorno esos dos

void encontrarMinMaxPorPivote(const vector<int>& datos, int inicio, int fin, int& minimo, int& maximo) {
    if (inicio > fin) return;

    int medio = (inicio + fin) / 2;

    // Comparar el pivote con mínimo y máximo actuales
    if (datos[medio] < minimo) minimo = datos[medio];
    if (datos[medio] > maximo) maximo = datos[medio];

    // Llamada recursiva a la izquierda y derecha del pivote
    encontrarMinMaxPorPivote(datos, inicio, medio - 1, minimo, maximo);
    encontrarMinMaxPorPivote(datos, medio + 1, fin, minimo, maximo);
}
