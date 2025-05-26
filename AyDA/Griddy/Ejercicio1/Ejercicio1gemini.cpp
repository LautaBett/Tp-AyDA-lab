#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort
#include <iomanip>   // Para std::fixed y std::setprecision

// Estructura para representar cada objeto
struct Objeto {
    int id;          // Identificador original del objeto
    double peso;
    double valor;
    double ratio_valor_peso; // v_i / p_i

    // Constructor para facilitar la creación de objetos
    Objeto(int _id, double _peso, double _valor) : id(_id), peso(_peso), valor(_valor) {
        if (peso > 0) {
            ratio_valor_peso = valor / peso;
        } else {
            ratio_valor_peso = 0; // O manejar como un caso especial/error
        }
    }
};

// Función de comparación para ordenar los objetos por su ratio_valor_peso en orden descendente
bool compararPorRatio(const Objeto& a, const Objeto& b) {
    return a.ratio_valor_peso > b.ratio_valor_peso;
}

// Estructura para guardar el resultado de la fracción tomada de cada objeto
struct FraccionObjeto {
    int id_objeto;
    double fraccion_tomada;
};

// Función principal del algoritmo Greedy para la Mochila Fraccionaria
std::pair<std::vector<FraccionObjeto>, double> mochilaFraccionariaGreedy(
    std::vector<Objeto>& objetos,
    double capacidad_maxima) {

    // Paso 1: El ratio ya se calculó en el constructor de Objeto.
    // Si no, se calcularía aquí.

    // Paso 2: Ordenar los objetos en orden decreciente de su ratio_valor_peso.
    std::sort(objetos.begin(), objetos.end(), compararPorRatio);

    std::vector<FraccionObjeto> fracciones_seleccionadas;
    double valor_total_en_mochila = 0.0;
    double capacidad_restante = capacidad_maxima;

    // Paso 3: Llenar la mochila
    for (const auto& obj : objetos) {
        if (capacidad_restante == 0) {
            // La mochila ya está llena
            break;
        }

        if (obj.peso <= capacidad_restante) {
            // El objeto cabe completamente
            fracciones_seleccionadas.push_back({obj.id, 1.0});
            capacidad_restante -= obj.peso;
            valor_total_en_mochila += obj.valor;
        } else {
            // El objeto no cabe completo, tomar la fracción que llene la mochila
            double fraccion = capacidad_restante / obj.peso;
            fracciones_seleccionadas.push_back({obj.id, fraccion});
            valor_total_en_mochila += fraccion * obj.valor;
            capacidad_restante = 0; // La mochila se llena
        }
    }

    return {fracciones_seleccionadas, valor_total_en_mochila};
}

int main() {
    // Ejemplo del práctico (Práctico N° 4-Greedy.pdf)
    // n=3, P=20
    // (v1,v2,v3)=(25,24,15)
    // (p1,p2,p3)=(18,15,10)

    std::vector<Objeto> objetos_disponibles;
    objetos_disponibles.emplace_back(1, 18.0, 25.0); // id, peso, valor
    objetos_disponibles.emplace_back(2, 15.0, 24.0);
    objetos_disponibles.emplace_back(3, 10.0, 15.0);

    double capacidad_P = 20.0;

    auto resultado = mochilaFraccionariaGreedy(objetos_disponibles, capacidad_P);
    std::vector<FraccionObjeto> fracciones_tomadas = resultado.first;
    double valor_maximo = resultado.second;

    std::cout << "Problema de la Mochila Fraccionaria (Greedy):" << std::endl;
    std::cout << "Capacidad máxima de la mochila: " << capacidad_P << std::endl;
    std::cout << "\nObjetos considerados (ordenados por ratio v/p decreciente):" << std::endl;
    for(const auto& obj : objetos_disponibles) { // Muestra los objetos ya ordenados por la función
        std::cout << "  ID: " << obj.id << ", Peso: " << obj.peso
                  << ", Valor: " << obj.valor << ", Ratio V/P: " << std::fixed << std::setprecision(3) << obj.ratio_valor_peso << std::endl;
    }

    std::cout << "\nFracciones tomadas de cada objeto (para maximizar el valor):" << std::endl;
    // Para mostrar las fracciones en el orden original de IDs, necesitaríamos un paso extra
    // o almacenar las fracciones en un array indexado por ID.
    // Por simplicidad, aquí mostramos los resultados tal como se seleccionaron.
    // Para una salida más ordenada por ID original, se puede post-procesar `fracciones_tomadas`.
    std::vector<double> x(objetos_disponibles.size() + 1, 0.0); // +1 si los IDs son 1-based
    for(const auto& fraccion_obj : fracciones_tomadas) {
        x[fraccion_obj.id_objeto] = fraccion_obj.fraccion_tomada;
    }

    double peso_final_calculado = 0.0;
    // Re-iterar sobre los objetos originales para mostrar las fracciones en su orden original
    // Esto es solo para la visualización, el algoritmo ya calculó las fracciones correctas.
    std::vector<Objeto> objetos_originales;
    objetos_originales.emplace_back(1, 18.0, 25.0);
    objetos_originales.emplace_back(2, 15.0, 24.0);
    objetos_originales.emplace_back(3, 10.0, 15.0);


    for(const auto& obj_orig : objetos_originales) {
        double fraccion_para_este_objeto = 0.0;
        for(const auto& fr_sel : fracciones_tomadas) {
            if (fr_sel.id_objeto == obj_orig.id) {
                fraccion_para_este_objeto = fr_sel.fraccion_tomada;
                break;
            }
        }
        std::cout << "  Objeto ID " << obj_orig.id << ": Fracción tomada = " << std::fixed << std::setprecision(3) << fraccion_para_este_objeto
                  << " (Peso aportado: " << (fraccion_para_este_objeto * obj_orig.peso)
                  << ", Valor aportado: " << (fraccion_para_este_objeto * obj_orig.valor) << ")" << std::endl;
        peso_final_calculado += fraccion_para_este_objeto * obj_orig.peso;
    }


    std::cout << "\nValor máximo obtenido en la mochila: " << std::fixed << std::setprecision(2) << valor_maximo << std::endl;
    std::cout << "Peso total en la mochila: " << std::fixed << std::setprecision(2) << peso_final_calculado << std::endl;


    // Ejemplo de salida esperada (Práctico N° 4-Greedy.pdf página 1, [6])
    // (0, 1, 1/2) -> x1=0, x2=1, x3=0.5
    // Valor: 31.5
    // Peso: (0*18) + (1*15) + (0.5*10) = 15 + 5 = 20
    std::cout << "\nVerificación con ejemplo del práctico (0, 1, 1/2):" << std::endl;
    std::cout << "  Objeto 1 (ID 1): Fracción tomada = " << x[1] << std::endl;
    std::cout << "  Objeto 2 (ID 2): Fracción tomada = " << x[2] << std::endl;
    std::cout << "  Objeto 3 (ID 3): Fracción tomada = " << x[3] << std::endl;


    return 0;
}