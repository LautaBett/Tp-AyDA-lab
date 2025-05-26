/*Sea T un arreglo ordenado de n enteros diferentes (puede incluir números negativos):
a) Implemente un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T [i] = i, siempre
y cuando exista tal índice. La complejidad temporal de la solución propuesta debe pertenecer
a O(log n).
b) Explicar por qué una búsqueda binaria es esencial en grandes volúmenes de datos (nube, redes
sociales, etc.)*/

int func(arr[], init , fin){
    p = (fin - init) /2  + init;
    if (p>= fin){
        return -1;
    }else{
        if(arr[p] = p){
            return p;
        }else{
            if ( arr[p] > p ){
                func(arr, init, p-1);
            }
            else{
                if(arr[p] < p){
                    fun(arr, p+1, fin);
                }  
            }
        }
    }    
}