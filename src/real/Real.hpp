#include "../numero/Numero.hpp"
/**
 * <h1>Real</h1>
 * Real es una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Real es una clase que representa a los numeros reales. Es
 * hija de la clase número.
 *
 * @see Numero
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-15
 */
class Real: public Numero{
public:

    /**
     * Constructor por defecto.
     */
    Real(void);

    /**
     * Constructor con número.
     * @param num número que representa.
     */
    Real(double num);

    /**
     * Constructor con cadena.
     * @param num cadena que representa al número.
     */
    Real(string num);

    /**
     * Destructor virtual.
     */
    virtual ~Real(void) {}
};
