#include <iostream>
#include "NodoArbol.h"
#include "ArbolABB.h"

using namespace std;

int main()
{
cout<<"\n*********************************\n"<<endl;

cout<<" Tester de arboles ABB #1\n "<<endl;

cout<<"\n*********************************\n"<<endl;

ArbolABB * elArbol = new ArbolABB();

ArbolABB * otroArbol = new ArbolABB();

int datosPrueba [] = {35,12,50,8,17,32,53,3,10, 29, 57};


int datosPruebaOtro [] = {53,12,50,8,17,32,3,10, 29, 57};
cout<<"\n----------------------------------\n"<<endl;

cout<<" Agregando valores\n "<<endl;

cout<<"\n----------------------------------\n"<<endl;

for (int i = 0; i < 11;i++){
    cout<<"Agregar "<<datosPrueba[i]<<endl;
    elArbol->insertar(datosPrueba[i]);
    otroArbol->insertar(datosPruebaOtro[i]);
}
cout<<"\n----------------------------------\n"<<endl;

cout<<" Comprobando cantidad de elementos entre árboles\n "<<endl;

cout<<"\n----------------------------------\n"<<endl;


if (elArbol->compara_cant_elem(otroArbol) == true)
    cout<<"Como resultado obtenemos que:\nSi son semejantes, respecto a la cantidad de elementos\n"<<endl;
if (elArbol->compara_cant_elem(otroArbol) == false)
    cout<<"Como resultado obtenemos que:\nNo son semejantes,respecto a la cantidad de elementos\n"<<endl;

cout<<"\n----------------------------------\n"<<endl;

cout<<" Prueba de altura entre árboles\n "<<endl;

cout<<"\n----------------------------------\n"<<endl;


if (elArbol->de_altura_son_iguales(otroArbol) == true)
    cout<<"Como resultado obtenemos que:\nDe altura son iguales\n"<<endl;
if (elArbol->de_altura_son_iguales(otroArbol) == false)
    cout<<"Como resultado obtenemos que:\nNo son iguales en altura\n"<<endl;

cout<<"\n----------------------------------\n"<<endl;

cout<<" Prueba de espacio en los árboles\n "<<endl;

cout<<"\n----------------------------------\n"<<endl;


cout<<"\nRealizando un recorrido a lo ancho del primer árbol \n"<<elArbol->recorrer_arbol_por_ancho()<<endl;
cout<<"\nRealizando un recorrido a lo ancho del segundo árbol\n"<<otroArbol->recorrer_arbol_por_ancho()<<endl;

if (elArbol->arbol_esta_lleno() == true)
    cout<<"Como resultado obtenemos que:\nSi esta lleno\n"<<endl;
if (elArbol->arbol_esta_lleno() == false)
    cout<<"Como resultado obtenemos que:\nNo esta lleno\n"<<endl;


if (elArbol->arbol_esta_completo() == true)
    cout<<"\nComo resultado obtenemos que:\nSi esta completo\n"<<endl;
if (elArbol->arbol_esta_completo() == false)
    cout<<"\nComo resultado obtenemos que:\nNo esta completo\n"<<endl;


cout<<"\n----------------------------------\n"<<endl;

cout<<" Eliminado hojas\n "<<endl;

cout<<"\n----------------------------------\n"<<endl;



cout<<"Borrando hoja 29\n "<<elArbol->eliminar_nodo(29)<<endl;
cout<<"Realizando un recorrido a lo ancho\n"<<elArbol->recorrer_arbol_por_ancho()<<endl;

cout<<"Borrando nodo con 0 hijo 53 \n"<<elArbol->eliminar_nodo(53)<<endl;
cout<<"Realizando un recorrido a lo ancho\n"<<elArbol->recorrer_arbol_por_ancho()<<endl;

cout<<"Borrando nodo con dos hijos 12\n"<<elArbol->eliminar_nodo(12)<<endl;
cout<<"Realizando un recorrido a lo ancho\n"<<elArbol->recorrer_arbol_por_ancho()<<endl;


cout<<"\n*********************************\n"<<endl;

cout<<" Tester de arboles ABB #2\n "<<endl;

cout<<"\n*********************************\n"<<endl;


ArbolABB* elLleno = new ArbolABB();
elLleno->insertar(29);
elLleno->insertar(11);
elLleno->insertar(28);
elLleno->insertar(18);
elLleno->insertar(31);

cout<<"El arbol (29,11,28,18,31):\n ";

if (elArbol->arbol_esta_lleno() == false)
    cout<<"No esta lleno\n"<<endl;

elLleno->insertar(8);
cout<<"El arbol (29,11,28,18,31,8): \n";
if (elLleno->arbol_esta_lleno() == true)
    cout<<"Si esta lleno"<<endl;
if (elLleno->arbol_esta_lleno() == false)
    cout<<"No esta lleno"<<endl;
cout<<"El arbol (29,11,28,18,31,8) \n";
if (elArbol->arbol_esta_completo() == true)
    cout<<"Si esta completo\n"<<endl;
if (elArbol->arbol_esta_completo() == false)
    cout<<"No esta completo\n"<<endl;




elLleno->insertar(9);
elLleno->insertar(5);
elLleno->insertar(10);
elLleno->insertar(12);
cout<<"El arbol (29,11,28,18,31,8,9,5,10,12) \n";
if (elLleno->arbol_esta_completo() == true)
    cout<<"Como resultado obtenemos que:\nSi esta completo\n"<<endl;
if (elLleno->arbol_esta_completo() == false)
    cout<<"Como resultado obtenemos que:\nNo esta completo\n"<<endl;



ArbolABB * elSemejante = new ArbolABB();
elSemejante->insertar(50);
elSemejante->insertar(46);
elSemejante->insertar(12);
elSemejante->insertar(23);
elSemejante->insertar(48);
elSemejante->insertar(53);
elSemejante->insertar(57);
elSemejante->insertar(68);
elSemejante->insertar(80);
cout<<"Los arboles (50,46,12,23,48,53,57,68,80) y (28,29,9,7,11,32,12,90,17) \n"<<endl;
if (elArbol->de_altura_son_iguales(elSemejante) == true)
    cout<<"Como resultado obtenemos que:\nSi comparamos la altura son iguales\n"<<endl;
if (elArbol->de_altura_son_iguales(elSemejante) == false)
    cout<<"Como resultado obtenemos que:\nComparando la altura no son iguales\n"<<endl;
ArbolABB * elIsoformo = new ArbolABB();
elIsoformo->insertar(53);
elIsoformo->insertar(80);
elIsoformo->insertar(23);
elIsoformo->insertar(57);
elIsoformo->insertar(46);
elIsoformo->insertar(12);
elIsoformo->insertar(50);
elIsoformo->insertar(68);
elIsoformo->insertar(48);
cout<<"Los arboles(50,46,12,23,48,53,57,68,80) y (53,80,23,57,46,12,50,68,48)\n "<<endl;
if (elIsoformo->compara_cant_elem(elSemejante) == true)
    cout<<"Como resultado obtenemos que:\nSi son semejantes\n"<<endl;
if (elIsoformo->compara_cant_elem(elSemejante) == false)
    cout<<"Como resultado obtenemos que:\nNo son semejantes\n"<<endl;

cout<<"\n//////////////////////////////////////////////////////////////\n"<<endl;
cout<<"Vamos a realizar las siguientes operaciones:\n ";
cout<<"\n//////////////////////////////////////////////////////////////\n"<<endl;

cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 32 \n"<<elArbol->eliminar_nodo(32)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 29 \n"<<elArbol->eliminar_nodo(29)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 28 \n"<<elArbol->eliminar_nodo(28)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 7 \n"<<elArbol->eliminar_nodo(7)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 12 \n"<<elArbol->eliminar_nodo(12)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 90 \n"<<elArbol->eliminar_nodo(90)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 17 \n"<<elArbol->eliminar_nodo(17)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 9 \n"<<elArbol->eliminar_nodo(9)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;
cout<<"Borrando hoja 11 \n"<<elArbol->eliminar_nodo(11)<<endl;
cout<<elArbol->ver_arbol(1)<<endl;


return 0;
}
