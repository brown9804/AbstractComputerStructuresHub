#include "node.h"



int main(){
    int opcion;
    int num;
    BinarySearchTree bst;
    node *temp;
    /* Menu loop */
    while(1){
        cout<<" \n   Binary   Search   Tree  "<<endl;
        cout<<"*******************************\n"<<endl;
        cout<<"Debe seleccionar una opción: "<<endl;
        cout<<"1. Digitar elemento "<<endl;
        cout<<"2. Eliminar elemento "<<endl;
        cout<<"3. Preorder "<<endl;
        cout<<"4. Inorder "<<endl;
        cout<<"5. Postorder "<<endl;
        cout<<"6. Mostrar el árbol"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"*******************************\n"<<endl;

        cin>>opcion;

        switch(opcion){
            case 1:
                temp = new node;
                cout<<"Digite el elemento a ingresar en el árbol\n ";
                cin>>temp->valor;
                bst.insert(base, temp);
                break;
            case 2:
                if(base == NULL){
                    cout<<"Se encuentra vacía por lo que no se puede eliminar algo\n"<<endl;
                    continue;
                }
                cout<<"Digite el valor que desea eliminar del árbol: \n";
                cin>>num;
                bst.remove(num);
                break;
            case 3:
                cout<<"Preorder \n "<<endl;
                bst.preorder(base);
                cout<<endl;
                break;
            case 4:
                cout<<"Inorder  \n"<<endl;
                bst.inorder(base);
                cout<<endl;
                break;
            case 5:
                cout<<"Postorder  \n "<<endl;
                bst.postorder(base);
                cout<<endl;
                break;
            case 6:
                cout<<"Mostrar el árbol que se posee hasta el momento \n "<<endl;
                bst.Mostrar_el_Arbol(base, 1);
                cout<<endl;
                break;
            case 7:
                exit(1);



            default:
                cout<<"\nFavor digite una opción que se encuentre dentro de las opciones \n"<<endl;
        }
    }
}
