#include <iostream>
#include <sstream>
#include "fraccion.h"

using namespace std;


Fraccion::Fraccion() {};

Fraccion::Fraccion(int n, int d) {
    this->n = n; //Numerador
    this->d=d;   //Denominador
};
Fraccion::Fraccion(const Fraccion &orig) {
    this->n = orig.n;
    this->d = orig.d;

};
Fraccion::~Fraccion() {
};
Fraccion& Fraccion::operator=(const Fraccion &rhs) {
    this->n = rhs.n;
    this->d = rhs.d;
    return *this;
};
void Fraccion::operator+(const Fraccion &rhs){
    this->n = (this->n * rhs.d) + (this->d * rhs.n) ;
    this->d = this->d * rhs.d;
};

void Fraccion::operator-(const Fraccion &rhs){
    this->n = (this->n * rhs.d) - (this->d * rhs.n) ;
    this->d = this->d * rhs.d;
};
void Fraccion::operator*(const Fraccion &rhs){
    this->n = this->n * rhs.n;
    this->d = this->d * rhs.d;
};
void Fraccion::operator/(const Fraccion &rhs){
    this->n = this->n * rhs.d;
    this->d = this->d * rhs.n;
};
string Fraccion::operator~() {
    stringstream s("", ios_base::app | ios_base::out);
    s<<"La fraccion es: " << n << "/" << d << endl;
    return s.str();
};
