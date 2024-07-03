
#include "polinomio_divi_multi.h"

using namespace std;

istream &operator>>(istream &inStream, polinomio_divi_multi &sourceCoeff)
{
    int coeff;
    int power;

    while (true)
    {
        inStream >> coeff >> power;

        if ((coeff == -1) && (power == -1))
        {
            break;
        }

        sourceCoeff.setCoeff(coeff, power);
    }

    return inStream;
}

ostream &operator<<(ostream &outStream, const polinomio_divi_multi &sourcepolinomio_divi_multi)
{
    bool allZeroes = true;

        for (int i = sourcepolinomio_divi_multi.size - 1; i >= 0; i--)

        {
            if (sourcepolinomio_divi_multi.coeffPtr[i] != 0)
            {
                allZeroes = false;

                outStream << " ";

                if (sourcepolinomio_divi_multi.coeffPtr[i] > 0)
                {
                    outStream << "+";
                }

                outStream << sourcepolinomio_divi_multi.coeffPtr[i];

                if (i != 0 && i != 1)
                {
                    outStream << "x^" << i;
                }

                if (i == 1)
                {
                    outStream << "x";
                }
            }
        }

    if (allZeroes == false)
    {
        return outStream;
    }
    else
    {
        return outStream << "0";
    }
}


polinomio_divi_multi::polinomio_divi_multi()
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = 0;
}


polinomio_divi_multi::polinomio_divi_multi(int coeff)
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = coeff;
}


polinomio_divi_multi::polinomio_divi_multi(int coeff, int power)
{
    this->size = power + 1;
    coeffPtr = new int[this->size];

    for (int i = 0; i < this->size ; i++)
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[power] = coeff;
}
polinomio_divi_multi::polinomio_divi_multi(const polinomio_divi_multi &source)
{
    this->size = source.size;
    coeffPtr = new int[size];

    for (int i = 0; i < this->size; i++)
    {
        coeffPtr[i] = source.coeffPtr[i];
    }
}


polinomio_divi_multi::~polinomio_divi_multi()
{
    delete[] coeffPtr;
    coeffPtr = NULL;
}


int polinomio_divi_multi::getCoeff(int power) const
{
    if ((power >= 0) && (power < this->size))
    {
        return coeffPtr[power];
    }
    else
    {
        return 0;
    }
}

void polinomio_divi_multi::setCoeff(int coeff, int power)
{
    if (power >= 0)
    {
        if (power < this->size)
        {
            coeffPtr[power] = coeff;
        }
        else
        {
            int *tempArr = new int[power + 1];

            for (int i = 0; i < this->size; i++)
            {
                tempArr[i] = coeffPtr[i];
            }

            for (int j = this->size; j < power + 1; j++)
            {
                tempArr[j] = 0;
            }

            tempArr[power] = coeff;

            delete[] coeffPtr;
            coeffPtr = NULL;
            coeffPtr = tempArr;
            tempArr = NULL;
            this->size = power + 1;   // redisenando la entrega
        }
    }
}

polinomio_divi_multi polinomio_divi_multi::operator*(const polinomio_divi_multi &rhs) const
{
    int tempSize;
    tempSize = (this->size + rhs.size - 2);

    polinomio_divi_multi tempArr(0, tempSize);

        for (int i = 0; i < this->size; i++)
        {
            if (this->coeffPtr[i] != 0) // solo multiplica sino es por cero
            {
                for (int j = 0; j < rhs.size; j++)
                {
                    tempArr.coeffPtr[i + j] += (this->coeffPtr[i] * rhs.coeffPtr[j]);
                    //
                }
            }
        }

    return tempArr; // dveuleve el producro de la multiplicacion de dos  polinomio_divi_multinomials
}


polinomio_divi_multi polinomio_divi_multi::operator/(const polinomio_divi_multi &rhs) const
{
    int tempSize;
    tempSize = (this->size + rhs.size);

    polinomio_divi_multi tempArr(0, tempSize);

        for (int i = 0; i < this->size; i++)
        {
            if (this->coeffPtr[i] != 0) //solo divide sino es por cero
            {
                for (int j = 0; j < rhs.size; j++)
                {
                    tempArr.coeffPtr[j-i-2] += (rhs.coeffPtr[j] /  this->coeffPtr[i]);
                    // rellena los nuevos valores
                }
            }
        }

    return tempArr; // retorna el producto de la divide de dos polinomio_divi_multi
}






polinomio_divi_multi& polinomio_divi_multi::operator=(const polinomio_divi_multi &rhs)
{
    if (this->coeffPtr == rhs.coeffPtr)
    {
        return *this;
    }

    if (this->size < rhs.size)
    {
        delete[] this->coeffPtr;    // elimina este arreglo
        coeffPtr = NULL;
        this->size = rhs.size;
        this->coeffPtr = new int[this->size];   // crea una copia para el nuevo arreglo

        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = rhs.coeffPtr[i];    // copia los valores en el nuevo arreglo
        }
    }

    if (this->size > rhs.size)  // se fija si el arreglo es mas grande
    {
        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = 0;  // pone todos los indices en cero
        }

        for (int j = 0; j < rhs.size; j++)
        {
            this->coeffPtr[j] = rhs.coeffPtr[j]; // copia los valores en el nuevo arreglo
        }
    }

    if (this->size == rhs.size) // se fija si el largo del arreglo es el mismo
    {
        for (int k = 0; k < this->size; k++)
        {
            this->coeffPtr[k] = rhs.coeffPtr[k];    //copia valores para el nuevo arreglo
        }
    }

    return *this;   // devuelve el nuevo arreglo
}
