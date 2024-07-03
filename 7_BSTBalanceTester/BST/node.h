#ifndef NODE_H
#define NODE_H


# include <iostream>
# include <cstdlib>
#include "queue"
using namespace std;

// structs de los nodos
struct node{
    int valor;
    struct node *izquierda;
    struct node *derecha;
};

//inciando nodos
struct node *base;

// clase BST
class BinarySearchTree{
    public:
        void insert(node *, node *);
        void dataIn(int, node **, node **);
        void remove(int);
        void remove_when_everything_is_null(node *, node *);
        void remove_when_everything_is_not_emty(node *, node *);
        void remove_when_has_two_hijoren(node *, node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void Mostrar_el_Arbol(node *, int);

        BinarySearchTree(){
            base = NULL;
        }
};



void BinarySearchTree::dataIn(int val, node **par, node **local){
    node *puntero;
    node *puntero_guardar;
    // si se encuentra vacio
    if(base == NULL){
        *local = NULL;
        *par = NULL;
        return;
    // sino tiene padre
    }
    if(val == base->valor){
        *local = base;
        *par = NULL;
        return;
    // buscando por las ramas
    }
    if(val < base->valor)
        puntero = base->izquierda;
    else
        puntero = base->derecha;
    puntero_guardar = base;
    while(puntero != NULL){
        if(val == puntero->valor){
            *local = puntero;
            *par = puntero_guardar;
            return;
        }
        puntero_guardar = puntero;
        if(val < puntero->valor)
            puntero = puntero->izquierda;
        else
            puntero = puntero->derecha;
    }
    // no se encuentra
    *local = NULL;
    *par = puntero_guardar;
}

// Digitar elemento
void BinarySearchTree::insert(node *tree, node *newNode){
    if(base == NULL){
        base = new node;
        base->valor = newNode->valor;
        base->izquierda = NULL;
        base->derecha = NULL;
        cout<<"Se creó la base del árbol"<<endl;
        return;
    }
    if(tree->valor == newNode->valor){
        cout<<"Ya se encuentra en el árbol, favor revisar si desea otro valor"<<endl;
        return;
    }
    if(tree->valor > newNode->valor){
        if(tree->izquierda != NULL){
            insert(tree->izquierda, newNode);
        }
        else{
            tree->izquierda = newNode;
            (tree->izquierda)->izquierda = NULL;
            (tree->izquierda)->derecha = NULL;
            cout<<"Agregando valor a la izquierda \n "<<endl;
            return;
        }
    }
    else{
        if(tree->derecha != NULL){
            insert(tree->derecha, newNode);
        }
        else{
            tree->derecha = newNode;
            (tree->derecha)->izquierda = NULL;
            (tree->derecha)->derecha = NULL;
            cout<<"Agregando valor a la derecha \n"<<endl;
            return;
        }
    }
}

void BinarySearchTree::remove(int val){
    node *padre;
    node *localation;
    if(base == NULL){
        cout<<"Está vacio, debe ingresar algo si desea eliminarlo \n"<<endl;
        return;
    }
    dataIn(val, &padre, &localation);
    if(localation == NULL){
        cout<<"No se encuentra en el árbol \n"<<endl;
        return;
    }
    if(localation->izquierda == NULL && localation->derecha == NULL)
        remove_when_everything_is_null(padre, localation);
    if(localation->izquierda == NULL && localation->derecha != NULL)
        remove_when_everything_is_not_emty(padre, localation);
    if(localation->izquierda != NULL && localation->derecha == NULL)
        remove_when_everything_is_not_emty(padre, localation);
    if(localation->izquierda != NULL && localation->derecha != NULL)
        remove_when_has_two_hijoren(padre, localation);
    free(localation);
}

void BinarySearchTree::remove_when_everything_is_null(node *par, node *local){

    if(par == NULL){
        base = NULL;
    }
    else{
        if(local == par->izquierda)
            par->izquierda = NULL;
        else
            par->derecha = NULL;
    }
}

void BinarySearchTree::remove_when_everything_is_not_emty(node *par, node *local){
    node *hijo;
// esta a la izquierda o a la derecha
    if(local->izquierda != NULL)
        hijo = local->izquierda;
    else
        hijo = local->derecha;

    if(par == NULL){
        base = hijo;
    }
    else{

        if(local == par->izquierda)
            par->izquierda = hijo;
        else
            par->derecha = hijo;
    }
}

void BinarySearchTree::remove_when_has_two_hijoren(node *par, node *local){
    node *puntero;
    node *puntero_guardar;
    node *suc;
    node *parsuc;

    puntero_guardar = local;
    puntero = local->derecha;
    while(puntero->izquierda != NULL){
        puntero_guardar = puntero;
        puntero = puntero->izquierda;
    }
    suc = puntero;
    parsuc = puntero_guardar;

    if(suc->izquierda == NULL && suc->derecha == NULL)
        remove_when_everything_is_null(parsuc, suc);
    else
        remove_when_everything_is_not_emty(parsuc, suc);
    if(par == NULL){
        base = suc;
    }
    else{
        if(local == par->izquierda)
            par->izquierda = suc;
        else
            par->derecha = suc;
    }
    suc->izquierda = local->izquierda;
    suc->derecha = local->derecha;
}

// Preorder
void BinarySearchTree::preorder(node *puntero){
    if(base == NULL){
        cout<<"Se encuenta vacio \n"<<endl;
        return;
    }
    if(puntero != NULL){
        cout<<puntero->valor<<"  ";
        preorder(puntero->izquierda);
        preorder(puntero->derecha);
    }
}

// Inorder
void BinarySearchTree::inorder(node *puntero){
    if(base == NULL){
        cout<<"Se encuenta vacio \n  "<<endl;
        return;
    }
    if(puntero != NULL){
        inorder(puntero->izquierda);
        cout<<puntero->valor<<"  ";
        inorder(puntero->derecha);
    }
}

//Postorder
void BinarySearchTree::postorder(node *puntero){
    if(base == NULL){
        cout<<"Se encuenta vacio \n"<<endl;
        return;
    }
    if(puntero != NULL){
        postorder(puntero->izquierda);
        postorder(puntero->derecha);
        cout<<puntero->valor<<"  ";
    }
}

//se  visualiza como arbol
void BinarySearchTree::Mostrar_el_Arbol(node *puntero, int level){
    int i;
    if(puntero != NULL){
        Mostrar_el_Arbol(puntero->derecha, level+1);
        cout<<endl;
        if(puntero == base)
            cout<<"Tenemos:  \n ";
        else{
            // para diferentes nivelos
            for(i = 0; i < level; i++)
                cout<<"       ";
        }
        cout<<puntero->valor;
        Mostrar_el_Arbol(puntero->izquierda, level+1);
    }
}


#endif
