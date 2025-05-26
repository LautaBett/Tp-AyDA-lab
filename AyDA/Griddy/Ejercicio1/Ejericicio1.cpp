// Definición de la estructura para un objeto
ESTRUCTURA Objeto {
    id_original: Entero  // Para mantener referencia al objeto original si es necesario
    peso: Real
    valor: Real
    ratio_valor_peso: Real
  }
  
  // Función principal del algoritmo Greedy para la Mochila Fraccionaria
  FUNCION MochilaFraccionaria (ListaDeObjetos objetos_disponibles, CapacidadMaxima mochila_capacidad)
    // Paso 1: Calcular el ratio valor/peso para cada objeto
    // (Esto se asume que ya podría estar precalculado en la estructura Objeto,
    //  o se puede hacer aquí iterando sobre objetos_disponibles)
    PARA CADA obj EN objetos_disponibles HACER
      obj.ratio_valor_peso = obj.valor / obj.peso
    FIN PARA
  
    // Paso 2: Ordenar los objetos en orden decreciente de su ratio_valor_peso
    // Se puede usar cualquier algoritmo de ordenamiento eficiente (ej. MergeSort, QuickSort)
    // La función Ordenar modificaría la lista 'objetos_disponibles' o devolvería una nueva lista ordenada.
    OrdenarPorRatioDescendente(objetos_disponibles)
  
    // Paso 3: Llenar la mochila
    ListaDeFraccionesX = LISTA VACÍA // Guardará las fracciones tomadas de cada objeto (en el orden original)
                                    // o podrías tener un array inicializado en ceros si los objetos tienen IDs fijos.
                                    // Para este pseudocódigo, asumiremos que guardamos tuplas (id_original, fraccion)
    
    valor_total_en_mochila = 0.0
    peso_actual_en_mochila = 0.0
    capacidad_restante = mochila_capacidad
  
    PARA CADA obj EN objetos_disponibles (ya ordenados) HACER
      SI capacidad_restante == 0 ENTONCES
        // La mochila ya está llena, no se pueden agregar más objetos
        ROMPER BUCLE // Salir del PARA CADA
      FIN SI
  
      SI obj.peso <= capacidad_restante ENTONCES
        // El objeto cabe completamente
        fraccion_a_tomar = 1.0
        AÑADIR (obj.id_original, fraccion_a_tomar) A ListaDeFraccionesX
        
        peso_actual_en_mochila = peso_actual_en_mochila + obj.peso
        valor_total_en_mochila = valor_total_en_mochila + obj.valor
        capacidad_restante = capacidad_restante - obj.peso
      SINO
        // El objeto no cabe completo, tomar la fracción que llene la mochila
        fraccion_a_tomar = capacidad_restante / obj.peso
        AÑADIR (obj.id_original, fraccion_a_tomar) A ListaDeFraccionesX
        
        peso_actual_en_mochila = peso_actual_en_mochila + (fraccion_a_tomar * obj.peso)
        valor_total_en_mochila = valor_total_en_mochila + (fraccion_a_tomar * obj.valor)
        capacidad_restante = 0 // La mochila se llena con esta fracción
      FIN SI
    FIN PARA
  
    // Si algunos objetos no se consideraron porque la mochila se llenó,
    // sus fracciones implícitamente son 0. Si necesitas un array completo
    // de fracciones para todos los n objetos originales, deberías inicializarlo
    // y luego actualizar las fracciones de los objetos que sí se tomaron.
  
    RETORNAR (ListaDeFraccionesX, valor_total_en_mochila, peso_actual_en_mochila)
  FIN FUNCION
  
  // --- Función auxiliar para ordenar (ejemplo conceptual) ---
  // En la práctica, usarías la función de ordenamiento de tu lenguaje.
  PROCEDIMIENTO OrdenarPorRatioDescendente(ListaDeObjetos &lista_objetos)
    // Implementación de un algoritmo de ordenamiento (ej. BubbleSort, MergeSort, QuickSort)
    // que ordene 'lista_objetos' de mayor a menor según el campo 'ratio_valor_peso'.
    // Por ejemplo, usando una función de comparación que devuelva verdadero si
    // objetoA.ratio_valor_peso > objetoB.ratio_valor_peso.
  FIN PROCEDIMIENTO
  
  
  // --- Ejemplo de uso ---
  // Definir los objetos (basado en el ejemplo del práctico [1898])
  // Objeto 1: (v=25, p=18)
  // Objeto 2: (v=24, p=15)
  // Objeto 3: (v=15, p=10)
  
  obj1 = NUEVO Objeto(id_original=1, peso=18.0, valor=25.0, ratio_valor_peso=0.0)
  obj2 = NUEVO Objeto(id_original=2, peso=15.0, valor=24.0, ratio_valor_peso=0.0)
  obj3 = NUEVO Objeto(id_original=3, peso=10.0, valor=15.0, ratio_valor_peso=0.0)
  
  lista_de_todos_los_objetos = [obj1, obj2, obj3]
  capacidad_P = 20.0
  
  (fracciones_tomadas, valor_maximo, peso_final) = MochilaFraccionaria(lista_de_todos_los_objetos, capacidad_P)
  
  IMPRIMIR "Fracciones tomadas (id_objeto, fraccion):"
  PARA CADA par EN fracciones_tomadas HACER
    IMPRIMIR par
  FIN PARA
  IMPRIMIR "Valor máximo obtenido:", valor_maximo
  IMPRIMIR "Peso final en la mochila:", peso_final
  
  // Salida esperada para el ejemplo del práctico:
  // Fracciones tomadas (id_objeto, fraccion):
  // (2, 1.0)  // Objeto 2 completo
  // (3, 0.5)  // Mitad del objeto 3
  // (1, 0.0)  // (implícito o explícito si se manejara un array completo de fracciones)
  // Valor máximo obtenido: 31.5
  // Peso final en la mochila: 20.0