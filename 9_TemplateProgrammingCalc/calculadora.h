#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>

using namespace std;

template <typename Data>
class Calculadora {
    public:
        Calculadora(){};
        ~Calculadora(){};
        Data add(Data &d1, const Data &d2){return d1+d2;}
        Data sub(Data &d1, const Data &d2){return d1-d2; }
        Data mul(Data &d1, const Data &d2){return d1*d2;}
        Data div(Data &d1, const Data &d2){return d1/d2;}
        void print(Data &d1){
            cout << "el resultado es: " << d1 <<endl;
        }
};

#endif
