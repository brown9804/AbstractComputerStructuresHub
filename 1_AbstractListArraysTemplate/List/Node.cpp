#include "Node.h"

#include<iostream>
using namespace std;

template<class T>
Node<T>::Node()
{
    Data=0;
    siguiente=0;
}

template<class T>
Node<T>::Node(T Data)
{
    this->Data=Data;
    siguiente=0;
}

template<class T>
Node<T>::Node(const Node<T> &RHS)
{
    this->Data=RHS.Data;
    this->siguiente=new Node<T>;
    this->siguiente=RHS.siguiente;
}

template<class T>
Node<T>::Node(T Data,Node<T> *siguiente)
{
    this->Data=Data;
    this->siguiente=new Node<T>;
    this->siguiente=siguiente;
}

template<class T>
Node<T>& Node<T>::operator =(const Node<T> &RHS)
{
    if(this!=&RHS)
    {
        delete this->siguiente;
        this->siguiente=new Node<T>;
        this->siguiente=RHS.siguiente;
        this->Data=RHS.Data;
    }
    return (*this);
}

template<class T>
void Node<T>::Pone_Datos(T Data)
{
    this->Data=Data;
}

template<class T>
void Node<T>::Fija_siguien(Node<T> *siguiente)
{
    this->siguiente=siguiente;
}

template<class T>
Node<T>* Node<T>::Obt_Nodo()
{
    return (*this);
}

template<class T>
T Node<T>::Obt_Datos()
{
    return Data;
}

template<class T>
Node<T>* Node<T>::Obtiene_siguiente_nodo()
{
    return siguiente;
}

template<class T>
Node<T>::~Node()
{
    if(siguiente!=0)
    {
        delete siguiente;
    }
    siguiente=0;
}
