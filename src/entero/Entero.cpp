/*
 * Entero.cpp
 *
 *  Created on: 7 de mar. de 2016
 *      Author: troyano
 */

#include "Entero.hpp"

    Entero::Entero(void):
    Numero(1, integer_num)
    {
        set_num(0,0);
    }

    Entero::Entero(double num):
    Numero(1, integer_num)
    {
        set_num(0,trunc(num));
    }


    Entero::Entero(string num):
    Numero(1, integer_num)
    {
        set_num(0, trunc(atof(num.c_str())));
    }




