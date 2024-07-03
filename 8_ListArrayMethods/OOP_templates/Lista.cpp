#include "Lista.h"
#include <string>
#include <sstream>
#include <iostream>

Lista::Lista(bool esDoble, bool esCircular)
{
    //ctor
    largo = 0;
    head = NULL;
    tail = NULL;
    actual = NULL;
    this->esDoble = esDoble;
    this->esCircular = esCircular;
}

Lista::~Lista()
{
    //dtor
}

int Lista::getSize(){
    return largo;
}

Nodo* Lista::getHead(){
    return head;
}

Nodo* Lista::getTail(){
    return tail;
}

Nodo* Lista::getActual(){
    return actual;
}

void Lista::append(int elem){
    Nodo* nuevo = new Nodo(elem);   // incorporar el elemento en un nodo
    if (head ==NULL){               // lista esta vacia
        head = nuevo;
    }
    else{
        if (head != NULL){          // al menos ya hay un elemento
            tail->sig = nuevo;      // se agrega al final de la lista
        }
    }
    actual = nuevo;
    tail = nuevo;
    largo++;
}

string Lista::numberToString(int n){
    stringstream convert;       // stringstream used for the conversion
    convert << n;               //add the value of Number to the characters in the stream
    return convert.str();       //set Result to the content of the stream
}

string Lista::show(){
    Nodo* tmp = head;
    string res = "";
    while (tmp!=NULL){
        res = res + numberToString(tmp->element) + " ";
        tmp = tmp->sig;
    }
    return "Contenido de la Lista\n" + res + "\n";
}

/*find: retorna la posicion donde se localiza la primera aparicion del elem*/
int Lista::find(int elem){
    if (head == NULL)
        return -1;  // lista vacia
    else{
        Nodo* tmp= head;
        int c=1;
        while(tmp != NULL && tmp->element != elem){
            tmp=tmp->sig;
            c++;
        }
        if (tmp!=NULL)
            return c;
        else
            return -1;   // no lo encontr� en la lista
    }

}

void Lista::setActual (int posicion){
 if (posicion >= 1 && posicion <= largo){
  actual = head;
  for(int c = 1; c < posicion;c++){
    actual=actual->sig;
  }

 }
 else
    actual = NULL;
}

void Lista::insert (int posicion, int elemento){
    if (posicion == 1){
        Nodo* nuevo = new Nodo(elemento);
        nuevo->sig = head;
        head = nuevo;
        actual = nuevo;
        largo++;
    }
    else
    if (posicion == largo+1){
            append (elemento);


    }
    else{
        setActual(posicion-1);
        Nodo* nuevo = new Nodo(elemento);
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
        actual = nuevo;
        largo++;
    }

}

void Lista::remove(){
    if (head!= NULL){
        if (largo == 1){
            delete actual;
            head = NULL;
            actual = NULL;
            tail = NULL;
            largo=0;
        }
        else{
            if (actual == head){
                head = head->sig;
                delete actual;
                actual = head;
                largo--;
            }
            else{
                // toma al actual como el que va a borrar
                Nodo* borrar = actual;
                // debe ubicar al actual uno antes del que va a borrar
                actual = head;
                while (actual->sig != borrar){
                    actual= actual->sig;
                }
                // desenlaza el nodo a borrar, asegurando que la lista queda continua
                actual->sig = borrar->sig;
                // actualiza la cola de la lista si va a borrar el ultimo
                if (borrar == tail)
                    tail = actual;

                // elimina el nodo a borrar
                delete borrar;
                largo--;
            }
        }
    }
}

int Lista::mayor(){
    int c = 0;
    if (head == NULL){
        c = 0;
    }
    else{
        actual = head;
        while (actual != NULL){
            if (actual->element > c)
                c = actual->element;
            actual = actual->sig;
        }
    }
    return c;
}

int Lista::menor(){
    int c = 999999999;
    if (head == NULL){
        c = 0;
    }
    else{
        actual = head;
        while (actual != NULL){
            if (actual->element < c)
                c = actual->element;
            actual = actual->sig;
        }
    }
    return c;
}

bool Lista::isOrderedAsc(){
    bool p = false;
    int c = 0;
    if (head != NULL){
        actual = head;
        while (actual->sig != NULL){
                c = actual->sig->element;
                if (actual->element >= c){
                 p = false;
                 break;
                }
                else
                    p = true;
                actual = actual->sig;
        }
    }
    return p;
}

int Lista::apariciones(int ele){
    int rep = 0;
    if (head != NULL){
        actual = head;
        while (actual != NULL){
            if (actual->element == ele)
                rep++;
            actual = actual->sig;
        }
    }
return rep;
}

int Lista::removeAll(int ele){
    int rep = 0;
    if (head != NULL){
        actual = head;
        while (actual != NULL){
            if (actual->element == ele){
                remove();
                rep++;
            }
            actual = actual->sig;
        }
    }
return rep;

}

void Lista::reverse(){
int t = largo;
Nodo * pa = tail;
    if (head != NULL){
        if (largo == 1){
        }
        else{
                actual = head;
                tail->sig = actual;
                tail = actual;
                head = actual->sig;
                actual->sig = NULL;
            for (int i = 0;i < t-2; t--){
                actual = head;
                head = actual->sig;
                actual->sig = pa->sig;
                pa->sig = actual;
            }
        }
    }

}

void Lista::joinRepeteadElem(){
    if (head != NULL){
        int y=1,j, sa = 0;
            int num[largo];
            int ga [largo];
            num[0]=head->element;
        actual = head;
            while (actual != NULL){
                for (int t=0;t<y;t++){
                    if(num[t]== actual->element){
                        break;
                    }
                    if (t == y-1){
                    num[y++] = actual->element;

                    }
                }
                actual= actual->sig;
            }

                for (int h=0;h<y;h++){
                    j=apariciones(num[h]);
                    ga[h]=j;
                }
        actual=head;
        while (actual != NULL){
            remove();
        }
        for (int k=0;k<y ;k++){
            for (int f = 0; f<ga[sa] ;f++){
                append(num[k]);
            }
        sa++;
        }
    }
}



void Lista::removeRepeteadElem(){
    if (head != NULL){
        int y=1;
            int num[largo];
            num[0]=head->element;
        actual = head;
            while (actual != NULL){
                for (int t=0;t<y;t++){
                    if(num[t]== actual->element){
                        break;
                    }
                    if (t == y-1){
                    num[y++] = actual->element;

                    }
                }
                actual= actual->sig;
            }
        actual=head;
        while (actual != NULL){
            remove();
        }
        for (int k=0;k<y ;k++){
            append(num[k]);
        }
}
}
