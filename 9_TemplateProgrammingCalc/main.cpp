#include <iostream>

#include "polinomio_divi_multi.h"
#include "calculadora.h"
#include "fraccion.h"
#include "polinomio.h"


using namespace std;


int main (){


    cout <<"Probando calculdadora con doubles: " <<endl;

    Calculadora<double> cal1;
    double a=2.455;
    double b=6.1;

    double f = cal1.add(a,b);
    double &x = f;
    cout  << "a: "<< a  << " " << "b: "<< b << endl;
    cout<<"a+b" <<endl;
    cal1.print(x);

    double f2 = cal1.sub(a,b);
    double &x2 = f2;
    cout  << "a: "<< a  << " " << "b: "<< b << endl;
    cout<<"a-b" <<endl;
    cal1.print(x2);
    
    double f3 = cal1.mul(a,b);
    double &x3 = f3;
    cout  << "a: "<< a  << " " << "b: "<< b << endl;
    cout<<"a*b" <<endl;
    cal1.print(x3);

    double f4 = cal1.div(a,b);
    double &x4 = f4;
    cout  << "a: "<< a  << " " << "b: "<< b << endl;
    cout<<"a/b" <<endl;
    cal1.print(x4);

    cout <<"Haciendo operaciones con fracciones: " <<endl;
    Fraccion fracc1(1,2);
    Fraccion fracc2(2,3);
    cout << "Fraccion A " <<~fracc1 <<endl;
    cout << "Fraccion B " <<~fracc2 <<endl;
    fracc1+fracc2;
    cout << "C = A + B --" << ~fracc1<< endl;
    fracc1-fracc2;
    cout << "D = C - B --" << ~fracc1<< endl; 
    fracc1*fracc2;
    cout << "E = D * B --" << ~fracc1<< endl; 
    fracc1/fracc2;
    cout << "F = E / B --" << ~fracc1<< endl; 



    cout<<"Suma y resta de polinomios: " <<endl;

    int* arr1 = new int[5];
    for( int i =0; i<5 ; i++){
        arr1[i]=i;
    }

    int* arr2 = new int[5];
    for( int i =0; i<5 ; i++){
        arr2[i]=i+2;
    }

    Polinomio pol1(5, arr1);
    Polinomio pol2(5,arr2);
    cout << "Polinomio 1: "<<~pol1;
    cout << "Polinomio 2: " <<~pol2;
    pol1+pol2;
    cout << "Polinomio 1 + Polinomio 2: " <<~pol1<< endl;
    cout << "Polinomio 1: "<<~pol1;
    cout << "Polinomio 2: " <<~pol2;

    pol1-pol2;
    cout << "Polinomio 1 - Polinomio 2: " <<~pol1<< endl;

 



    polinomio_divi_multi A(5, 7), B(3, 4), C(2), D(A), X, Y;
    polinomio_divi_multi A2, B2, Z1, Z2;
    cout << "     " << endl;
    cout << "Se define el polinomio A = 6x^4 -8x^3 +17x -9 " << endl;
    cout << "     " << endl;
    A.setCoeff(6, 4);
    A.setCoeff(17, 1);
    A.setCoeff(-8, 3);
    A.setCoeff(-9, 0);

    cout << "Se define B = 3x^6 +10x^3" << endl;
    cout << "     " << endl;
    B.setCoeff(3, 6);
    B.setCoeff(10, 3);


    cout << "Calculando  D = A * B " << endl;
    D = A * B ;
    cout << "     " << endl;
    cout << "Resultado D =" << D << endl;
    cout << "     " << endl;



    cout << "Se define B2 = -x^4 -3x^3" << endl;
    cout << "     " << endl;
    B2.setCoeff(-1, 4);
    B2.setCoeff(-3, 3);


    cout << "Se define el polinomio A2 = x^3 +3x^2" << endl;
    cout << "     " << endl;
    A2.setCoeff(1, 3);
    A2.setCoeff(3, 2);
    A2.setCoeff(0, 3);
    A2.setCoeff(0, 0);

    cout << "Calculando  X = B2 / A2 " << endl;
    X = A / B;

    cout << "     " << endl;
    cout << "Resultado  verificado en una calculadora online da: X = -1x y nuestro resultado calculado es: " << X << endl;
    cout << "     " << endl;




    return 0;
}
