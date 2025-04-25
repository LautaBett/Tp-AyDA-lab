#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    int numero;
};

int buscarTelefonoPorNombre(Persona agenda[], int tam, string nombre) {
    for (int i = 0; i < tam; i++) {
        if (agenda[i].nombre == nombre) {
            return agenda[i].numero;
        }
    }
    return -1;
}

string buscarNombrePorTelefono(Persona agenda[], int tam, int telefono) {
    for (int j = 0; j < tam; j++) {
        if (agenda[j].numero == telefono) {
            return agenda[j].nombre;
        }
    }
    return "Teléfono no encontrado";
}

int main() {
    const int TAM = 5;

    Persona agenda[TAM] = {
        {"Juan", 15678410},
        {"Ana", 15974417},
        {"Pedro", 15570327},
        {"Maria", 15609411},
        {"Carlos", 15470424}
    };

    string nombre;
    int num;

    cout << "Pasame un nombre para buscar el número: ";
    cin >> nombre;

    cout << "Pasame un número para buscar el nombre: ";
    cin >> num;

    int telefono = buscarTelefonoPorNombre(agenda, TAM, nombre);
    string nombrepor = buscarNombrePorTelefono(agenda, TAM, num);

    if (telefono != -1)
        cout << "El número de " << nombre << " es: " << telefono << endl;
    else
        cout << "Nombre no encontrado." << endl;

    cout << "El teléfono " << num << " pertenece a: " << nombrepor << endl;

    return 0;
}