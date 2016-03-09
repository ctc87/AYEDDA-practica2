// fichero app.cpp

#include "../calculadora/calculadora.hpp"


#define MAX 20 

int main(void){
	Calculadora<Numero> calc = Calculadora<Numero>("operaciones.op");
}

/*int main(void)
{
    string complex("5+7.45i");
    string real   ("5.67889");
    string integer("4536569");

    Entero a(integer);
    Real    b(real);
    Complejo c(complex);
    cout << b.get_num(0) <<endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    Numero d = a + b;
    Numero e = c - b;
    Numero f = c * b;

    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
}*/

