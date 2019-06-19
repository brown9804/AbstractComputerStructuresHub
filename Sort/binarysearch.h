#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#include "header.h"
// bsuqueda binaria
template<class T>
int ArrayList<T>::binarySearch(const T & element) const {

    if (sorted) {

        return binarySearch(element, 0, size - 1);
    }
    else {

        return -1;
    }
}

// metodo principal de la busqueda binaria
template<class T>
int ArrayList<T>::binarySearch(const T & element, int index1, int index2) const {

    if (index1 < index2) {

        int pivot = (index1 + index2) / 2;

        if (element < array[pivot]) {

            return binarySearch(element, index1, pivot - 1);
        }
        else if (element > array[pivot]) {

            return binarySearch(element, pivot + 1, index2);
        }
        else {

            return pivot;
        }
    }
    else if (index1 == index2) {

        return index1;
    }
    else {

        return -1;
    }
}



#endif
