#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#pragma once
using namespace std;

/**
 * Enumeración para los distintos tipos de datos
 */
enum {
	integer_num,
	real_num,
	rational_num,
	complex_num
};

/**
 * <h1>Numero</h1>
 * Numero es una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Numero es una clase que representa a los números complejos, y todos
 * los conjuntos que estos abarcan. Esta clase se utiliza para implementar
 * las operaciones entre estos tipos de números.
 *
 * @see Numero
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-1
 */
class Numero {
private:

    /**
     * Puntero que  contendrá en memoria dinámica como un vector, las partes del
     * número.(1 posición para reales y enteros 2 para reales)
     */
	double* info_;

    /**
     * Tamaño del vector de moría dinámica info_.
     */
	int     sz_;

    /**
     * Tipo de subclase almacenada.
     */
	int     num_type_;

public:

    /**
     * Constructor por defecto.
     */
	Numero(void);

    /**
     * Constructor con el tamaño de número.(1 para reales y enteros, 2 para complejos),
     * que tiene el array que guarda los datos de estos. Además también recibe el
     * tipo de numero hijo que es este.
     *
     * @param sz Tamaño del vector que almacena los campos del número.
     * @param num_type Tipo de subclase.
     */
	Numero(int sz, int num_type);
    string to_string();

    /**
     * Constructor con de copia para no tener problemas con la memoria dinámica.
     *
     * @param number Número para la copia.
     */
	Numero(const Numero& number);


    /**
     * Destructor que borra la memoria dinámica.
     */
	~Numero(void);

	/**
	 * Setter de num. Escribe información en una posición del vector de números.
	 * @param pos Posición de vector.
	 * @param val Valor a insertar.
	 */
	void set_num (int pos, double val);

    /**
     * Getter de num. Devuelve la información en la posición pos.
     * @param pos Posición de vector.
     * @return double.
     */
	double get_num (int pos) const;

	/**
	 * Sobrecarga del operador suma.
	 */
	Numero operator +(const Numero& number) const;

    /**
     * Sobrecarga del operador suma.
     */
	Numero operator -(const Numero& number) const;

    /**
     * Sobrecarga del operador multiplicación.
     */
    Numero operator *(const Numero& number) const;

    /**
     * Sobrecarga del operador división.
     */
    Numero operator /(const Numero& number) const;

    /**
     * Sobrecarga del operador potencia.
     */
    Numero operator ^(const Numero& number) const;

    /**
     * Sobrecarga del operador de salida <<.
     */
	friend ostream& operator <<(ostream& os, const Numero& nat);
};









