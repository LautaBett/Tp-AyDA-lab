/*En ciertas aplicaciones, puede ser necesario combinar información proveniente de distintas
fuentes sin alterar su estructura original. Supongamos que se tienen dos vectores X e Y, cada uno
con n enteros ordenados en forma creciente. Se desea calcular la mediana del conjunto total de 2n
elementos sin necesidad de mezclar ni ordenar explícitamente los vectores.
Implemente un algoritmo en C++ que resuelva el problema en un tiempo O(log n).*/


/*int func(int arr1[], int arr2[], int piso1, int techo1, int piso2, int techo2){
    int med1 = techo1 + (piso1-techo1)/2 ;
    int med2 = techo2 + (piso2-techo2)/2 ;
    if(arr1[med1]<arr2[med2]){
        return func(arr1,arr2,med1,techo1,piso2,med2);
        else{
        return func(arr1,arr2,piso1,med1,med2,techo2);
        }
    }
    
    if(arr[med1]<arr[med2]){
        return med1;
    else
        return med2;    
    }
*/


#include <iostream>
using namespace std;

float mediana(int arr[], int inicio, int fin) {
    int n = fin - inicio + 1;
    int mid = inicio + (fin - inicio) / 2;
    if (n % 2 == 0)
        return (arr[mid] + arr[mid + 1]) / 2.0;
    else
        return arr[mid];
}

float encontrarMedianaRec(int arr1[], int arr2[], int piso1, int techo1, int piso2, int techo2) {
    // Caso base: solo 2 elementos por arreglo
    if ((techo1 - piso1 == 1) && (techo2 - piso2 == 1)) {
        int maxIzq = max(arr1[piso1], arr2[piso2]);
        int minDer = min(arr1[techo1], arr2[techo2]);
        return (maxIzq + minDer) / 2.0;
    }

    float m1 = mediana(arr1, piso1, techo1);
    float m2 = mediana(arr2, piso2, techo2);

    int len = (techo1 - piso1 + 1) / 2;

    if (m1 < m2)
        return encontrarMedianaRec(arr1, arr2, piso1 + len, techo1, piso2, techo2 - len);
    else
        return encontrarMedianaRec(arr1, arr2, piso1, techo1 - len, piso2 + len, techo2);
}

float encontrarMediana(int arr1[], int arr2[], int n) {
    return encontrarMedianaRec(arr1, arr2, 0, n - 1, 0, n - 1);
}

int main() {
    int X[] = {1, 3, 5, 7};
    int Y[] = {2, 4, 6, 8};
    int n = sizeof(X) / sizeof(X[0]);

    float med = encontrarMediana(X, Y, n);
    cout << "La mediana combinada es: " << med << endl;

    return 0;
}
