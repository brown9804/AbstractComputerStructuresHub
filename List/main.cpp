#include "Node.cpp"
#include "LinkedList.cpp"
#include <vector>
#define DataType int
#include<iostream>
#include <stdint.h>


using namespace std;


int Menu()
{
	cout<<"\n************** Menu **************\n\n";
	int Decision;
	cout<<"\n\n1)  Introduzca nodo al principio";
	cout<<"\n\n2)  Introduzca nodo al final";
	cout<<"\n\n3)  Introduzca nodo en una posicion definida a su escogencia";
	cout<<"\n\n4)  Elimine nodo al principio";
	cout<<"\n\n5)  Elimine nodo al final";
	cout<<"\n\n6)  Elimine nodo que se encuentra en una posicion definida";
	cout<<"\n\n7)  Darle vuelta a los nodos em lista";
	cout<<"\n\n8)  Darle vuelta al Data";
	cout<<"\n\n9)  Darle vuelta a la lista recursivamente";
  cout<<"\n\n10) Ordena la lista";
  cout<<"\n\n11) Ver lista";
  cout<<"\n\n12) Tamaño de la lista";
	cout<<"\n\n0)  Salir";
	cout<<"\n\n\nDigite una opcion : ";
	cin>>Decision;
	return Decision;
}


int main(){
	SingleLinkedList<int> SLLOne;
	cout<<"\n--- Lista simple enlazada ---\n\n";
	cout<<endl<<endl;
	while(1)
	{
		switch(Menu())
		{
			case 1:
			{
                DataType Data;
                cout<<"\n\nDigite una opcion: ";
                cin>>Data;
                SLLOne.Ingre_inicio(Data);
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 2:
			{
                DataType Data;
                cout<<"\n\nDigite un valor: ";
                cin>>Data;
                SLLOne.Ingre_final(Data);
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 3:
			{
                int Pos=0;
                DataType Data;
                cout<<"\n\nDigite un valor : ";
                cin>>Data;
                cout<<"\n\nDigite un posicion: ";
                cin>>Pos;
                SLLOne.Ingreso_en_posicion(Data,Pos);
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 4:
			{
                SLLOne.Eliminar_primero();
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 5:
			{
                SLLOne.Eliminar_ultimo();
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 6:
			{
                int Pos=0;
                cout<<"\n\nDigite una posicion:   ";
                cin>>Pos;
                SLLOne.Eliminar_posicion(Pos);
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 7:
			{
                SLLOne.Vuelta_lista();
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}
			case 8:
			{
                SLLOne.Vuelta_datos();
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}

			case 9:
			{
                SLLOne.Vuelta_lista(SLLOne.GetHead());
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}

			case 10:
			{
                SLLOne.Ordenar();
                cout<<"\n\nProceso realizado exitosamente...\n\n";
				break;
			}

			case 11:
			{
                SLLOne.Ver_lista();
				break;
			}
			case 12:
			{
                cout<<"\n\nTamaño de la lista : "<<SLLOne.Obt_tamano()<<endl<<endl;
				break;
			}
			case 0:
			{
				cout<<endl<<endl<<"Cerrando el programa\n\n";
				exit(0);
				break;
			}
			default:
			{
				cout<<"\nOpcion invalida\n";
			}
		}
		cout<<endl;
	}
}
