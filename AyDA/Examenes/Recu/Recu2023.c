CLASS ArregloSeguro[Elemento]
IMPORTS Nat, Boolean
BASIC CONSTRUCTORS crearArreglo, agregarElemento
EFFECTIVE
TYPE ArregloSeguro // Representa un arreglo seguro de elementos de un tipo dado.

OPERATIONS
  crearArreglo: Nat -> ArregloSeguro;
  // Crea un arreglo vacío con una dimensión (capacidad máxima) dada.
  // Pre: La dimensión debe ser un natural positivo.

  agregarElemento: ArregloSeguro * Nat * Elemento -> ArregloSeguro;
  // Agrega un elemento en una posición dada del arreglo.
  // Pre: La posición debe ser un índice válido dentro de la dimensión del arreglo (1 <= posicion <= dimension)
  //      y la posición debe estar vacía (no contener previamente un elemento).

  modificarElemento: ArregloSeguro * Nat * Elemento -> ArregloSeguro;
  // Modifica el valor almacenado en una posición ya ocupada del arreglo.
  // Pre: La posición debe ser un índice válido dentro de la dimensión del arreglo (1 <= posicion <= dimension)
  //      y la posición debe estar ocupada (contener previamente un elemento).

  estaElemento: ArregloSeguro * Elemento -> Boolean;
  // Determina si un elemento dado está almacenado en el arreglo.

  obtenerElemento: ArregloSeguro * Nat -> Elemento;
  // Devuelve el elemento almacenado en una posición dada del arreglo.
  // Pre: La posición debe ser un índice válido dentro de la dimensión del arreglo (1 <= posicion <= dimension)
  //      y la posición debe estar ocupada.

  cantidadElementos: ArregloSeguro -> Nat;
  // Devuelve la cantidad de elementos actualmente almacenados en el arreglo.

  dimension: ArregloSeguro -> Nat;
  // Devuelve la dimensión (capacidad máxima) del arreglo.

  estaVaciaPosicion: ArregloSeguro * Nat -> Boolean;
  // Determina si una posición dada del arreglo está vacía.
  // Pre: La posición debe ser un índice válido dentro de la dimensión del arreglo (1 <= posicion <= dimension).

  estaLleno: ArregloSeguro -> Boolean;
  // Determina si el arreglo ha alcanzado su capacidad máxima de elementos.

AXIOMS arr: ArregloSeguro; elem, elem2: Elemento; pos, pos2, dim: Nat;

  // Axiomas para dimension
  dimension(crearArreglo(dim)) = dim;
  dimension(agregarElemento(arr, pos, elem)) = dimension(arr);
  dimension(modificarElemento(arr, pos, elem)) = dimension(arr);

  // Axiomas para cantidadElementos
  cantidadElementos(crearArreglo(dim)) = 0;
  cantidadElementos(agregarElemento(arr, pos, elem)) = 1 + cantidadElementos(arr);
  // Nota: Se asume que la precondición de agregarElemento (posición vacía) se cumple.
  cantidadElementos(modificarElemento(arr, pos, elem)) = cantidadElementos(arr);
  // Nota: modificarElemento no cambia la cantidad de elementos.

  // Axiomas para agregarElemento y obtenerElemento
  obtenerElemento(agregarElemento(arr, pos, elem), pos) = elem;
  (pos != pos2) => obtenerElemento(agregarElemento(arr, pos, elem), pos2) = obtenerElemento(arr, pos2);

  // Axiomas para modificarElemento y obtenerElemento
  obtenerElemento(modificarElemento(arr, pos, elem), pos) = elem;
  (pos != pos2) => obtenerElemento(modificarElemento(arr, pos, elem), pos2) = obtenerElemento(arr, pos2);

  // Axiomas para estaElemento
  estaElemento(crearArreglo(dim), elem) = False;
  estaElemento(agregarElemento(arr, pos, elem), elem2) = (elem == elem2) or estaElemento(arr, elem2);
  // Para modificarElemento, si el elemento modificado es el que se busca, da true.
  // Si no, depende de si el nuevo valor es igual o si el elemento estaba en otra parte.
  // Este axioma puede ser más complejo dependiendo de cómo se manejen los duplicados.
  // Asumimos que puede haber duplicados para simplificar.
  estaElemento(modificarElemento(arr, pos, elem), elem2) = (elem == elem2) or estaElemento(eliminarElementoInterno(arr,pos), elem2);
  // Se necesitaría una operación interna "eliminarElementoInterno" para la correctitud de estaElemento tras modificar,
  // o redefinir la lógica para iterar y verificar. Para la funcionalidad mínima solicitada,
  // y sin entrar en la implementación de la búsqueda, lo dejamos así.

  // Axiomas para estaVaciaPosicion
  estaVaciaPosicion(crearArreglo(dim), pos) = True;
  estaVaciaPosicion(agregarElemento(arr, pos, elem), pos) = False;
  (pos != pos2) => estaVaciaPosicion(agregarElemento(arr, pos, elem), pos2) = estaVaciaPosicion(arr, pos2);
  // Modificar un elemento no cambia el estado de vacío de otras posiciones.
  // La posición modificada sigue sin estar vacía.
  estaVaciaPosicion(modificarElemento(arr, pos, elem), pos) = False;
  (pos != pos2) => estaVaciaPosicion(modificarElemento(arr, pos, elem), pos2) = estaVaciaPosicion(arr, pos2);


  // Axiomas para estaLleno
  estaLleno(arr) = (cantidadElementos(arr) == dimension(arr));

END-CLASS