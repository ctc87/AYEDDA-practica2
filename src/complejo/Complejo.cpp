#include "Complejo.hpp"

  Complejo::Complejo(void):
    Numero(2, complex_num)
    {
        set_num(0, 0);
        set_num(1, 0);
    }

  Complejo::Complejo(double re, double im):
    Complejo::Numero(2, complex_num)
    {
        set_num(0, re);
        set_num(1, im);
    }

  Complejo::Complejo(string num):
    Numero(2, complex_num)
    {


        float aux = 1;
        if(num[0] == '-') {
            num.erase (num.begin());
            aux = -1.0;
        }
        string::size_type pos = num.find("i");
        string suma = num.substr (0, pos);
        if(num.find("-") != string::npos)
            pos = suma.find("-");
        else
            pos = suma.find("+");
        string re = suma.substr (0, pos);
        string im = suma.substr (pos);
        set_num(0, (atof(re.c_str()) *  aux));
        set_num(1, atof(im.c_str()));
    }

