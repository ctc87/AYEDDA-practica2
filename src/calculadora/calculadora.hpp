#include "../pila/pila.hpp"
#include "../entero/Entero.hpp"
#include "../complejo/Complejo.hpp"
#include "../real/Real.hpp"
#include <string>
#include <fstream>
#include <istream>
#include <vector>



/**
 * <h1>Calculadora</h1>
 * Calculadora es una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Calculadora es una clase que sirve para calcular operaciones
 * en notación posfija. Para ello utiliza la entrada IStream
 * para leer desde un fichero los operandos y los operadores. <br/>
 * <br/>
 * A través de una pila del tipo de dato necesario calculara
 * la solución. <br/>
 * <br/>
 * La calculadora está preparada para funcionar con al clase Numero.
 * y todas sus clases derivadas. <br/>
 * <br/>
 * Implementa las operaciones de: <br/>
 *  1. Suma <br/>
 *  2. Diferencia <br/>
 *  3. Producto <br/>
 *  4. División <br/>
 *
 * @see pila
 * @see Numero
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-15
 */
template <class tipoDato>
class Calculadora {
  private:
    /**
     * Nombre del fichero del que se quieren leer los datos.
     */
	string nombreFicheroEntrada;

	/**
	 * Pila utilizada para el cálculo de operaciones posfijas.
	 */
    pila<tipoDato> pilaCalucladora;

    /**
     * Método principal que lee desde la entrada y obtiene la solución.
     * Es invocado desde el constructor.
     * @return tipoDato Solución.
     */
    tipoDato leerDeLaEntradaHastaObtenerResultado();

    /**
     * Método que ejecuta las operaciones según el
     * carácter ASCII que las representa.
     * @param operador Carácter ASCII de la operación.
     * @return tipoDato Solución de la operación unitaria.
     */
    tipoDato operar(char operador);

    /**
     * Método que establece el tipo de número según una cadena de entrada.
     * @param numero Cadena de entrada.
     */
    void establecerElTipoDeNumero(string numero);

    /**
     * Método que devuelve un vector de Strings al cortar una
     * cadena.
     * @param s Cadena a cortar.
     * @param delim Delimitador para cortar la cadena.
     * @return vector<string>
     */
    vector<string> split(string &s, const char delim);

    /**
     * Método booleano que comprueba si una cadena es un número entero.
     * @param s Cadena de entrada.
     */
    bool esNumero(const string& s);

    /**
     * Método booleano que comprueba si una cadena es un número real.
     * @param s Cadena de entrada.
     */
    bool esReal(const string& s);

    /**
     * Método booleano que comprueba si una cadena es un número complejo.
     * @param s Cadena de entrada.
     */
    bool esComplejo(const string& s);
  public:

    /**
     * Constructor con cadena. Calcula las operaciones con los números
     * descritos en el fichero de entrada.<br/>
     * Los números son en el formato:<br>
     * entero -> [-]n<br/>
     * real -> [-]n.m(e|E)(+|-)y<br/>
     * complejo -> [-]a(+|-)bi<br/>
     * operadores -> (*|+|/|-)
     * @param archivoDeEntrada Cadena que contiene la ruta al archivo de entrada
     */
    Calculadora(string archivoDeEntrada);
    /**
     * Setter de la pila.
     * @param pilaCalculadora Pila de la clase incluida.
     */
    void setPilaCalucladora(const pila<tipoDato>& pilaCalucladora);

    /**
     * Getter de la pila.
     * @return pila Pila de la clase incluida.
     */
    const pila<tipoDato>& getPilaCalucladora() const;

    /**
     * Setter de la ruta del fichero.
     * @param pilaCalculadora Pila de la clase incluida.
     */
    void setNombreFicheroEntrada(const string& nombreFicheroEntrada);

    /**
     * Getter de la ruta del fichero.
     * @return pila Pila de la clase incluida.
     */
    string& getNombreFicheroEntrada();

    /**
     * Destructor de la clase.
     */
	~Calculadora();
};

