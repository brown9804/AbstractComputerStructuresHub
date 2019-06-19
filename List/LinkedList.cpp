#include "LinkedList.h"

#include<iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
    Head=Tail=0;
    Size=0;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    NewNode->Fija_siguien(0);
    Head=NewNode;
    Tail=NewNode;
    Head->Fija_siguien(Tail);
    Tail->Fija_siguien(0);
    Size=1;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &RHS)
{
    Head=0;
    Tail=0;
    Copy_Ar(RHS);
}

template<class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator = (const SingleLinkedList<T> &RHS)
{
    if(this!=&RHS)
    {
        if(Head!=NULL)
        {
            Elimina_todos_Nodos();
            delete Head;
        }
        if(Tail!=NULL)
        {
            delete Tail;
        }
        Head=Tail=0;
        Copy_Ar(RHS);
    }
    else
    {
        return (*this);
    }
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList()
{
    if(Head!=NULL)
    {
        Elimina_todos_Nodos();
        delete Head;
    }
    if(Tail!=NULL)
    {
        delete Tail;
    }
    Head=Tail=0;
    Size=0;
}

// Funciones especiales

template<class T>
Node<T>* SingleLinkedList<T>::GetHead()
{
    return Head;
}

template<class T>
Node<T>* SingleLinkedList<T>::GetTail()
{
    return Tail;
}

template<class T>
int SingleLinkedList<T>::Obt_tamano()
{
    return Size;
}

template <class T>
void SingleLinkedList<T>::Copy_Ar(const SingleLinkedList<T> &RHS)
{
    Node<T>* Temp=RHS.Head;
    Node<T>* Pre=RHS.Head;
    while(Temp!=0)
    {
        Node<T> *NewNode=new Node<T>(Temp->Obt_Datos());
        if(Head==0)
        {
            Head=NewNode;
            Tail=NewNode;
            Head->Fija_siguien(Tail);
            Pre=NewNode;
        }
        else
        {
            Pre->Fija_siguien(NewNode);
            Pre=NewNode;
            Tail=NewNode;
            Tail->Fija_siguien(0);
        }
        Size++;
        Temp=Temp->Obtiene_siguiente_nodo();
    }
}

template<class T>
void SingleLinkedList<T>::Ingre_inicio(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Head==0)
    {
        Head=NewNode;
        Tail=NewNode;
        Head->Fija_siguien(Tail);
        Tail->Fija_siguien(0);
    }
    else
    {
        NewNode->Fija_siguien(Head);
        Head=NewNode;
        Node<T> *Temp=Head;
    }
    Size++;
}

template<class T>
void SingleLinkedList<T>::Ingre_final(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Head==0)
    {
        Head=NewNode;
        Tail=NewNode;
        Head->Fija_siguien(Tail);
        Tail->Fija_siguien(0);
    }
    else
    {
        Tail->Fija_siguien(NewNode);
        Tail=NewNode;
    }
    Size++;
}

template<class T>
void SingleLinkedList<T>::Ingreso_en_posicion(T Data,int Index)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Index==1)
    {
        Ingre_inicio(Data);
    }
    else if(Index>0 && Index <=Size+1)
    {
        Node<T> *Pre=0;
        Node<T> *Cur=0;
        Cur=Head;
        for(int i=1;i<Index;i++)
        {
            Pre=Cur;
            Cur=Cur->Obtiene_siguiente_nodo();
        }
        Pre->Fija_siguien(NewNode);
        NewNode->Fija_siguien(Cur);
        Size++;
    }
    else
    {
        cout<<"\nProceso realizado satisfactoriamente ...\n";
    }
}

template<class T>
void SingleLinkedList<T>::Eliminar_primero()
{
    if(Head==0)
    {
        cout<<"\nEsta lista se encuentra vacia ...\n";
    }
    else
    {
        Node<T> *Temp;
        Temp=Head;
        Head=Head->Obtiene_siguiente_nodo();
        Temp=0;
        Size--;
    }
}

template<class T>
void SingleLinkedList<T>::Eliminar_ultimo()
{
    if(Head==0)
    {
        cout<<"\nEsta lista se encuentra vacia ...\n";
    }
    else
    {
        Node<T> *Cur=Head;
        Node<T> *Pre=0;
        Pre=Head;
        while(Cur->Obtiene_siguiente_nodo()!=0)
        {
            Pre=Cur;
            Cur=Cur->Obtiene_siguiente_nodo();
        }
        Tail=Pre;
        Pre->Fija_siguien(0);
        delete Cur;
        Cur=0;
        Size--;
    }
}

template<class T>
void SingleLinkedList<T>::Eliminar_posicion(int Index)
{
    if(Head==0)
    {
        cout<<"\nEsta lista se encuentra vacia ...\n";
    }
    else if(Index==1 && Head!=0)
    {
        Eliminar_primero();
    }
    else if(Index==Size)
    {
        Eliminar_ultimo();
    }
    else if(Index>1 && Index<Size)
    {
        Node<T>* Cur=Head;
        Node<T>* Pre=0;
        for(int i=1;i<Index;i++)
        {
            Pre=Cur;
            Cur=Cur->Obtiene_siguiente_nodo();
        }
        Pre->Fija_siguien(Cur->Obtiene_siguiente_nodo());
        Cur=0;
        Size--;
    }
    else
    {
        cout<<"\nProceso realizado satisfactoriamente ...\n";
    }

}

