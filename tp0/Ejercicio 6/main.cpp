
Escribir una función que reciba como parámetro un arreglo de N números naturales, busque el
elemento “mayoría” y retorne si existe el elemento mayoría y, en caso positivo, la cantidad de veces
que aparece en el arreglo. El elemento mayoría es aquel que aparece más de N/2 veces en el arreglo.
*/

#include <iostream>
using std::cout;
using std::endl;

int frecuenciaElemento(int arreglo[], int tamaño, int elemento)
{
  int frecuencia = 0;
  for (int i = 0; i < tamaño; i++)
  {
    if (arreglo[i] == elemento)
      frecuencia++;
  }
  return frecuencia;
}

int buscarMayor(int arreglo[], int tamaño)
{
  int frecuenciaMax = 0;
  for (int i = 0; i < tamaño; i++)
  {
    int frecuencia = frecuenciaElemento(arreglo, tamaño, arreglo[i]);
    if (frecuencia > frecuenciaMax)
      frecuenciaMax = frecuencia;
  }
  return frecuenciaMax;
}

void mostrarArreglo(int arreglo[], int tamaño)
{
  for (int i = 0; i < tamaño; i++)
  {
    cout << arreglo[i] << " ";
  }
  cout << "" << endl;
}

void mostrarMayoria(int arreglo[], int tamaño)
{
  int mayorFrecuencia = buscarMayor(arreglo, tamaño);
  if (mayorFrecuencia > tamaño / 2)
  {
    cout << "El elemento mayoria existe, y aparece " << mayorFrecuencia << " veces.";
  }
  else
  {
    cout << "El elemento mayoria no existe";
  }
}

int main()
{
  const int N = 10;
  int arreglo[N] = {1, 1, 1, 1, 1, 1, 7, 8, 9, 10};
  mostrarArreglo(arreglo, N);
  mostrarMayoria(arreglo, N);
  return 0;
}