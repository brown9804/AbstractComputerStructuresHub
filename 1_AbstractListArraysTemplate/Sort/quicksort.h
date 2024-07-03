#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "header.h"


template<class T>
void ArrayList<T>::quickSort() {

    int index1 = 0;
    int index2 = size - 1;

    quickSort(index1, index2);

    sorted = true;
}


template<class T>
const T & ArrayList<T>::choosePivot(int index1, int index2) {

    int center = (index1 + index2) / 2;

    if (array[center] < array[index1]) {

        move(index1, center);
    }
    if (array[index1] > array[index2]) {

        move(index1, index2);
    }
    if (array[center] > array[index2]) {

        move(center, index2);
    }

    move(center, index2 - 1);

    return array[index2 - 1];
}


template<class T>
void ArrayList<T>::quickSort(int index1, int index2) {

    if (index2 - index1 >= 10) {

        const T & pivot = choosePivot(index1, index2);

        int i = index1, j = index2 - 1;

        while (true) {

            while (array[++i] < pivot);
            while (array[--j] > pivot);

            if (i < j) {

                move(i, j);
            }
            else {

                break;
            }
        }

        move(i, index2 - 1);

        quickSort(index1, i - 1);
        quickSort(i + 1, index2);
    }
    else {

        SelectionSort(index1, index2);
    }
}

#endif
