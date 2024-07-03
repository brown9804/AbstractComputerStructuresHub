#include<iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

void ss(string filePath)
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
    int array[max] ={};
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

    //Comienza el algoritmo de selection sort
    unsigned t0, t1;
 
    t0=clock();
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
    cout<<"Cant. datos: "<<max<<endl;
    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecución : " << time << " s"<< endl;

    return;
    }



int main(int argc , char* argv[]){

ss(argv[1]);


return 0;

}