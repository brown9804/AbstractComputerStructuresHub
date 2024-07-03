#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
    int la;
  //  Creando una  lista simple lineal
    Lista * simpleL = new Lista(false, false);

    simpleL->append(2);
    simpleL->append(3);
    simpleL->append(4);
    simpleL->append(5);
    simpleL->append(2);
    simpleL->append(5);
    simpleL->append(4);
    simpleL->append(3);
    simpleL->append(5);
    simpleL->append(2);
    simpleL->append(2);
    simpleL->append(4);
    simpleL->append(3);


   if (simpleL->getHead() != NULL)
    cout<<"El mayor numero de la lista es: "<<simpleL->mayor()<<endl;
    else
        cout<<"Lista vacia"<<endl;

    if (simpleL->getHead() != NULL)
    cout<<"El menor numero de la lista es: "<<simpleL->menor()<<endl;
    else
        cout<<"Lista vacia"<<endl;

    if (simpleL->getHead() != NULL){
            if (simpleL->isOrderedAsc() == 1)
    cout<<"La lista si esta ordenada de orden ascedente"<<endl;
            else{
                    if (simpleL->getHead() == simpleL->getTail())
                        cout<<"La lista solo contiene 1 elemento"<<endl;
                    else
                        cout<<"La lista no esta ordenada de manera ascendente"<<endl;
            }
    }
    else
        cout<<"Lista vacia"<<endl;

     if (simpleL->getHead() != NULL){
    cout<<"Cuantas veces aparece el numero ";
    cin>>la;
    cout<<"El numero de apariciones del valor "<<la<<" son "<<simpleL->apariciones(la)<<endl;
     }
    else
        cout<<"Lista vacia"<<endl;

    if (simpleL->getHead() != NULL){
        cout<<"Numero que desea eliminar del todo en la lista ";
        cin>>la;
        cout<<"Numero de veces que se borro el numero son "<<simpleL->removeAll(la)<<endl;
    }
    else
        cout<<"Lista vacia"<<endl;
               cout<<simpleL->show()<< endl;
        cout<<simpleL->show()<< endl;
        cout<<"Head :"<<simpleL->getHead()->element<<endl;
        cout<<"Tail :"<<simpleL->getTail()->element<<endl;
      simpleL->reverse();
        cout<<simpleL->show()<< endl;
        cout<<"Head :"<<simpleL->getHead()->element<<endl;
        cout<<"Tail :"<<simpleL->getTail()->element<<endl;

        cout<<simpleL->show()<< endl;
        simpleL->joinRepeteadElem();
        cout<<simpleL->show()<< endl;

        simpleL->removeRepeteadElem();
        cout<<simpleL->show()<< endl;





    cout << simpleL->show() << endl;

    int numero = 30;
    cout << "El "<< numero << " esta en posicion " << simpleL->find(numero) << endl;

    simpleL->setActual(4);
    if (simpleL->getActual() != NULL)
    cout<<simpleL->getActual()->element<<endl;
    else
       cout<<"Posicion incorrecta"<<endl;

    simpleL->insert(5,22);
    simpleL->insert(3,15);
    simpleL->insert(2,44);
    simpleL->insert(1,88);

    cout<<simpleL->show()<< endl;

//coloca el actual al inicio de la lista
    simpleL->setActual(1);
    simpleL->remove();
    cout << "Luego de borrar el inicio, " << simpleL->show() << endl;

  //  coloca el actual al final de la lista
    simpleL->setActual(simpleL->getSize());
    simpleL->remove();
    cout << "Luego de borrar el ultimo, " << simpleL->show() << endl;

    //coloca al segundo elemento como actual
    simpleL->setActual(2);   // haciendo del 40 el actual
    if (simpleL->getActual() != NULL){
            cout << simpleL->getActual()->element << endl;
           simpleL->remove();
           cout << "Luego de borrar el segundo de la lista, " << simpleL->show() << endl;
        }
    else
       cout << "Posicion incorrecta" << endl;

        cout<<simpleL->getSize()<<endl;
    return 0;
}
