#include "NodoArbol.h"
#include <cstddef>
NodoArbol::NodoArbol(int dato){
    izq = NULL;
    der = NULL;
    this->dato = dato;
    //ctor
}

NodoArbol::~NodoArbol()
{
    //dtor
    izq = der = NULL;
}


void NodoArbol::fija_dat(int dato){
    this->dato = dato;
}

void NodoArbol::pone_a_la_izquierda(NodoArbol* izq){
    this->izq = izq;
}

void NodoArbol::pone_a_la_derecha(NodoArbol* der){
    this->der = der;
}

int NodoArbol::obtener_datos(){
    return dato;
}

NodoArbol*& NodoArbol::obtiene_izquierda(){
    return izq;
}

NodoArbol*& NodoArbol::obtiene_derecha(){
    return der;
}
