#include <iostream>
#include <sstream>
#include "polinomio.h"

Polinomio::Polinomio() {
};
Polinomio::Polinomio(int s, int* g) {
    this->s=s;
    this->g=g;
};
Polinomio::Polinomio(const Polinomio &orig) {
    this->s = orig.s;
    for(int i =0; i<s; i++){
        this->g[i]=orig.g[i];
    }

};
Polinomio::~Polinomio() {
};

Polinomio& Polinomio::operator=(const Polinomio &rhs) {
    this->s = rhs.s;
    this->g = new int[s];
    for(int i=0; i<s; i++){
        this->g[i]=rhs.g[i];
    }
    return *this;
};

void Polinomio::operator+(const Polinomio &rhs){
    if (s>=rhs.s){
        for(int i =0; i<s; i++){
            this->g[i]=this->g[i] + rhs.g[i];
        }
    }
    else{
        for(int i=0; i<rhs.s ; i++ ){
            rhs.g[i]=this->g[i] + rhs.g[i];
            delete this->g;
            this->g=new int[rhs.s];
            for (int i=0; i<rhs.s ; i++ ){
                this->g[i]=rhs.g[i];
            }
        }
    }
};
void Polinomio::operator-(const Polinomio &rhs){
    if (s>=rhs.s){
        for(int i =0; i<s; i++){
            this->g[i]=this->g[i] - (rhs.g[i]);
        }
    }
    else{
        for(int i=0; i<rhs.s ; i++ ){
            rhs.g[i]= rhs.g[i] - (this->g[i]);
            }
        delete this->g;
        this->g=new int[rhs.s];
        for (int i=0; i<rhs.s ; i++ ){
            this->g[i]=rhs.g[i];
            }
        }
        };

string Polinomio::operator~(){
    stringstream s("", ios_base::app | ios_base::out);
    int k =(this->s)-1;
    for(int i =0; i<(this->s);i++){
        if (i<=(k)){
            s << to_string(g[i]) << "x^" <<i << " + ";
        }
        else if (i==k){
            s << to_string(g[i]) << "x^" <<i;
        }
        }
        s <<endl;
        return s.str();
        };
