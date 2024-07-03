#ifndef NODO_H
#define NODO_H
#include <cstddef>   // para uso de NULL


class Nodo
{
    public:
        // definicion de atributos
        int element;
        Nodo* sig;
        Nodo* ant;

        Nodo(int);
        virtual ~Nodo();
    protected:
    private:
};

#endif // NODO_H
