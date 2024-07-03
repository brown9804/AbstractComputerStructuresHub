
#ifndef POLINOMIO_DIVI_MULTI_H
#define POLINOMIO_DIVI_MULTI_H


#include <iostream>


class polinomio_divi_multi
{
    //Sobrecarga de operador
    friend std::istream& operator>>(std::istream &inStream, polinomio_divi_multi &sourceCoeff);

    // Imprime el polinomio
    friend std::ostream& operator<<(std::ostream &outStream, const polinomio_divi_multi &Sourcepolinomio_divi_multi);

public:
    // contructores y destructores
    polinomio_divi_multi();
    polinomio_divi_multi(int coeff);
    polinomio_divi_multi(int coeff, int power);
    polinomio_divi_multi(const polinomio_divi_multi &source);
    ~polinomio_divi_multi();

    // Obtiene y tiene
    int getCoeff(int power) const;
    void setCoeff(int coeff, int power);

    polinomio_divi_multi operator*(const polinomio_divi_multi &rhs) const;
    polinomio_divi_multi operator/(const polinomio_divi_multi &rhs) const;
    polinomio_divi_multi& operator=(const polinomio_divi_multi &rhs);

private:
    int* coeffPtr;  // Puntero al arreglo
    int size;   //Tamaño del arreglo
};


#endif
