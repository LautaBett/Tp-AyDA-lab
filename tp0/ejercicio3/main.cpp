#include <iostream>

using namespace std;

int main()
{
    string palabra1, palabra2;
    cout << " escribe dos palabras separadas por un espacio" << endl;
    cin >> palabra1 >> palabra2;
    if(cin.fail()){
        cout<< " no se pudo leer una palabra" << endl;
    }else{
        cout<<"la palabra uno es: " << palabra1 << " la palabra 2 es " << palabra2 << endl;
    cout <<"la concatenacion de las dos palabras da: "<< palabra1 + palabra2 << endl;
    }
    return 0;
}
