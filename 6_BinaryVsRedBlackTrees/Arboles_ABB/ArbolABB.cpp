#include "ArbolABB.h"
#include "NodoArbol.h"
#include <cstddef>
#include <sstream>
#include <string>
#include <cmath>
ArbolABB::ArbolABB(){
    raiz = NULL;
    //ctor
}

ArbolABB::~ArbolABB(){
    //dtor
    raiz = NULL;
}


NodoArbol* ArbolABB::obtener_raiz(){
return raiz;
}



bool ArbolABB::encuentra_en_ABB_Aux(int dato, NodoArbol* a){
if (a == NULL)
    return false;
if(dato == a->obtener_datos())
    return true;
if (dato < a->obtener_datos())
    return encuentra_en_ABB_Aux(dato,a->obtiene_izquierda());
else
    return encuentra_en_ABB_Aux(dato,a->obtiene_derecha());
}

bool ArbolABB::encuentra_en_arbol_ABB(int dato){
    return encuentra_en_ABB_Aux(dato, raiz);
}

void ArbolABB::agrega_en_el_auxili(int dato, NodoArbol*& aux){
    if (aux == NULL){
        NodoArbol * n= new NodoArbol(dato);
        aux = n;
    }
    else{
        if(dato > aux->obtener_datos())
            agrega_en_el_auxili(dato, aux->obtiene_derecha());
        else
            agrega_en_el_auxili(dato, aux->obtiene_izquierda());
    }
}

void ArbolABB::insertar(int i){
    if(!encuentra_en_arbol_ABB(i))
        agrega_en_el_auxili(i,raiz);
}

string ArbolABB::posOrden (NodoArbol* a){
    if (a == NULL){
        return "";
    }
    else{
        return posOrden (a->obtiene_izquierda()) + posOrden (a->obtiene_derecha()) + numeros_de_string(a->obtener_datos()) + " ";
    }

}

string ArbolABB::preOrden(NodoArbol* a){
    if (a == NULL){
        return "";
    }
    else{
        return numeros_de_string(a->obtener_datos()) + " " + preOrden (a->obtiene_izquierda()) + preOrden (a->obtiene_derecha());
    }
}

string ArbolABB::ver_arbol(int tipo){
    string resultado = "";
    switch(tipo){
    case 1: resultado = en_orden(raiz);break;
    case 2: resultado = preOrden(raiz);break;
    case 3: resultado = posOrden(raiz);break;
    }
    return resultado;
}
string ArbolABB::numeros_de_string(int n){
    stringstream convert;
    convert << n;
    return convert.str();
}

string ArbolABB::en_orden(NodoArbol*a){
    if (a == NULL){
        return "";
    }
    else{
        return en_orden(a->obtiene_izquierda()) + numeros_de_string(a->obtener_datos()) + " " + en_orden(a->obtiene_derecha());
    }
}


int ArbolABB::cantidad_de_nodos_presente(){
if (raiz == NULL){
    return 0;
}
    else{
        int contador = 1;
        return contador + cantidad_nodos_auxiliar(raiz->obtiene_izquierda()) + cantidad_nodos_auxiliar(raiz->obtiene_derecha());
    }
}


int ArbolABB::cantidad_nodos_auxiliar(NodoArbol* a){
    if (a != NULL){
    return 1 + cantidad_nodos_auxiliar(a->obtiene_izquierda()) + cantidad_nodos_auxiliar(a->obtiene_derecha());
}
    else{
        return 0;
    }
}

string ArbolABB::ruta(int num){
    if (encuentra_en_arbol_ABB(num) == true){
        return rutaAux(num, raiz);
    }
    else
        return "El valor no se encuentra en el arbol";
}

string ArbolABB::rutaAux(int dato,NodoArbol* a){
if(dato == a->obtener_datos())
    return numeros_de_string(a->obtener_datos());
if (dato < a->obtener_datos())
    return numeros_de_string(a->obtener_datos()) + " " + rutaAux(dato,a->obtiene_izquierda());
else
    return numeros_de_string(a->obtener_datos()) + " " + rutaAux(dato,a->obtiene_derecha());
}

string ArbolABB::nodos_hoja(){
    if (raiz != NULL){
        return nodosHojaAux(raiz);
    }
    else
        return "";
}

