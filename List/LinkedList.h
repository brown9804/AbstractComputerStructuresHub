#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

template<class T>
class SingleLinkedList
{
	private:

        Node<T> *Head;
        Node<T> *Tail;
        int Size;
        void Elimina_todos_Nodos();

	public:

        //Funciones principales
        SingleLinkedList();
        SingleLinkedList(T Data);
        SingleLinkedList(const SingleLinkedList<T> &RHS);
        SingleLinkedList& operator =(const SingleLinkedList<T> &RHS);
        ~SingleLinkedList();

        //Funciones especiales
        Node<T>* GetHead();
        Node<T>* GetTail();
        int Obt_tamano();
        void Copy_Ar(const SingleLinkedList<T> &RHS);
        void Ingre_inicio(T Data);
        void Ingre_final(T Data);
        void Ingreso_en_posicion(T Data,int Index);
        void Eliminar_primero();
        void Eliminar_ultimo();
        void Eliminar_posicion(int Index);
        void Vuelta_lista();
        void Vuelta_datos();
        void Vuelta_lista(Node<T> *N);
        void Ver_lista();
        void GetNth(int Index);
        void Encontrar_dat(T Data);
        void Ordenar();
        void Eliminar_Dat(T Data);
};
