#include <iostream>

using namespace std;

int main()
{
    double a,b,c, discr,x1,x2;
    cout << "ingrese los valores de a b y c separados por un espacio" << endl;
    cin >> a >> b >> c;
    discr = (b*b)-(4*a*c);
    cout<<"los valores ingresados som : " << a << " " << b << " "<< c << " " << endl;
    cout<< " y el discr da: " <<discr << endl;

    if(discr > 0.0 ){
        cout<<"son reales y distintas"<<endl;
        x1 = (-b + (discr/2))/(2*a);
        x2 = (-b - (discr/2))/(2*a);
        cout<< " x1 da : "<< x1 << " x2 da: " << x2 << endl;
    }else if (discr == 0.0){
        cout<<"son reales y iguales"<< endl;
        x1 = x2 = -b/2*a;
        cout<< " x1 da : "<< x1 << " x2 da: " << x2 << endl;
    }else if (discr < 0.0){
        cout<< "son complejas y conjugadas" <<endl;
    }
    return 0;
}