string ArbolABB::nodosHojaAux(NodoArbol* a){
    if (a == NULL)
        return "";
    if (a->obtiene_izquierda() == NULL && a->obtiene_derecha() == NULL){
        return numeros_de_string(a->obtener_datos()) + " ";
}
    else{
        return nodosHojaAux(a->obtiene_izquierda()) + nodosHojaAux(a->obtiene_derecha());
    }
}

string ArbolABB::nodos_internos_arbol(){
     if (raiz != NULL){
        return nodosInternosAux(raiz);
    }
    else
        return "";
}

string ArbolABB::nodosInternosAux(NodoArbol* a){
    if (a == NULL)
        return "";
    if (a->obtiene_izquierda() != NULL || a->obtiene_derecha() != NULL){
        return numeros_de_string(a->obtener_datos()) + " " + nodosInternosAux(a->obtiene_izquierda()) + nodosInternosAux(a->obtiene_derecha());
}
    else{
        return nodosInternosAux(a->obtiene_izquierda()) + nodosInternosAux(a->obtiene_derecha());
    }
}

int ArbolABB::un_nivel_nodos_auxili(NodoArbol* a, int cont){
if (a == NULL)
    return 0;
if (cont == 0)
    return 1;
else
    return un_nivel_nodos_auxili(a->obtiene_derecha(),cont-1) + un_nivel_nodos_auxili(a->obtiene_izquierda(),cont-1);
}

int ArbolABB::un_nivel_nodos(int n){
if (raiz != NULL){
        return un_nivel_nodos_auxili(raiz,n);
    }
    else
        return 0;
}

int ArbolABB::nivel_de_un_nodo(int dato){
if (encuentra_en_arbol_ABB(dato) == true){
        int nivel = 0;
        return nivel_de_un_nodo_auxiliar(dato, nivel, raiz);
}
else
    return -1;
}

int ArbolABB::nivel_de_un_nodo_auxiliar(int dato, int nivel, NodoArbol* a){
if(dato == a->obtener_datos())
    return nivel;
if (dato < a->obtener_datos())
    return nivel_de_un_nodo_auxiliar(dato,nivel+1,a->obtiene_izquierda());
else
    return nivel_de_un_nodo_auxiliar(dato,nivel+1,a->obtiene_derecha());
}

int ArbolABB::altura(){
if (raiz != NULL){
    int nivel = 0;
    int cuenta = 1;
    while (cuenta != 0){
        cuenta = un_nivel_nodos(nivel);
        nivel++;
    }
    return nivel-1;
}
else
    return 0;
}

string ArbolABB::sucesores(int dato){
if (raiz != NULL && encuentra_en_arbol_ABB(dato) == true){
    int nivel = nivel_de_un_nodo(dato);
    return sucesores_del_arbol_auxiliar(raiz, nivel, 0);
}
else
    return "El valor no se encuentra en el valor";
}

string ArbolABB::sucesores_del_arbol_auxiliar(NodoArbol* a, int nivel, int cont){
if (a == NULL)
    return "";
if (cont < nivel)
    return numeros_de_string(a->obtener_datos())+ " " + sucesores_del_arbol_auxiliar(a->obtiene_izquierda(), nivel, cont+1) + sucesores_del_arbol_auxiliar(a->obtiene_derecha(), nivel, cont+1);
else
    return "";
}

int ArbolABB::obtiene_padre(int dato){
if (encuentra_en_arbol_ABB(dato) == true && nivel_de_un_nodo(dato) != 0){
    return obtiene_padre_arbol_auxiliar(raiz, dato, raiz->obtener_datos());
}
else
    return -1;
}

int ArbolABB::obtiene_padre_arbol_auxiliar(NodoArbol* a, int dato, int pad){
if (dato == a->obtener_datos())
    return pad;
if (dato < a->obtener_datos())
    return obtiene_padre_arbol_auxiliar(a->obtiene_izquierda(), dato, a->obtener_datos());
else
    return obtiene_padre_arbol_auxiliar(a->obtiene_derecha(), dato, a->obtener_datos());
}

