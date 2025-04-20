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

int buscarMayor(int arreglo[], int tamaño, int &mayoriaElemento)
{
  int frecuenciaMax = 0;
  for (int i = 0; i < tamaño; i++)
  {
    int frecuencia = frecuenciaElemento(arreglo, tamaño, arreglo[i]);
    if (frecuencia > frecuenciaMax)
    {
      frecuenciaMax = frecuencia;
      mayoriaElemento = arreglo[i];  // Guardamos el elemento con la mayor frecuencia
    }
  }
  return frecuenciaMax;
}

void mostrarArreglo(int arreglo[], int tamaño)
{
  for (int i = 0; i < tamaño; i++)
  {
    cout << arreglo[i] << " ";
  }
  cout << endl;  // Solo usamos endl para saltar a la siguiente línea
}

void mostrarMayoria(int arreglo[], int tamaño)
{
  int mayoriaElemento = -1;
  int mayorFrecuencia = buscarMayor(arreglo, tamaño, mayoriaElemento);
  if (mayorFrecuencia > tamaño / 2)
  {
    cout << "El elemento mayoria es " << mayoriaElemento << " y aparece " << mayorFrecuencia << " veces." << endl;
  }
  else
  {
    cout << "El elemento mayoria no existe" << endl;
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
