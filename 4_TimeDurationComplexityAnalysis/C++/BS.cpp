#include<iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

void bs(string filePath, int objetivo)
{

    ifstream archivo;
    archivo.open(filePath, ios::in);
    string texto;
    int linea =0;
    int max;
    while(!archivo.eof()){
        getline(archivo, texto);
        istringstream isstream(texto);
            while(!isstream.eof()){ //divide cada linea en palabras
                int tempStr; 
                isstream >> tempStr;
                max=tempStr; 
            }
        break;
    }
    archivo.close();
    ifstream archivo2;
    archivo2.open(filePath, ios::in); 
    string texto2;
    int array[max]={};
    linea =0; 
    while(!archivo2.eof()){
        getline(archivo2, texto2);
        istringstream isstream(texto2);
        if (linea==1) {
            int iter=0;
            while(!isstream.eof()){ //divide cada linea en palabras
                if (iter<max){
                    int tempStr; 
                    isstream >> tempStr;
                    array[iter]=tempStr;
                    iter=iter+1;
                }else{
                    break;
                }
            }
        }
        linea=1;
    }
    archivo2.close();

    //Codigo selection sort para ordenar el arreglo
    int min;
    int aux;
    for (int i=0; i<max-1; i++ ){
        min=i;
        for(int j=i+1; j<max; j++){
            if (array[min]>array[j]){
                min=j;
            }
        }
        aux=array[i];
        array[i]=array[min];
        array[min]=aux;
        
    }


    cout<<"Cant datos: "<<max<<endl;
    cout<<"objetivo: "<<objetivo<<endl;
    min=0;
    int result=0;
    bool cond =false;
    
    //Algoritmo binary search
    
    unsigned t0, t1;
    t0=clock();

    while(min<=max)
    {
        int promedio = (min + max)/2;

        if (array[promedio]==objetivo){
            result=promedio;
            cond=true;
            break;
            }
        if (array[promedio]<objetivo){
            min=promedio+1;
            promedio=(min+max)/2;
            }
        if (array[promedio]>objetivo){
            max=promedio-1;
            promedio=(min+max)/2;
            }
        }
    if (cond==false){
        cout<<"Numero no esta en el arreglo"<<endl;
    }
    else{
        cout<<"Numero esta en la posición: "<< result<< endl;

    }
    t1 = clock();
 
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecución : " << time << " s"<< endl;

    return;

    }



int main(int argc , char* argv[]){



int objetivo = 100000;
bs(argv[1], objetivo);





return 0;

}