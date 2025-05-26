/* Implementar una función iterativa para buscar un elemento en un conjunto ordenado
sin repetidos con arreglo y con secuencia de nodo. No usar búsqueda binaria.*/

#include <iostream>
#include <cstdlib> //para usar las funciones rand() y srand()
#include <ctime> //para usar la función time
using namespace std;




struct nodo
{
    int valor;
    nodo* sig;
};

nodo* crearNodo(int valor, nodo* primero ){
    nodo* nuevo = new nodo();
    nuevo ->valor = valor;
    nuevo ->sig = primero;
    return nuevo;
}

bool existe(nodo* primero, int valor) {
    while (primero != NULL) {
        if (primero->valor == valor) return true;
        primero = primero->sig;
    }
    return false;
}

void insertar_ordenado(nodo* &primero, int valor) {
    if (existe(primero, valor)) return;

    nodo* nuevo = crearNodo(valor, NULL);

    if (primero == NULL || valor < primero->valor) { //caso ponerlo prinmero
        nuevo->sig = primero;
        primero = nuevo;
        return;
    }

    nodo* actual = primero;
    while (actual->sig != NULL && actual->sig->valor < valor) {
        actual = actual->sig;
    }

    nuevo->sig = actual->sig;
    actual->sig = nuevo;
}

void crear(nodo* &primero){
    int a;
    for(int i =0 ; i < 5 ; i++){
        cout<< "pasame un num para los punteros" << endl;
        cin >> a;
        insertar_ordenado(primero , a);
    }
}

void mostrar_elementos(const nodo * primero) {
    const nodo* actual = primero;
    cout << "Lista: ";
    while (actual != NULL) {
        cout << actual-> valor << " -> ";
        actual = actual->sig;
    }
    cout << "NULL" << endl;
}


void liberar_memoria(nodo * & primero) {
    nodo * actual = primero;
    nodo * siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->sig;
        delete actual; // Libera nodo actual del Heap
        actual = siguiente;
    }
    primero = NULL; // Asegura que el puntero original quede nulo
}






void mostrar_lista(nodo* primero) {
    cout << "Lista ordenada: ";
    while (primero != NULL) {
        cout << primero->valor << " ";
        primero = primero->sig;
    }
    cout << endl;
}

bool existeEnArreglo(int valor, int arr[]){
    for(int i = 0; i != valor; i++){
        if (arr[i] == valor){
            return true;
        }
        else 
        {
            if (arr[i] == NULL){
                return false;
            }
        }
        
    }
    return false;
}


void ordenarElementos(int arr[], int n){
        for(int i = 0; i < n; i++){
            for( int j = n; j > i; j--){
                if (arr[i] < arr[j]){
                    int aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
        }
    
  
}

void mostrarArreglo(int arr[], int valor){
    for(int i = 0; i < valor ; i++){
        cout << arr[i] << endl;
    }
}
void cargarArreglo(int arr[],int cantidad){
    int a;
    for(int i=0 ; i < cantidad ; i ++){
        cout<<"pasame un valor distinto a los otros sin ningun orden " << endl;
        cin >> a ;
        if(!existeEnArreglo(a,arr))
            arr[i] = a;
    }
}




int main(){
    int n;
    cout << "dame un valor n" << endl;
    cin >> n;
    int* arreglo = new int[n];

    cargarArreglo(arreglo,n);
    ordenarElementos(arreglo, n);
    cout << "el arreglo queda ordenado"<< endl;
    mostrarArreglo(arreglo, n);

    nodo* primero = NULL;
    crear(primero);
    mostrar_elementos(primero);

    cout << existe(primero, 4)<< endl;
    cout << existeEnArreglo(4, arreglo)<<endl;
    liberar_memoria(primero);


}