#include "Nodo.h"
#include <cstddef>   // para uso de NULL

Nodo::Nodo(int elem){
    this->element = elem;
    sig = NULL;
    ant = NULL;
}

Nodo::~Nodo()
{
    //dtor
}