NodoArbol* ArbolABB::obtiene_nodo(int dato){
if (encuentra_en_arbol_ABB(dato) == true){
    return obtiene_nodo_auxiliar(raiz, dato);
}
else
    return NULL;
}

NodoArbol* ArbolABB::obtiene_nodo_auxiliar(NodoArbol* a, int dato){
if (dato == a->obtener_datos())
    return a;
if (dato < a->obtener_datos())
    return obtiene_nodo_auxiliar(a->obtiene_izquierda(), dato);
else
    return obtiene_nodo_auxiliar(a->obtiene_derecha(), dato);
}

string ArbolABB::recorrer_arbol_por_ancho(){
if (raiz != NULL){
        string str;
        for (int i = 0; i < altura();i++){
            str += recorrer_arbol_por_ancho_auxiliar(raiz , i);
        }
        return str;
    }
    else
    return "El arbol se encuentra vacio ";
}

string ArbolABB::recorrer_arbol_por_ancho_auxiliar(NodoArbol* a, int cont){
if (a == NULL)
    return "";
if (cont == 0)
    return numeros_de_string(a->obtener_datos())+ " ";
else
    return recorrer_arbol_por_ancho_auxiliar(a->obtiene_izquierda(),cont-1) + recorrer_arbol_por_ancho_auxiliar(a->obtiene_derecha(),cont-1);
}


bool ArbolABB::arbol_esta_lleno(){
if (raiz != NULL){
        int num = esta_arbol_auxiliar_lleno(raiz);
        if (num != 0)
            return false;
        else
            return true;
    }
    else
    return false;
}

int ArbolABB::esta_arbol_auxiliar_lleno(NodoArbol* a){
if (a == NULL)
    return 0;
if (a->obtiene_derecha() == NULL && a->obtiene_izquierda() != NULL)
    return 1;
if (a->obtiene_izquierda() == NULL && a->obtiene_derecha() != NULL)
    return 1;
else
    return esta_arbol_auxiliar_lleno(a->obtiene_derecha()) + esta_arbol_auxiliar_lleno(a->obtiene_izquierda());
}

bool ArbolABB::arbol_esta_completo(){
if (raiz != NULL){
        if (cantidad_de_nodos_presente() == 1)
            return false;
        if (cantidad_de_nodos_presente() == total_nodos(0,altura()))
            return true;
        if (cantidad_de_nodos_presente() > total_nodos(0,altura()-1) && cantidad_de_nodos_presente() < total_nodos(0,altura())){
            string str = arbol_auxiliar_esta_completo(raiz, altura()-1);
            int tamano = pow (2,altura()-1);
            for(int i = 0;i < tamano-1;i++){
                if (str[i] == '0' && str[i+1] != '0')
                    return false;
            }
            return true;
        }
        else
            return false;
    }
    else
    return false;
}

int ArbolABB::total_nodos(int y, int elev){
if (y == elev)
    return 0;
else
    return pow(2,y) + total_nodos(y+1,elev);
}


string ArbolABB::arbol_auxiliar_esta_completo(NodoArbol* a,int cont){
if (a == NULL && cont == 0)
    return "0";
if (a == NULL)
    return "";
if (cont == 0)
    return "1";
else
    return arbol_auxiliar_esta_completo(a->obtiene_izquierda(),cont-1) + arbol_auxiliar_esta_completo(a->obtiene_derecha(),cont-1);
}

bool ArbolABB::compara_cant_elem( ArbolABB* otroArbol){
if (raiz != NULL){
        if (otroArbol->ver_arbol(1) == ver_arbol(1))
            return true;
        else
            return false;
    }
    else
    return false;
}

bool ArbolABB::de_altura_son_iguales( ArbolABB* otroArbol){
if (raiz != NULL){
        for (int i =0;i<altura();i++){
            if (otroArbol->arbol_auxiliar_esta_completo(otroArbol->obtener_raiz(),i) != arbol_auxiliar_esta_completo(raiz,i))
                return false;
        }
        return true;
    }
    else
    return false;
}

