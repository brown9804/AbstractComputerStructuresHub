#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Lista.h"
#include <ncurses.h>
#include <ctime>
#include "funciones.h"

using namespace std;

double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms;
}

int main(){


    Lista* bubble = new Lista(true, false);
    Lista* insert = new Lista(true, false);
    Lista* selection =  new Lista(true, false);
    Lista* shell = new Lista(true, false);
    Lista* radix = new Lista(true, false);
    int la, y;
    cout<<"De cuantos elementos aleatorios desea entre 30, 120, 240, 301 o 406:"<<endl;
    cin>>la;
    cout<<endl<<endl;
    if (la == 30 || la == 120 || la == 240 || la == 301 || la == 406){
    srand(time(NULL));
    for (int i = 0; i < la;i++){
        //asi todos los metodos van a tener los mismos numeros y la variacion de la reapidez no se vera afectada por los datos
        y = 1+rand()%(10001-1);
        bubble->append(y);
        insert->append(y);
        selection->append(y);
        shell->append(y);
        radix->append(y);
    }

    clock_t inicio=clock();

    bubble->bubbleSort();
    cout<<"Después de bubbleSort:"<<endl;
    cout<<bubble->show()<<endl;
    cout<<"La cantidad de cambios efectivos son: "<<bubble->efi()<<endl<<endl;
    cout<<"La cantidad de procesos: "<<bubble->pro()<<endl<<endl;
    //tiempo del proceso
    clock_t fin=clock();
    cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

    inicio=clock();

    insert->insertSort();
    cout << "Después de insertSort: "<<endl;
    cout<<insert->show()<<endl;
    cout<<"La cantidad de cambios efectivos son: "<<insert->efi()<<endl<<endl;
    cout<<"La cantidad de procesos: "<<insert->pro()<<endl<<endl;
    //tiempo del proceso
    fin=clock();
    cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;


    inicio=clock();
    shell->shellSort();
    cout << "Después de shellSort: "<<endl;
    cout<<shell->show()<<endl;
    cout<<"La cantidad de cambios efectivos son: "<<shell->efi()<<endl<<endl;
    cout<<"La cantidad de procesos: "<<shell->pro()<<endl<<endl;
    //tiempo del proceso
    fin=clock();
    cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

    inicio=clock();

    radix->radixSort();
    cout << "Después de radixSort: " <<endl;
    cout<<radix->show()<<endl;
    cout<<"La cantidad de cambios efectivos son: "<<radix->efi()<<endl<<endl;
    cout<<"La cantidad de procesos: "<<radix->pro()<<endl<<endl;
    //tiempo del proceso
    fin=clock();
    cout << "Milisegundos realizando el proceso " << diffclock(fin,inicio) <<endl<<endl;

    //fin=clock();
    //tiempo= fin-inicio;
   // cout << tiempo;





   inicio=clock();
   selection->selectionSort();
   cout << "Después de selectionSort a gran escala: "<<endl;
   cout<<selection->show()<<endl;
   cout<<"La cantidad de cambios efectivos son: "<<selection->efi()<<endl<<endl;
   cout<<"La cantidad de procesos: "<<selection->pro()<<endl<<endl;
   //tiempo del proceso
   fin=clock();
   cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

   int arreglo[] = {45, 16, 1500000, 426, 124598, 1619, 23000, 76543, 5423970, 4527290, 35456};
   int n = sizeof(arreglo)/sizeof(arreglo[0]);
   std::cout << "Antes de aplicar cualquier método de ordenamiento y busqueda:\n" << std::endl;
   imprime_arreglo(arreglo, n);
   std::cout << "\n" << std::endl;

   inicio=clock();
   mergeSort(arreglo, 0, n - 1);
   std::cout << "Merge Sort da como resultado:\n" << std::endl;
   imprime_arreglo(arreglo, n);
    //tiempo del proceso
   fin=clock();
   cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

   int arreglo1[] = {45, 16, 1500000, 426, 124598, 1619, 23000, 76543, 5423970, 4527290, 35456};
   inicio=clock();
   quickSort(arreglo1, 0, n);
   std::cout << "Quick Sort da como resultado:\n" << std::endl;
   imprime_arreglo(arreglo1, n);
      //tiempo del proceso
   fin=clock();
      cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

   int arreglo2[] = {45, 16, 1500000, 426, 124598, 1619, 23000, 76543, 5423970, 4527290, 35456};
   inicio=clock();
   selectionSort(arreglo2, n);
   std::cout << "Selection Sort da como resultado:\n" << std::endl;
   imprime_arreglo(arreglo2, n);
         //tiempo del proceso
   fin=clock();
   cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;

   std::cout << "Antes de aplicar busqueda binaria, tenemos el arreglo:\n" << std::endl;
   int arreglo_indexado[] =  {1, 5, 12, 48, 49, 49, 49, 50, 50, 65, 89};
   imprime_arreglo(arreglo_indexado, n);

   inicio=clock();
   std::cout << "Valores ordenados indexados encontrados:   " << binarySearch(arreglo_indexado, n, 65) << std::endl;
   fin=clock();
   cout << "Milisegundos realizando el proceso    " <<diffclock(fin,inicio) <<endl<<endl;

   inicio=clock();
   std::cout << "Valor encontrado de primero en el indexado:   " << binarySearchFirst(arreglo_indexado, n, 49) << std::endl;
   fin=clock();
   cout << "Milisegundos realizando el proceso     " <<diffclock(fin,inicio) <<endl<<endl;

   inicio=clock();
   std::cout << "Valor ultimo en el indexado:    " << binarySearchLast(arreglo_indexado, n, 49) << std::endl;
   fin=clock();
   cout << "Milisegundos realizando el proceso    " <<diffclock(fin,inicio) <<endl<<endl;



   int arreglo_lineal[] = { 4, 3, 32, 17, 59, 18, 2, 9, 1, 5, 20, 27, 98, 92, 76, 39, 12, 65, 21, 7};
   int digitado = 0;
   cout << "Tenemos la lista: \n";
   imprime_arreglo(arreglo_lineal, n);
   cout << endl;
   inicio=clock();
   cout << "Digite algun entero que se encuentre en la lista anterior, para buscarlo y saber su posicion: ";
   cin >> digitado;

   for (int i = 0; i < 20; i++) {
   	if (arreglo_lineal[i] == digitado) {
   		cout << "Se ha encontrado [" << i << "]" << endl;
       fin=clock();
       cout << "Milisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;
   		break;

   	}
   }

    int x, i, biter, busque_arr[20], a[20]={1, 9, 18, 24, 27, 35, 38, 41, 49, 53, 55, 66, 67, 72, 75, 77, 81, 89, 90, 97};
   	char decision;
    cout << "Tenemos la lista: \n";
    imprime_arreglo(a, n);

   	busque_arr[0] = 0;
   	busque_arr[1] = 1;
   	i = 1;

    inicio=clock();
   	while(busque_arr[i] < 20)
   	{
   		i++;
   		busque_arr[i] = busque_arr[i-1]+busque_arr[i-2];
   	}

   	up:
   	cout<<"\nDigite el número que desea buscar con Fibonacci: ";
   	cin>>x;

   	FibonacciSearch(a, 0, 19, busque_arr, i, x);
    fin=clock();
    cout << "\nMilisegundos realizando el proceso " <<diffclock(fin,inicio) <<endl<<endl;
   	cout<<"\nDesea buscar otro(y/n)?";
   	cin>>decision;
   	if(decision == 'y' || decision == 'Y')
   		goto up;





    }
    else
        cout<<"El valor no esta en los aceptados"<<endl;


    return 0;
}
