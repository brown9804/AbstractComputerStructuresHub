#ifndef NODOARBOL_H
#define NODOARBOL_H


class NodoArbol
{
    public:
        NodoArbol(int);
        virtual ~NodoArbol();
        void fija_dat(int);
        void pone_a_la_izquierda(NodoArbol*);
        void pone_a_la_derecha(NodoArbol*);
        int obtener_datos ();
        NodoArbol*& obtiene_izquierda();
        NodoArbol*& obtiene_derecha();
    protected:
    private:
        int dato;
        NodoArbol* izq;
        NodoArbol* der;
};

#endif // NODOARBOL_H