bool ArbolABB::eliminar_nodo(int n){
if (raiz != NULL && encuentra_en_arbol_ABB(n) == true){
    if (obtiene_nodo(n) == raiz && raiz->obtiene_derecha() == NULL && raiz->obtiene_izquierda() == NULL){
            NodoArbol*borrar;
            borrar = raiz;
            raiz = NULL;
            delete borrar;
    }
    else if(obtiene_nodo(n) == raiz){
        if(raiz->obtiene_derecha() == NULL){
        NodoArbol* num1 = new NodoArbol(raiz->obtener_datos());
        NodoArbol* aux = new NodoArbol(raiz->obtiene_izquierda()->obtener_datos());
        aux->obtiene_izquierda() = num1;
        aux->obtiene_derecha() = NULL;
        num1->obtiene_derecha() = raiz->obtiene_izquierda()->obtiene_derecha();
        num1->obtiene_izquierda() = raiz->obtiene_izquierda()->obtiene_izquierda();
        NodoArbol* y = raiz;
        NodoArbol* x = raiz->obtiene_izquierda();
        delete y;
        delete x;
        raiz = aux;
        eliminar_nodo_case_2(aux, num1);
        }
        else{
        NodoArbol* num1 = new NodoArbol(raiz->obtener_datos());
        NodoArbol* aux = new NodoArbol(raiz->obtiene_derecha()->obtener_datos());
        aux->obtiene_izquierda() = raiz->obtiene_izquierda();
        aux->obtiene_derecha() = num1;
        num1->obtiene_derecha() = raiz->obtiene_derecha()->obtiene_derecha();
        num1->obtiene_izquierda() = raiz->obtiene_derecha()->obtiene_izquierda();
        NodoArbol* y = raiz;
        NodoArbol* x = raiz->obtiene_derecha();
        delete y;
        delete x;
        raiz = aux;
        eliminar_nodo_case_2(aux, num1);
        }
    }
    else{
    eliminar_nodo_case_2(obtiene_nodo(obtiene_padre(n)) , obtiene_nodo(n));
    }
    return true;
}
else
    return false;
}

void ArbolABB::eliminar_nodo_case_1(NodoArbol* padre, NodoArbol*num){
    NodoArbol* borrar;
        if (num == padre->obtiene_derecha()){
            borrar = padre->obtiene_derecha();
            padre->obtiene_derecha() = NULL;
            delete borrar;
        }
        else{
            borrar = padre->obtiene_izquierda();
            padre->obtiene_izquierda() = NULL;
            delete borrar;
        }
}

void ArbolABB::eliminar_nodo_case_2(NodoArbol* padre, NodoArbol* num){
    if (num->obtiene_izquierda() == NULL && num->obtiene_derecha() == NULL){
        eliminar_nodo_case_1(padre,num);
    }
    else if (num->obtiene_izquierda() == NULL && num->obtiene_derecha() != NULL){
        NodoArbol* num1 = new NodoArbol(num->obtener_datos());
        NodoArbol* aux = new NodoArbol(num->obtiene_derecha()->obtener_datos());
        if (padre->obtiene_derecha() == num)
            padre->obtiene_derecha() = aux;
        else
            padre->obtiene_izquierda() = aux;
        aux->obtiene_izquierda() = NULL;
        aux->obtiene_derecha() = num1;
        padre = num;
        num = num->obtiene_derecha();
        num1->obtiene_derecha() = num->obtiene_derecha();
        num1->obtiene_izquierda() = num ->obtiene_izquierda();
        delete padre;
        delete num;
        eliminar_nodo_case_2(aux, num1);
    }
    else if (num->obtiene_izquierda() != NULL){
        NodoArbol* num1 = new NodoArbol(num->obtener_datos());
        NodoArbol* aux = new NodoArbol(num->obtiene_izquierda()->obtener_datos());
        if (padre->obtiene_derecha() == num){
            padre->obtiene_derecha() = aux;
        }
        else{
            padre->obtiene_izquierda() = aux;
        }
        aux->obtiene_izquierda() = num1;
        aux->obtiene_derecha() = num->obtiene_derecha();
        padre = num;
        num = num->obtiene_izquierda();
        num1->obtiene_derecha() = num->obtiene_derecha();
        num1->obtiene_izquierda() = num ->obtiene_izquierda();
        delete padre;
        delete num;
        eliminar_nodo_case_2(aux, num1);
    }
}
