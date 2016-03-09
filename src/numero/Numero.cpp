#include "Numero.hpp"
#include <sstream>

template <class T>
T maxi (T a, T b) {
    return a > b? a: b;
}

    Numero::Numero(void):
    info_(NULL),
    sz_(0),
    num_type_(-1)
    {}

    Numero::Numero(int sz, int num_type):
    info_(NULL),
    sz_(sz),
    num_type_(num_type)
    {
        info_ = new double [sz_];

        for(int i = 0; i < sz_; i++)
            info_[i] = 0.0;
    }

    Numero::Numero(const Numero& number):
    info_(NULL),
    sz_(number.sz_),
    num_type_(number.num_type_)
    {
        info_ = new double [sz_];

        for(int i = 0; i < sz_; i++)
            info_[i] = number.info_[i];
    }

    Numero::~Numero(void){
        if (info_){
            //delete [] info_;
            //info_ = NULL;
        }
    }

    void Numero::set_num (int pos, double val){
        info_[pos] = val;
    }

    double Numero::get_num (int pos) const{
        if (pos >= sz_)
            return 0.0;
        else
            return info_[pos];
    }

    Numero Numero::operator +(const Numero& number) const
    {
        Numero aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

        for(int i = 0; i < aux.sz_; i++)
            aux.info_[i] = get_num(i) + number.get_num(i);

        return aux;
    }

    Numero Numero::operator -(const Numero& number) const
    {
        Numero aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));
        for(int i = 0; i < aux.sz_; i++)
            aux.info_[i] = get_num(i) - number.get_num(i);

        return aux;
    }

    Numero Numero::operator *(const Numero& number) const
    {
        Numero aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

        if (aux.sz_ == 1)
            aux.info_[0] = info_[0] * number.info_[0];
        else if (aux.num_type_ == complex_num){
            aux.info_[0] = get_num(0) * number.get_num(0) -  get_num(1) * number.get_num(1);
            aux.info_[1] = get_num(0) * number.get_num(1) +  get_num(1) * number.get_num(0);
        }

        return aux;
    }

    Numero Numero::operator /(const Numero& number) const
    {
        Numero aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

        if (aux.sz_ == 1)
            aux.info_[0] = info_[0] / number.info_[0];
        else if (aux.num_type_ == complex_num) {
            int div=(number.info_[0]*number.info_[0]) + (number.info_[1]*number.info_[1]);

                aux.info_[0]=(info_[0]*number.info_[0])+(info_[1]*number.info_[1]);
                aux.info_[0]/=div;
                aux.info_[1]=(info_[1]*number.info_[0])-(info_[0]*number.info_[1]);
                aux.info_[1]/=div;
        }
        cout << aux << endl;
        return aux;
    }

    Numero Numero::operator ^(const Numero& number) const
    {
        Numero aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

        if (aux.sz_ == 1)
            aux.info_[0] = (info_[0] * info_[0]) * (number.info_[0] - 1) ;
        else if (aux.num_type_ == complex_num) {
            aux.info_[0] = get_num(0) * get_num(0) -  get_num(1) * get_num(1);
            aux.info_[1] = get_num(0) * get_num(1) +  get_num(1) * get_num(0);
        }
        cout << aux << endl;
        return aux;
    }

    ostream& operator <<(ostream& os, const Numero& nat)
    {
        switch (nat.num_type_) {
            case integer_num:
            os << nat.get_num(0);
            break;
            case real_num:
            os << nat.get_num(0);
            break;
            case complex_num:
            os << nat.get_num(0);
            if(nat.get_num(1) > 0)
            os << "+";
            os << nat.get_num(1);
            os << "i";
            break;
        }
        return os;
    }

    string Numero::to_string( )
        {
            stringstream p;
            switch (num_type_) {
                case integer_num:
                    p << get_num(0);
                break;
                case real_num:
                    p << get_num(0);
                break;
                case complex_num:
                    p << get_num(0);
                    if(get_num(1) > 0)
                        p << "+";
                    else
                        p << "-";
                    p << get_num(1);
                    p << "i";
                break;
            }
            return p.str();
        }









