#ifndef ARREGLOSEGURO_H
#define ARREGLOSEGURO_H

template <typename Elemento>
class ArregloSeguro {

    ￼
    Mostrar razonamiento
    

    // Agrega un elemento en una posición vacía.
    // Pre: 1 <= posicion <= obtenerDimension() && estaVacia(posicion)
    // Post: El elemento se agrega en la posición dada. Lanza excepción si no se cumplen las precondiciones.
    void agregarElemento(unsigned int posicion, const Elemento& elemento);

    // Modifica el valor almacenado en una posición ya ocupada.
    // Pre: 1 <= posicion <= obtenerDimension() && !estaVacia(posicion)
    // Post: El elemento en la posición dada se modifica. Lanza excepción si no se cumplen las precondiciones.
    void modificarElemento(unsigned int posicion, const Elemento& elemento);

    // Determina si un elemento dado está almacenado en el arreglo.
    bool estaElemento(const Elemento& elemento) const;

    // Devuelve el elemento almacenado en una posición dada.
    // Pre: 1 <= posicion <= obtenerDimension() && !estaVacia(posicion)
    // Post: Devuelve el elemento. Lanza excepción si no se cumplen las precondiciones.
    Elemento obtenerElemento(unsigned int posicion) const;

    // Devuelve la cantidad de elementos almacenados en el arreglo.
    unsigned int cantidadElementos() const;

    // Devuelve la dimensión (capacidad máxima) del arreglo.
    unsigned int obtenerDimension() const;

    // Determina si una posición dada del arreglo está vacía.
    // Pre: 1 <= posicion <= obtenerDimension()
    // Post: Devuelve true si la posición está vacía, false en caso contrario. Lanza excepción si la posición es inválida.
    bool estaVacia(unsigned int posicion) const;

    // Determina si el arreglo está lleno.
    bool estaLleno() const;

private:
    Elemento* elementos;        // Puntero al array de elementos
    bool* posicionesOcupadas; // Array para marcar si una posición está ocupada o vacía
    unsigned int dim;           // Dimensión del arreglo
    unsigned int contador;      // Cantidad actual de elementos
};

#endif // ARREGLOSEGURO_H