#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
	private:

        T Data;
        Node<T> *siguiente;

	public:

	    //Funciones principales
	    Node();
	    Node(T Data);
	    Node(const Node<T> &RHS);
	    Node<T>& operator =(const Node<T> &RHS);
	    Node(T Data,Node<T> *siguiente);
        ~Node();

	    //Funciones diferentes
        void Pone_Datos(T Data);
        void Fija_siguien(Node<T> *siguiente);
        Node<T>* Obt_Nodo();
        T Obt_Datos();
        Node* Obtiene_siguiente_nodo();

};
