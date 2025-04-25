/*  Implementar un programa que elimine un nodo de una secuencia. */
#include <iostream>
#include <cstdlib> // NULL

using namespace std;

// Estructura del Nodo (de [[Ejemplo de ejercicios resueltos]])
struct Nodo {
    int elemento;
    Nodo * siguiente;
};

// Función crear_nodo (de [[Ejemplo de ejercicios resueltos]])
// Crea un nodo en el Heap.
Nodo * crear_nodo(int elemento, Nodo * sigte) {
    Nodo * nuevo = new Nodo(); // Asigna memoria en el Heap
    nuevo->elemento = elemento;
    nuevo->siguiente = sigte;
    return nuevo; // Devuelve la dirección del nodo en el Heap
}

// --- Función agregar_final (de [[Ejemplo de ejercicios resueltos]]) ---
// Complejidad: O(N) - Debe recorrer toda la lista para encontrar el final.
void agregar_final(int nuevo_elemento, Nodo * & primero) {
    Nodo * nuevo = crear_nodo(nuevo_elemento, NULL);
    if (primero == NULL) {
        primero = nuevo; // Modifica 'primero' de main si la lista estaba vacía
    } else {
        Nodo * actual = primero;
        while (actual->siguiente != NULL) { // Recorre hasta el último
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo; // Enlaza el nuevo nodo
    }
}

// --- Función agregar_principio (de [[Ejemplo de ejercicios resueltos]]) ---
// Complejidad: O(1) - Solo manipula punteros al inicio.
void agregar_principio (int nuevo_elemento, Nodo * & primero) {
    // El nuevo nodo apunta al que era el primero.
    Nodo * nuevo = crear_nodo(nuevo_elemento, primero);
    // 'primero' ahora apunta al nuevo nodo. Modifica 'primero' de main.
    primero = nuevo;
}

// Función mostrar_elementos (de [[Ejemplo de ejercicios resueltos]])
void mostrar_elementos(const Nodo * primero) {
    const Nodo* actual = primero;
    cout << "Lista: ";
    while (actual != NULL) {
        cout << actual->elemento << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

// Función liberar_memoria (de [[Ejemplo de ejercicios resueltos]])
// ¡Importante para evitar memory leaks!
void liberar_memoria(Nodo * & primero) {
    Nodo * actual = primero;
    Nodo * siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        delete actual; // Libera nodo actual del Heap
        actual = siguiente;
    }
    primero = NULL; // Asegura que el puntero original quede nulo
}

void elimiarNodo(int elemenot_a_eliminar , Nodo * & primero){
    Nodo * actual = primero;
    Nodo * anterior = NULL;

    while (actual != NULL && actual -> elemento != elemenot_a_eliminar){
        anterior = actual;
        actual = actual -> siguiente;
    }

    if (elemenot_a_eliminar = actual -> elemento){
        if (anterior == NULL){ //osea el eliminar es el primero
            primero = actual -> siguiente;  //hago que el nuevo primero sea el segundo
            delete actual; //libero el nodo
        } else {
            anterior -> siguiente = actual -> siguiente; //hago que el anterior apunte al siguiente
            delete actual; //libero el nodo
            }
    } else {    
        if (actual == NULL)
            cout << "la lista esta vacia" << endl; 
        }      
};


int main() {
    Nodo* mi_lista = NULL; // Puntero 'primero' en el Stack, inicialmente nulo.

    cout << "Insertando al principio..." << endl;
    agregar_principio(10, mi_lista); // 10 -> NULL
    mostrar_elementos(mi_lista);
    agregar_principio(5, mi_lista);  // 5 -> 10 -> NULL
    mostrar_elementos(mi_lista);

    cout << "\nInsertando al final..." << endl;
    agregar_final(20, mi_lista);   // 5 -> 10 -> 20 -> NULL
    mostrar_elementos(mi_lista);
    agregar_final(30, mi_lista);   // 5 -> 10 -> 20 -> 30 -> NULL
    mostrar_elementos(mi_lista);

  

   elimiarNodo(20, mi_lista);
    cout << "\nEliminando el nodo con valor 20..." << endl;
    mostrar_elementos(mi_lista);
    elimiarNodo(5, mi_lista);
    cout << "\nEliminando el nodo con valor 5..." << endl;
    mostrar_elementos(mi_lista);

//liberar memoria al final
    liberar_memoria(mi_lista);  
    cout << "\nMemoria liberada." << endl;
    mostrar_elementos(mi_lista);

    return 0;
}
