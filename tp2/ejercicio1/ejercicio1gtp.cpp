#include <iostream>
#include <string>
#include <vector> // Usaremos vector para inicializar fácilmente

using namespace std;

// Tamaño fijo para nuestro arreglo estático
const int MAX_CONTACTOS = 5;

// Estructura para almacenar la información de un contacto, //esto es un ejemplo
struct Contacto {
    string nombre;
    int telefono; // Asumiendo que el teléfono es un número entero
};

// --- Función buscarPorNumero (Adaptada de [[Ejemplo de ejercicios resueltos]]) ---
// Complejidad: O(N) - Búsqueda lineal
string buscarPorNumero(int numero, const Contacto* contactos, int n_contactos) {
    const Contacto* ptr = contactos;
    string nombre = "";
    int i = 0;
    bool encontro = false;
    cout << "--- Seguimiento buscarPorNumero(" << numero << ") ---" << endl;
    while (!encontro && i < n_contactos) {
        cout << "  Iteracion " << i << ": Comparando con " << ptr->nombre << " (" << ptr->telefono << ")" << endl;
        if (ptr->nombre != "" && ptr->telefono == numero ) {
            cout << "    -> Encontrado!" << endl;
            nombre = ptr->nombre;
            encontro = true;
        }
        i++;
        ptr++; // Avanza al siguiente contacto en memoria (Stack)
    }
     if (!encontro) {
         cout << "  -> No encontrado." << endl;
     }
    cout << "-----------------------------------------" << endl;
    return nombre;
}

// --- Función buscarPorNombre (Adaptada de [[Ejemplo de ejercicios resueltos]]) ---
// Complejidad: O(N) - Búsqueda lineal
int buscarPorNombre(string nombre_buscar, const Contacto* contactos, int n_contactos) {
    const Contacto* ptr = contactos;
    int telefono = -1;
    int i = 0;
    bool encontro = false;
    cout << "--- Seguimiento buscarPorNombre(" << nombre_buscar << ") ---" << endl;
    while (!encontro && i < n_contactos) {
         cout << "  Iteracion " << i << ": Comparando con " << ptr->nombre << " (" << ptr->telefono << ")" << endl;
        if (ptr->nombre == nombre_buscar) {
             cout << "    -> Encontrado!" << endl;
            telefono = ptr->telefono;
            encontro = true;
        }
        i++;
        ptr++; // Avanza al siguiente contacto en memoria (Stack)
    }
     if (!encontro) {
         cout << "  -> No encontrado." << endl;
     }
     cout << "-----------------------------------------" << endl;
    return telefono;
}

// --- Función mostrarContactos (Adaptada de [[Ejemplo de ejercicios resueltos]]) ---
void mostrarContactos(const Contacto* contactos, int n_contactos) {
    cout << "\nLista de Contactos Actual:\n";
    for (int i = 0; i < n_contactos; i++) {
        if (contactos[i].nombre != "") {
            cout << "  " << contactos[i].nombre << " - " << contactos[i].telefono << endl;
        }
    }
     cout << "---------------------------\n" << endl;
}

int main() {
    // Arreglo estático en el Stack con los 5 contactos
    Contacto contactos[MAX_CONTACTOS] = {
        {"Juan", 15678410},
        {"Ana", 15974417},
        {"Pedro", 15570327},
        {"Maria", 15609411},
        {"Carlos", 15470424}
    };

    mostrarContactos(contactos, MAX_CONTACTOS);

    // Realizar seguimiento solicitado
    int telefono_ana = buscarPorNombre("Ana", contactos, MAX_CONTACTOS);
    cout << "Resultado buscarPorNombre('Ana'): " << telefono_ana << endl << endl;

    string nombre_carlos = buscarPorNumero(15470424, contactos, MAX_CONTACTOS);
    cout << "Resultado buscarPorNumero(15470424): " << nombre_carlos << endl << endl;

    return 0;
}