template <class tipoDato>
  Calculadora<tipoDato>::Calculadora(string ficheroEntrada):
    pilaCalucladora(),
    nombreFicheroEntrada(ficheroEntrada)
    {
		pila<tipoDato> pilaAux;
		setPilaCalucladora(pilaAux);
		leerDeLaEntradaHastaObtenerResultado();
    }

template <class tipoDato>
tipoDato Calculadora<tipoDato>::operar(char operador) {
  tipoDato op1;
  tipoDato op2;
  tipoDato res;
  op1 = pilaCalucladora.pop();
  op2 = pilaCalucladora.pop();
  cout << "operación:  " <<  op2 << " " << operador << " " << op1 << endl;
  switch(operador) {
  case '+':
  	res = op2 + op1;
  break;
  case '*':
  	res = op2 * op1;
  break;
  case '/':
  	res = op2 / op1;
  break;
  case '-':
    res = op2 - op1;
  break;
  case '^':
    res = op2 ^ op1;
  break;
  }
  cout << "Resultado " << res << endl;
  return res;
}



template <class tipoDato>
  void Calculadora<tipoDato>::establecerElTipoDeNumero(string numero) {
    if(esComplejo(numero)) {
        Complejo aux(numero);
        pilaCalucladora.push(aux);
    } else if (esReal(numero)) {
        Real aux(numero);
        pilaCalucladora.push(aux);
    } else if(esNumero(numero)) {
        Entero aux(numero);
        pilaCalucladora.push(aux);
    }

}

template <class tipoDato>
  tipoDato Calculadora<tipoDato>::leerDeLaEntradaHastaObtenerResultado() {
    tipoDato resultado;
    ifstream in(getNombreFicheroEntrada().c_str());
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	string operando;
	int c = (cin >>  ws).peek();
	string oper;
	bool operadorResta = false;
	while(c!= EOF) {
      while(((c != '*') && (c != '^') && (c != '/') && (c != '+')) && !operadorResta) {
          cin >> operando;           //input from the file in.txt
        if(c != '-') {
            establecerElTipoDeNumero(operando);
            c = (cin >>  ws).peek();
        } else if (!(esNumero(operando) || esComplejo(operando) || esReal(operando))){
            operadorResta = true;
        } else if((esNumero(operando) || esComplejo(operando) || esReal(operando))){
            establecerElTipoDeNumero(operando);
        }
      }
      if(!operadorResta) {
          cin >> oper;
      } else {
          oper = operando;
          operadorResta = false;
      }
      resultado = operar(oper.c_str()[0]);
      establecerElTipoDeNumero(resultado.to_string());
      c = (cin >>  ws).peek();
    }
	cin.rdbuf(cinbuf);
	return resultado;
  }

template <class tipoDato>
bool Calculadora<tipoDato>::esNumero(const string& s) {
    return ( ((s[0] == '-') && isdigit(s[1])) || isdigit(s[0]) );
}

template <class tipoDato>
bool Calculadora<tipoDato>::esComplejo(const string& s) {
    size_t found = s.find("i");
    return esNumero(s) && (found != string::npos);
}

template <class tipoDato>
bool Calculadora<tipoDato>::esReal(const string& s) {
    size_t found1 = s.find(".");
    size_t found2 = s.find("E");
    size_t found3 = s.find("e");
    return esNumero(s) && ((found1 != string::npos) || (found2 != string::npos) || (found3 != string::npos));
}


template <class tipoDato>
void Calculadora<tipoDato>::setPilaCalucladora(const pila<tipoDato>& pilaCalucladora) {
    this->pilaCalucladora = pilaCalucladora;
}

template <class tipoDato>
const pila<tipoDato>& Calculadora<tipoDato>::getPilaCalucladora() const {
    return pilaCalucladora;
}


template <class tipoDato>
string& Calculadora<tipoDato>::getNombreFicheroEntrada() {
	return nombreFicheroEntrada;
}

template <class tipoDato>
void Calculadora<tipoDato>::setNombreFicheroEntrada(const string& nombreFicheroEntrada) {
	this->nombreFicheroEntrada = nombreFicheroEntrada;
}

template <class tipoDato>
  Calculadora<tipoDato>::~Calculadora(){}

