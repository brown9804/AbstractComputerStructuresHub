#include "header.h"

using namespace std;
struct node {
int Datos_ramas_arb_valor{};
    node* izquierda = nullptr;
    node* derecha = nullptr;
    node* padre_arbol = nullptr;
    string color_rojo_negro;
};
class Arbol_Rojo_Negro {
    node* raiz;
public:
Arbol_Rojo_Negro() : raiz(nullptr) {}
        node* Obtener_Base(){ return raiz; }
void Agregar_nodo_arbol(int obj) {
if(raiz == nullptr){
               raiz = new node();
               raiz->Datos_ramas_arb_valor = obj;
               raiz->padre_arbol = nullptr;
               raiz->color_rojo_negro = "Negro";
               cout << "-----------------------\n";
               cout << "Se agregó el valor\n";
               cout << "-----------------------\n";

           }
else {
auto enlace = Obtener_Base();
               node* nueva_nodo = new node();
               nueva_nodo->Datos_ramas_arb_valor = obj;
while(enlace != nullptr){
if(enlace->Datos_ramas_arb_valor > obj){
if(enlace->izquierda == nullptr){
                           enlace->izquierda = nueva_nodo;
                           nueva_nodo->color_rojo_negro = "Rojo";
                           nueva_nodo->padre_arbol = enlace;
                           cout << "-----------------------\n";
                           cout << "Se agregó el valor\n";
                           cout << "-----------------------\n";
                           break; }


else { enlace = enlace->izquierda; }
                   } else {
if(enlace->derecha == nullptr){
                           enlace->derecha = nueva_nodo;
                           nueva_nodo->color_rojo_negro = "Rojo";
                           nueva_nodo->padre_arbol = enlace;
                           cout << "-----------------------\n";
                           cout << "Se agregó el valor\n";
                           cout << "-----------------------\n";
                           break; }
else {  enlace = enlace->derecha; }
                   }
               }
Rojo_Negro_Arreglo(nueva_nodo);
           }
        }
void Rojo_Negro_Arreglo(node* iterador_num) {
while(iterador_num->padre_arbol->color_rojo_negro == "Rojo") {
auto padre_padre = iterador_num->padre_arbol->padre_arbol;
auto padre_hermano = Obtener_Base();
if(iterador_num->padre_arbol == padre_padre->izquierda) {
if(padre_padre->derecha) { padre_hermano = padre_padre->derecha; }
if(padre_hermano->color_rojo_negro == "Rojo"){
                        iterador_num->padre_arbol->color_rojo_negro = "Negro";
                        padre_hermano->color_rojo_negro = "Negro";
                        padre_padre->color_rojo_negro = "Rojo";
if(padre_padre->Datos_ramas_arb_valor != raiz->Datos_ramas_arb_valor){ iterador_num = padre_padre; }
else { break; }
                    }
else if(iterador_num == padre_padre->izquierda->derecha) {
Rotacion_izquierda(iterador_num->padre_arbol);
                    }
else {
                        iterador_num->padre_arbol->color_rojo_negro = "Negro";
                        padre_padre->color_rojo_negro = "Rojo";
Rotacion_derecha(padre_padre);
if(padre_padre->Datos_ramas_arb_valor != raiz->Datos_ramas_arb_valor){ iterador_num = padre_padre; }
else { break; }
                    }
                }
else {
if(padre_padre->izquierda) { padre_hermano = padre_padre->izquierda; }
if(padre_hermano->color_rojo_negro == "Rojo"){
                        iterador_num->padre_arbol->color_rojo_negro = "Negro";
                        padre_hermano->color_rojo_negro = "Negro";
                        padre_padre->color_rojo_negro = "Rojo";
if(padre_padre->Datos_ramas_arb_valor != raiz->Datos_ramas_arb_valor){ iterador_num = padre_padre; }
else { break; }
                    }
else if(iterador_num == padre_padre->derecha->izquierda){
Rotacion_derecha(iterador_num->padre_arbol);
                    }
else {
                        iterador_num->padre_arbol->color_rojo_negro = "Negro";
                        padre_padre->color_rojo_negro = "Rojo";
Rotacion_izquierda(padre_padre);
if(padre_padre->Datos_ramas_arb_valor != raiz->Datos_ramas_arb_valor){ iterador_num = padre_padre; }
else { break; }
                    }
                }
            }
            raiz->color_rojo_negro = "Negro";
        }
void eliminar_nodo(node* padre_arbol, node* curr, int obj) {
if(curr == nullptr) { return; }
if(curr->Datos_ramas_arb_valor == obj) {
//CASE -- 1
if(curr->izquierda == nullptr && curr->derecha == nullptr) {
if(padre_arbol->Datos_ramas_arb_valor == curr->Datos_ramas_arb_valor){ raiz = nullptr; }
else if(padre_arbol->derecha == curr) {
Eliminar_Rojo_Negro_Arreglo(curr);
                        padre_arbol->derecha = nullptr;
                    }
else {
Eliminar_Rojo_Negro_Arreglo(curr);
                        padre_arbol->izquierda = nullptr;
                    }
                }
//CASE -- 2
else if(curr->izquierda != nullptr && curr->derecha == nullptr) {
int swap = curr->Datos_ramas_arb_valor;
                    curr->Datos_ramas_arb_valor = curr->izquierda->Datos_ramas_arb_valor;
                    curr->izquierda->Datos_ramas_arb_valor = swap;
eliminar_nodo(curr, curr->derecha, obj);
                }
else if(curr->izquierda == nullptr && curr->derecha != nullptr) {
int swap = curr->Datos_ramas_arb_valor;
                    curr->Datos_ramas_arb_valor = curr->derecha->Datos_ramas_arb_valor;
                    curr->derecha->Datos_ramas_arb_valor = swap;
eliminar_nodo(curr, curr->derecha, obj);
                }


else {
bool flag = false;
                    node* temp = curr->derecha;
while(temp->izquierda) { flag = true; padre_arbol = temp; temp = temp->izquierda; }
if(!flag) { padre_arbol = curr; }
int swap = curr->Datos_ramas_arb_valor;
                    curr->Datos_ramas_arb_valor = temp->Datos_ramas_arb_valor;
                    temp->Datos_ramas_arb_valor = swap;
eliminar_nodo(padre_arbol, temp, swap);
                }
            }
        }
void eliminar(int obj) {
auto temp = raiz;
auto padre_arbol = temp;
bool flag = false;
if(!temp) { eliminar_nodo(nullptr, nullptr, obj); }
while(temp) {
if(obj == temp->Datos_ramas_arb_valor) { flag = true; eliminar_nodo(padre_arbol, temp, obj); break; }
else if(obj < temp->Datos_ramas_arb_valor) { padre_arbol = temp ; temp = temp->izquierda; }
else { padre_arbol = temp ; temp = temp->derecha; }
            }
if(!flag) { cout << "\n ➼➼➼➼ El valor no se encuentra ➼➼➼➼\n"; }
        }
void Eliminar_Rojo_Negro_Arreglo(node* iterador_num) {
while(iterador_num->Datos_ramas_arb_valor != raiz->Datos_ramas_arb_valor && iterador_num->color_rojo_negro == "Negro") {
auto sibling = Obtener_Base();
if(iterador_num->padre_arbol->izquierda == iterador_num) {
if(iterador_num->padre_arbol->derecha){ sibling = iterador_num->padre_arbol->derecha; }
if(sibling) {


if(sibling->color_rojo_negro == "Rojo") {
                            sibling->color_rojo_negro = "Negro";
                            iterador_num->padre_arbol->color_rojo_negro = "Rojo";
Rotacion_izquierda(iterador_num->padre_arbol);
                            sibling = iterador_num->padre_arbol->derecha;
                        }


if(sibling->izquierda == nullptr && sibling->derecha == nullptr) {
                            sibling->color_rojo_negro = "Rojo";
                            iterador_num = iterador_num->padre_arbol;
                        }
else if(sibling->izquierda->color_rojo_negro == "Negro" && sibling->derecha->color_rojo_negro == "Negro") {
                            sibling->color_rojo_negro = "Rojo";
                            iterador_num = iterador_num->padre_arbol;
                        }


else if(sibling->derecha->color_rojo_negro == "Negro") {
                            sibling->izquierda->color_rojo_negro = "Negro";
                            sibling->color_rojo_negro = "Rojo";
Rotacion_derecha(sibling);
                            sibling = iterador_num->padre_arbol->derecha;
                        } else {
                            sibling->color_rojo_negro = iterador_num->padre_arbol->color_rojo_negro;
                            iterador_num->padre_arbol->color_rojo_negro = "Negro";
if(sibling->derecha){ sibling->derecha->color_rojo_negro = "Negro"; }
Rotacion_izquierda(iterador_num->padre_arbol);
                            iterador_num = raiz;
                        }
                    }
                } else {
if(iterador_num->padre_arbol->derecha == iterador_num){
if(iterador_num->padre_arbol->izquierda){ sibling = iterador_num->padre_arbol->izquierda; }
if(sibling) {


if(sibling->color_rojo_negro == "Rojo"){
                                sibling->color_rojo_negro = "Negro";
                                iterador_num->padre_arbol->color_rojo_negro = "Rojo";
Rotacion_derecha(iterador_num->padre_arbol);
                                sibling = iterador_num->padre_arbol->izquierda;
                            }




if(sibling->izquierda == nullptr && sibling->derecha == nullptr) {
                                sibling->color_rojo_negro = "Rojo";
                                iterador_num = iterador_num->padre_arbol;
                            }
else if(sibling->izquierda->color_rojo_negro == "Negro" && sibling->derecha->color_rojo_negro == "Negro") {
                                sibling->color_rojo_negro = "Rojo";
                                iterador_num = iterador_num->padre_arbol;
                            }



else if(sibling->izquierda->color_rojo_negro == "Negro") {
                                sibling->derecha->color_rojo_negro = "Negro";
                                sibling->color_rojo_negro = "Rojo";
Rotacion_derecha(sibling);
                                sibling = iterador_num->padre_arbol->izquierda;
                            } else {
                                sibling->color_rojo_negro = iterador_num->padre_arbol->color_rojo_negro;
                                iterador_num->padre_arbol->color_rojo_negro = "Negro";
if(sibling->izquierda){ sibling->izquierda->color_rojo_negro = "Negro"; }
Rotacion_izquierda(iterador_num->padre_arbol);
                                iterador_num = raiz;
                            }
                        }
                    }
                }
            }
            iterador_num->color_rojo_negro = "Negro";
        }
        node* TreeSearch(int obj) {
auto temp = Obtener_Base();
if(temp == nullptr) { return nullptr; }
while(temp) {
if(obj == temp->Datos_ramas_arb_valor){ return temp; }
else if(obj < temp->Datos_ramas_arb_valor){ temp = temp->izquierda; }
else { temp = temp->derecha; }
            }
return nullptr;
        }
void Rotacion_izquierda(node* x) {
            node* nw_node = new node();
if(x->derecha->izquierda) { nw_node->derecha = x->derecha->izquierda; }
            nw_node->izquierda = x->izquierda;
            nw_node->Datos_ramas_arb_valor = x->Datos_ramas_arb_valor;
            nw_node->color_rojo_negro = x->color_rojo_negro;
            x->Datos_ramas_arb_valor = x->derecha->Datos_ramas_arb_valor;
            x->izquierda = nw_node;
if(nw_node->izquierda){ nw_node->izquierda->padre_arbol = nw_node; }
if(nw_node->derecha){ nw_node->derecha->padre_arbol = nw_node; }
            nw_node->padre_arbol = x;
if(x->derecha->derecha){ x->derecha = x->derecha->derecha; }
else { x->derecha = nullptr; }
if(x->derecha){ x->derecha->padre_arbol = x; }
        }
void Rotacion_derecha(node* x) {
            node* nw_node = new node();
if(x->izquierda->derecha){ nw_node->izquierda = x->izquierda->derecha; }
            nw_node->derecha = x->derecha;
            nw_node->Datos_ramas_arb_valor = x->Datos_ramas_arb_valor;
            nw_node->color_rojo_negro = x->color_rojo_negro;
            x->Datos_ramas_arb_valor = x->izquierda->Datos_ramas_arb_valor;
            x->color_rojo_negro = x->izquierda->color_rojo_negro;
            x->derecha = nw_node;
if(nw_node->izquierda){ nw_node->izquierda->padre_arbol = nw_node; }
if(nw_node->derecha){ nw_node->derecha->padre_arbol = nw_node; }
            nw_node->padre_arbol = x;
if(x->izquierda->izquierda){ x->izquierda = x->izquierda->izquierda; }
else { x->izquierda = nullptr; }
if(x->izquierda){ x->izquierda->padre_arbol = x; }
        }
void Pre_Ordenamiento_forma_lateral(node* temp) {
if(!temp){ return; }
            cout << "➼➼➼➼ " << temp->Datos_ramas_arb_valor << "[" << temp->color_rojo_negro << "]";
Pre_Ordenamiento_forma_lateral(temp->izquierda);
Pre_Ordenamiento_forma_lateral(temp->derecha);
        }
void Post_Ordenamiento_forma_lateral(node *temp) {
if(!temp){ return; }
Post_Ordenamiento_forma_lateral(temp->izquierda);
Post_Ordenamiento_forma_lateral(temp->derecha);
            cout << "➼➼➼➼ " << temp->Datos_ramas_arb_valor << "[" << temp->color_rojo_negro << "]";
        }
 };

void menu(){
            cout << "\n*******************************************";
            cout << "\n         Árbol rojo y negro                ";
            cout << "\n*******************************************";
            cout << "\n\n1. Agregar elemento al árbol";
            cout << "\n2. Buscar un elemento ";
            cout << "\n3. PRE-ORDER ";
            cout << "\n4. POST-ORDER ";
            cout << "\n5. Eliminar un elemento del árbol";
            cout << "\n6. Salir";
            cout << "\n*******************************************";
            cout << "\nEscoja una opción  ➼➼➼➼  ";
        }
