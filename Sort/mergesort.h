#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "header.h"


// corre merge sort
template<class T>
void ArrayList<T>::mergeSort() {

    T* temp = mergeSort(array, capacity, size);
    delete [] array;
    array = temp;
    sorted = true;
}


template<class T>
T * ArrayList<T>::mergeSort(T * array, int theCapacity, int arraySize) {

    T * returnArray;

    if (arraySize > 1) {

        int size1 = arraySize / 2;
        int size2 = arraySize - size1;

        T* array1;
        T* array2;

        //Recursiva
        array1 = mergeSort(array, size1, size1);
        array2 = mergeSort(array + size1, size2, size2);

        returnArray = new T[theCapacity];

        int i = 0, j = 0, k = 0;
        while (i < arraySize) {

            if ((j < size1) &&  (k == size2 || array1[j] <= array2[k])) {

                returnArray[i] = array1[j];
                j++;
            }
            else {

                returnArray[i] = array2[k];
                k++;
            }

            i++;
        }


        delete [] array1;
        delete [] array2;
        array1 = 0;
        array2 = 0;
    }
    else {


        returnArray = new T[1];
        returnArray[0] = array[0];
    }

    return returnArray;
}

#endif
