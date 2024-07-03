#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <sstream>
using namespace std;


class Fraccion {
    private:
        int n;
        int d;
        
    public:
        Fraccion() ;
        Fraccion(int n, int d) ;
        Fraccion(const Fraccion &orig) ;
        ~Fraccion();
        Fraccion& operator=(const Fraccion &rhs) ;
        void operator+(const Fraccion &rhs);
        void operator-(const Fraccion &rhs);
        void operator*(const Fraccion &rhs);
        void operator/(const Fraccion &rhs);
        string operator~();
    };

#endif

        

