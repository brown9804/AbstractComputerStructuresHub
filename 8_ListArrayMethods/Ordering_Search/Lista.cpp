#include "Lista.h"
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include<stdlib.h>

Lista::Lista(bool esDoble, bool esCircular)
{
    //ctor
    eficiencia = 0;
    procesos = 0;
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
                                    // al menos ya hay un elemento
            tail->sig = nuevo;      // se agrega al final de la lista
            if(esDoble)
                nuevo->ant = tail;
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
        if (esDoble){
            nuevo->sig->ant = nuevo;
            nuevo->ant = actual;
        }
        actual = nuevo;
        largo++;
    }

}

int Lista::getelement(int posicion){
    setActual(posicion);
    int ele = actual->element;
    return (ele);
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
                if(esDoble)
                    head->ant = NULL;
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
                if (esDoble && borrar != tail){
                    borrar->sig->ant = actual;
                }
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
    int c = -999999999;
    if (head == NULL){
        c = head->element;
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
        c = head->element;
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
                if (actual->element > c){
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

bool Lista::insertAsc(int num){
    bool asc = false;
    int cont = 0;
    if (isOrderedAsc() == true){
        asc = true;
        actual = head;
        while (actual != NULL){
            cont++;
            if (num <= actual->element && cont == 1){
            break;
            }
            if (num >= actual->element && cont == largo){
            cont++;
            break;
            }
            if (num >= actual->element && num <= actual->sig->element){
            cont++;
            break;
            }
            actual = actual->sig;
        }
        insert (cont, num);
    }
    return asc;
}


void Lista::getDesc(){
 if (head != NULL && largo != 1){
    int h = mayor();
    int f = menor();
     int y =0;
    int desc[largo];
    actual=head;
    while (actual != NULL){
        desc[y++] = actual->element;
        remove();
    }
    append(f);
    append(h);
    for (int k =0;k<y;k++){
    insertAsc(desc[k]);
    }
   reverse();
   actual = head;
   remove();
   actual = tail;
   remove();
 }
}

//tipos de ordenamiento
//todas las listas
void Lista::bubbleSort(){
      eficiencia = 0;
      procesos = 0;
      int i, j;
      int numLength = largo;
      int f;
      for(i = 0; i < numLength; i++){
          actual = head;
          for (j=0; j < numLength-1; j++){
               if (actual->element > actual->sig->element){
                    f = actual->element;
                    actual->element = actual->sig->element;
                    actual->sig->element = f;
                    eficiencia++;
               }
               actual=actual->sig;
               procesos++;
          }
          procesos++;
     }
     return;
}
//lista circular y doble
void Lista::insertSort(){
        eficiencia = 0;
        procesos = 0;
        int length = largo;
	 	int j, temp;

	for (int i = 0; i < length; i++){
		j = i;
        setActual(i+1);
		while (j > 0 && actual->element < actual->ant->element){
			  temp = actual->element;
			  actual->element = actual->ant->element;
			  actual->ant->element = temp;
			  actual=actual->ant;
			  j--;
			  eficiencia++;
			  procesos++;
			  }
			  procesos++;
		}
}

//todas las listas
void Lista::selectionSort(){
    eficiencia = 0;
    procesos = 0;
int i,j,n,loc,temp,min;
    Nodo* ga;
    ga = head;
    n = largo;

    for(i=0;i<n-1;i++){
        min=ga->element;
        loc=i;
        for(j=i+1;j<n;j++){
            setActual(j+1);
            if(min>actual->element){
                min=actual->element;
                loc=j;
            }
            procesos++;
        }
        setActual(loc+1);
        temp = ga->element;
        ga->element=actual->element;
        actual->element=temp;
        ga = ga->sig;
        eficiencia++;
        procesos++;
    }

}
//todas las listas
void Lista::shellSort(){
    procesos = 0;
    eficiencia = 0;
    int n = largo;
int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j=i-gap; j>=0 && getelement(j+1) > getelement(j+gap+1); j-=gap) {
                setActual(j+1);
                temp = actual->element;
                actual->element = getelement(j+gap+1);
                setActual(j+gap+1);
                actual->element = temp;
                eficiencia++;
                procesos++;
            }
            procesos++;
        }
        procesos++;
    }
}
//todas las listas
void Lista::radixSort(){
    eficiencia = 0;
    procesos = 0;
    int n = largo;
    int output[n];
    int i, count[10] = {0};
    int m = mayor();
    for (int exp = 1; m/exp > 0; exp *= 10){
    for (i =0;i<10;i++)
        count[i]=0;
    for (i = 0; i < n; i++){
        count[ (getelement(i+1)/exp)%10 ]++;
        procesos++;
    }

    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
        procesos++;
    }


    for (i = n - 1; i >= 0; i--){
        output[count[ (getelement(i+1)/exp)%10 ] - 1] = getelement(i+1);
        count[ (getelement(i+1)/exp)%10 ]--;
        eficiencia++;
        procesos++;
    }
    actual = head;
    for (i = 0; i < n; i++){
        actual->element = output[i];
        actual = actual->sig;
        procesos++;
    }
    procesos++;
    }
}



int Lista::efi(){
return eficiencia;
}


int Lista::pro(){
return procesos;
}
