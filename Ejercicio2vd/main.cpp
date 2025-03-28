#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout << "ingrese un valor de un entero y dsp otro" << endl;
    cin >> a;
    cin >> c;
    if(cin.fail()){
        cout << "el valor no es valido";
    }else{
    cout << "el valor ingresado es: " << a <<endl;
    cout << "el segundo ingresado es: " << c <<endl;
    }
    cout << "ingrese un valor de un entero: " << endl;

    cin >> b;
    if (cin.fail()){
        cout << "el valor no es valido";
    }else{
    cout << "el valor ingresado es: " << b <<endl;
    }
    cout<< a << " por " << b << " por " << c << " da "<< a*b*c << endl;
    return 0;
}
