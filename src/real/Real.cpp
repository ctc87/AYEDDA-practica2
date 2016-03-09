/*
 * Real.cpp
 *
 *  Created on: 7 de mar. de 2016
 *      Author: troyano
 */
#include "Real.hpp"

    Real::Real(void):
    Numero(1, real_num)
    {
        set_num(0, 0);
    }

    Real::Real(double num):
    Numero(1, real_num)
    {
        set_num(0, num);
    }

    Real::Real(string num):
    Numero(1, real_num)
    {
        set_num(0, atof(num.c_str()));
    }




