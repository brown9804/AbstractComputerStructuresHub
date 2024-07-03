#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <iostream>
#include "NodoArbol.h"

using namespace std;

class ArbolABB
{
    public:
        ArbolABB();
        virtual ~ArbolABB();
        NodoArbol* obtener_raiz();

        void insertar(int);

        bool encuentra_en_arbol_ABB(int);

        string ver_arbol(int);

        int cantidad_de_nodos_presente();
        string ruta(int);
        string nodos_hoja();
        string nodos_internos_arbol();
        int un_nivel_nodos(int);
        int nivel_de_un_nodo(int);
        int altura();
        string sucesores(int);
        int obtiene_padre(int);
        NodoArbol* obtiene_nodo(int);

        string recorrer_arbol_por_ancho();
        bool arbol_esta_lleno();
        bool arbol_esta_completo();
        bool compara_cant_elem( ArbolABB* );
        bool de_altura_son_iguales( ArbolABB* );
        string arbol_auxiliar_esta_completo(NodoArbol*,int);
        bool eliminar_nodo(int );

    protected:
    private:
        NodoArbol* raiz;
        void agrega_en_el_auxili(int, NodoArbol*&);
        bool encuentra_en_ABB_Aux(int, NodoArbol*);
        string numeros_de_string(int);


        int cantidad_nodos_auxiliar(NodoArbol* );
        string rutaAux(int ,NodoArbol* );
        string nodosHojaAux(NodoArbol* );
        string nodosInternosAux(NodoArbol*);
        int un_nivel_nodos_auxili(NodoArbol* , int );
        int nivel_de_un_nodo_auxiliar(int , int , NodoArbol* );
        string sucesores_del_arbol_auxiliar(NodoArbol* , int , int );
        int obtiene_padre_arbol_auxiliar(NodoArbol* ,int, int);
        NodoArbol* obtiene_nodo_auxiliar(NodoArbol* , int);

        string recorrer_arbol_por_ancho_auxiliar(NodoArbol* , int);
        int esta_arbol_auxiliar_lleno(NodoArbol* );
        int total_nodos(int , int);
        void eliminar_nodo_case_1(NodoArbol*, NodoArbol*);
        void eliminar_nodo_case_2(NodoArbol*, NodoArbol*);

        string en_orden(NodoArbol* raiz);
        string preOrden(NodoArbol* raiz);
        string posOrden(NodoArbol* raiz);
};

#endif // ARBOLABB_H
