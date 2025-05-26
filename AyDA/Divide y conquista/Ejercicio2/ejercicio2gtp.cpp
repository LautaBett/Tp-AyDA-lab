#include <iostream>
using namespace std;

/*
Sea T un arreglo ordenado de n enteros diferentes (puede incluir números negativos):

a) Implemente un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T[i] = i, 
   siempre y cuando exista tal índice. La complejidad temporal de la solución propuesta 
   debe pertenecer a O(log n).
*/

int encontrarIndiceIgualValor(int arr[], int init, int fin) {
    if (init > fin) {
        return -1;
    }

    int mid = (fin - init) / 2 + init;

    if (arr[mid] == mid) {
        return mid;
    } else if (arr[mid] > mid) {
        return encontrarIndiceIgualValor(arr, init, mid - 1);
    } else {
        return encontrarIndiceIgualValor(arr, mid + 1, fin);
    }
}

int main() {
    int arr[] = {-10, -5, 0, 3, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int resultado = encontrarIndiceIgualValor(arr, 0, n - 1);

    if (resultado != -1)
        cout << "Índice encontrado: " << resultado << endl;
    else
        cout << "No existe tal índice." << endl;

    return 0;
}

/*
b) Explicar por qué una búsqueda binaria es esencial en grandes volúmenes de datos 
   (nube, redes sociales, etc.):

La búsqueda binaria es esencial porque permite encontrar elementos en tiempo logarítmico, 
es decir, O(log n), lo cual es muy eficiente comparado con la búsqueda lineal O(n). En 
sistemas que manejan grandes volúmenes de datos, como los servidores en la nube, bases 
de datos, o plataformas como redes sociales, realizar búsquedas rápidas es crítico para 
mantener tiempos de respuesta aceptables.

Al reducir drásticamente el número de comparaciones necesarias, la búsqueda binaria 
minimiza el uso de recursos computacionales y mejora el rendimiento general del sistema. 
Esto la convierte en una herramienta fundamental para lograr escalabilidad y eficiencia 
en aplicaciones modernas donde se manejan millones de registros o usuarios simultáneamente.
*/