template<class T>
void SingleLinkedList<T>::Vuelta_lista()
{
    Node<T>* Cur=Head;
    Node<T>* Pre=0;
    Node<T>* siguiente=0;
    while(Cur!=0)
    {
        siguiente=Cur->Obtiene_siguiente_nodo();
        Cur->Fija_siguien(Pre);
        Pre=Cur;
        Cur=siguiente;
    }
    Head=Pre;
}

template<class T>
void SingleLinkedList<T>::Vuelta_datos()
{
    T Array[Size];
    T Holder;
    Node<T> *Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Array[i]=Temp->Obt_Datos();
        Temp=Temp->Obtiene_siguiente_nodo();
    }
    for(int i=0,j=Size-1;i<Size/2;i++,j--)
    {
        Holder=Array[i];
        Array[i]=Array[j];
        Array[j]=Holder;
    }
    Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Temp->Pone_Datos(Array[i]);
        Temp=Temp->Obtiene_siguiente_nodo();
    }
}

template<class T>
void SingleLinkedList<T>::Vuelta_lista(Node<T> *N)
{
    if(N->Obtiene_siguiente_nodo()==0)
    {
        Head=N;
        return;
    }
    Vuelta_lista(N->Obtiene_siguiente_nodo());
    Node<T> *Temp=N->Obtiene_siguiente_nodo();
    Temp->Fija_siguien(N);
    N->Fija_siguien(0);
}


template<class T>
void SingleLinkedList<T>::Elimina_todos_Nodos()
{
    if(Head!=0)
    {
        cout<<"\n\nEliminando nodos...\n";
        Node<T> *Current=Head;
        Node<T> *Pre;
        while(Current!=0)
        {
            Pre=Current;
            cout<<"\nEliminados "<<Pre->Obt_Datos();
            Current=Current->Obtiene_siguiente_nodo();
            Pre=0;
            delete Pre;
        }
    }
    Size=0;
    cout<<"\n\nFueron eliminados exitosamente...\n";
}
template<class T>
void SingleLinkedList<T>::Ver_lista()
{
    Node<T> *Temp;
    if(Head==NULL)
    {
        cout<<"\nLa lista esta vacia..."<<endl;
    }
    else
    {
        Temp=Head;
        cout<<"\n\n     Lista \n\n";
        int i=1;
        while(Temp!=NULL)
        {
            cout<<"**** Nodo "<<i<<" ****\n";
            cout<<"   "<<Temp<<"\n";
            cout<<"      "<<Temp->Obt_Datos()<<"\n";
            if(Temp->Obtiene_siguiente_nodo()==0)
            {
                cout<<"      0\n";
                cout<<"**************\n";
            }
            else
            {
                cout<<"   "<<Temp->Obtiene_siguiente_nodo()<<"\n";
                cout<<"**************\n";
            }
            i++;
            Temp=Temp->Obtiene_siguiente_nodo();
            cout<<endl;
        }
    }
}


template<class T>
void SingleLinkedList<T>::GetNth(int Index)
{
	Node<T> *Temp=Head;
	if(Temp==NULL)
	{
		cout<<"\nEsta lista se encuentra vacia ..."<<endl;
	}
	else if(Index>0 && Index<=Size)
	{
		for(int i=1;i<Index;i++)
		{
			Temp=Temp->Obtiene_siguiente_nodo();
		}
		cout<<"\n\nDato indexado "<<Index<<" : "<<Temp->Obt_Datos();
	}
	else
    {
        cout<<"\n\nFuera de rango, favor revise y digite uno que se encuentre dentro ...\n\n";
    }

}

template<class T>
void SingleLinkedList<T>::Encontrar_dat(T Data)
{
    Node<T> *Temp=Head;
    int i=1;
    int flag=0;
    while(Temp!=0)
    {
        if(Data==Temp->Obt_Datos())
        {
            cout<<"\n\nDato esta  dentro de los valores que hay por el momento "<<i<<endl<<endl;
            flag=1;
        }
        i++;
        Temp=Temp->Obtiene_siguiente_nodo();
    }
    if(flag==0)
    {
        cout<<"\n\nDato no esta  dentro de los valores que hay por el momento ...\n\n";
    }
}


template<class T>
void SingleLinkedList<T>::Ordenar()
{
    T Array[Size];
    Node<T>* Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Array[i]=Temp->Obt_Datos();
        Temp=Temp->Obtiene_siguiente_nodo();
    }
    sort(Array,Array+Size);
    Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Temp->Pone_Datos(Array[i]);
        Temp=Temp->Obtiene_siguiente_nodo();
    }

}

template<class T>
void SingleLinkedList<T>::Eliminar_Dat(T Data)
{
    Node<T> *Cur=Head;
    Node<T> *Pre=0;
    int flag=0;
    int Index=1;
    while(Cur!=0)
    {
        if(Cur->Obt_Datos()==Data)
        {
            flag=1;
            break;
        }
        Cur=Cur->Obtiene_siguiente_nodo();
        Index++;
    }
    if(flag==0)
    {
        cout<<"\n\nDato no esta  dentro de los valores que hay por el momento ...\n\n";
    }
    else
    {
        Eliminar_posicion(Index);
        cout<<"\n\nProceso ralizado exitosamente ...\n\n";
    }
}
