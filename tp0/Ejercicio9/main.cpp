// Escribir una función que permita determinar si un número entero dado es primo o no. Escribir un
//programa que verifique si cada uno de los números almacenados en un arreglo son números primos.

#include <iostream>

using namespace std;


bool esPrimo(int num)
{
  if (num == 1)
    return false;

  bool esPrimo = true;
  int i = 2;
  while (i < num && esPrimo)
  {
    if (num % i == 0)
    {
      esPrimo = false;
    }
    i++;
  }
  return esPrimo;
}


void verificarPrimos(int arreglo[], int N)
{
  for (int i = 0; i < N; i++)
  {
    if (esPrimo(arreglo[i]))
    {
      cout << arreglo[i] << " es primo" << endl;
    }
    else
    {
      cout << arreglo[i] << " no es primo" << endl;
    }
  }
}

int main()
{
  int N = 5;
  int arreglo[N] = {1, 2, 3, 4, 5};
  verificarPrimos(arreglo, N);
  return 0;
}


