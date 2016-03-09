#include "../numero/Numero.hpp"
/**
 * <h1>Complejo</h1>
 * Complejo es una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Complejo es una clase que representa a los numeros complejos. Es
 * hija de la clase número.
 *
 * @see Numero
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-15
 */
class Complejo: public Numero {
public:

    /**
     * Constructor por defecto.
     */
    Complejo(void);

    /**
     * Constructor con número.
     * @param num número que representa.
     */
    Complejo(double re, double im);

    /**
     * Constructor con cadena.
     * @param num cadena que representa al número.
     */
    Complejo(string num);

    /**
     * Destructor virtual.
     */
    virtual ~Complejo(void) {};
};
