/*
 * Entero.hpp
 *
 *  Created on: 7 de mar. de 2016
 *      Author: troyano
 */
#include "../numero/Numero.hpp"
/**
 * <h1>Entero</h1>
 * Entero es una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Entero es una clase que representa a los numeros enteros. Es
 * hija de la clase número.
 *
 * @see Numero
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-15
 */
class Entero: public Numero {
public:

    /**
     * Constructor por defecto.
     */
    Entero(void);

    /**
     * Constructor con número.
     * @param num número que representa.
     */
    Entero(double num);

    /**
     * Constructor con cadena.
     * @param num cadena que representa al número.
     */
    Entero(string num);

    /**
     * Destructor virtual.
     */
    virtual ~Entero(void){};
};
