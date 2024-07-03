#include "header.h"
using namespace std;


int main(){
    Arbol_Rojo_Negro demo;
int info, input;
menu();
        cin >> info;
while(info != 6){
switch (info){
  case 1: cout << "\nVa a ser insertado ...  ";
                        cin >> input; demo.Agregar_nodo_arbol(input);
break;
case 2: cout << "\nVa a ser buscado  ➼➼➼➼";
                        cin >> input;
if(demo.TreeSearch(input)) { cout << "Se encontró el valor ➼➼➼➼\n"; }
else { cout << "No se encontró el valor ➼➼➼➼\n"; }
break;
case 3: cout << "Pre-Order  ➼➼➼➼ ";
                        demo.Pre_Ordenamiento_forma_lateral(demo.Obtener_Base());
                        cout << endl;
break;
case 4: cout << "Post-Order  ➼➼➼➼ ";
                        demo.Post_Ordenamiento_forma_lateral(demo.Obtener_Base());
                        cout << endl;
break;
case 5: cout << "\n ➼➼➼➼Eliminar el valor ➼➼➼➼ ";
                        cin >> input;
                        demo.eliminar(input);
break;
default: cout << "Favor digite una opción dentro del menú \n";
            }
        cout << "\n ➼➼➼➼Escoja una opción  ➼➼➼➼  ";
        cin >> info;
        }
    cout << "\nSalir  ➼➼➼➼ \n ";
return 0;
 }
