#include <iostream>
using std::cout;
using std::endl;

int frecuenciaElemento(int arreglo[], int tama�o, int elemento)
{
  int frecuencia = 0;
  for (int i = 0; i < tama�o; i++)
  {
    if (arreglo[i] == elemento)
      frecuencia++;
  }
  return frecuencia;
}

int buscarMayor(int arreglo[], int tama�o, int &mayoriaElemento)
{
  int frecuenciaMax = 0;
  for (int i = 0; i < tama�o; i++)
  {
    int frecuencia = frecuenciaElemento(arreglo, tama�o, arreglo[i]);
    if (frecuencia > frecuenciaMax)
    {
      frecuenciaMax = frecuencia;
      mayoriaElemento = arreglo[i];  // Guardamos el elemento con la mayor frecuencia
    }
  }
  return frecuenciaMax;
}

void mostrarArreglo(int arreglo[], int tama�o)
{
  for (int i = 0; i < tama�o; i++)
  {
    cout << arreglo[i] << " ";
  }
  cout << endl;  // Solo usamos endl para saltar a la siguiente l�nea
}

void mostrarMayoria(int arreglo[], int tama�o)
{
  int mayoriaElemento = -1;
  int mayorFrecuencia = buscarMayor(arreglo, tama�o, mayoriaElemento);
  if (mayorFrecuencia > tama�o / 2)
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
