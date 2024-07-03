#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <sstream>

using namespace std;

class Polinomio {
    private:
        int s;
        int* g;

    public:
        Polinomio();
        Polinomio(int s, int* g);
        Polinomio(const Polinomio &orig);
        ~Polinomio();
        Polinomio& operator=(const Polinomio &rhs);
        void operator+(const Polinomio &rhs);
        void operator-(const Polinomio &rhs);
        string operator~();
    };

#endif
