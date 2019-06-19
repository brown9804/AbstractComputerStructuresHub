
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include "header.h"
template<class T>
class ArrayList {

    public:
        //Constructores
        ArrayList();
        ArrayList(int theSize);
        ArrayList(const ArrayList<T> & list);
        ArrayList(const ArrayList<T> &list, int theCapacity);
        ~ArrayList();
        //Metodos
        void add(const T & element);
        void add(const T & element, int index);
        bool agrega_ordena(const T & element);
        void add(const ArrayList<T> & list, int index);
        void add(const ArrayList<T> & list);
        bool eliminar_elemento(const T & element);
        const T * eliminar(int index);
        void eliminar_todo();
        void eliminar_todo(int newCapacity);
        bool move(int index1, int index2);
        const T * get(int index) const;
        //Basicas
        const ArrayList<T> & subList(int index1, int index2) const;
        T * getArray() const;
        T * getSubArray(int index1, int index2) const;
        //Binaria
        int binarySearch(const T & element) const;
        //Ordenamiento
        void quickSort();
        void SelectionSort();
        void mergeSort();
        void shuffle();
        //Informacion obtenida
        int Obt_tamano() const;
        int Obt_capacidad() const;
        std::string toString() const;










    private:
        //Base de ArrayList.
        T * array;
        //elemntos de ArrayList
        int size;
        //memoria
        int capacity;
        //para saber si fue ordenado o no
        bool sorted;

        //~Methods-----------------------//
        void reallocate();
        void reallocate(int newSize);
        //~SORTS-----------------------------------
        const T & choosePivot(int index1, int index2);
        void quickSort(int index1, int index2);
        int binarySearch(const T & element, int index1, int index2) const;
        void SelectionSort(int index1, int index2);
        T * mergeSort(T * array, int theCapacity, int arraySize);
};

//~Class Initialization/Destruction/Resetting Functions---------------------
/**
 * Default constructor,
 * creates a 20 element ArrayList, of type T.
 */
template<class T>
ArrayList<T>::ArrayList() {

    array = new T[20];
    capacity = 20;
    size = 0;
}

/**
 * Creates an ArrayList of type T of size
 * theSize.
 *
 * @param theSize the size to initialize the array to.
 */
template<class T>
ArrayList<T>::ArrayList(int theSize) {

    array = new T[theSize];
    capacity = theSize;
    size = 0;
}

/**
 * Creates an ArrayList of type T that is twice the
 * size of the passed in ArrayList, and adds all elements
 * from the passed ArrayList<T> list, to this ArrayList.
 *
 * Runs in O(n) time, where n = the size of the passed list.
 *
 * @param list the ArrayList to use as a seed for this ArrayList.
 */
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> & list) {

    array = new T[list.Obt_tamano() * 2];
    capacity = list.Obt_tamano() * 2;
    size = list.Obt_tamano();

    for (int i = 0; i < list.Obt_tamano(); i++) {

        array[i] = *list.get(i);
    }
}

/**
 * Creates an ArrayList of type T that has a capacity equal to the passed
 * in theCapacity parameter. This ArrayList starts with the passed ArrayList.
 *
 * Note: If the passed in capacity is smaller than the size of the passed in
 *          ArrayList, then the capacity is set to twice the size of the
 *          passed ArrayList.
 *
 * Runs in O(n) time where n is the size of the passed list.
 *
 * @param list the ArrayList to use as a seed for this ArrayList.
 * @param theCapacity the capacity for this ArrayList.
 */
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> & list, int theCapacity) {

    if (theCapacity >= list.Obt_tamano()) {

        array = new T[theCapacity];
        capacity = theCapacity;
    }
    else {

        array = new T[list->Obt_tamano() * 2];
        capacity = list->Obt_tamano() * 2;
    }

    size = list->size;

    for (int i = 0; i < size; i++) {

        array[i] = list->get(i);
    }
}

/**
 * General destructor, deallocates the array.
 */
template<class T>
ArrayList<T>::~ArrayList() {

    delete [] array;
}

/**
 * Doubles the capacity of the ArrayList.
 *
 * Runs in O(n) time where n is the current size of the list.
 */
template<class T>
void ArrayList<T>::reallocate() {

    capacity *= 2;
    T * temp = new T[capacity];

    for (int i = 0; i < size; i++) {

        temp[i] = array[i];
    }

    delete [] array;

    array = temp;
}

/**
 * Creates a new Array that is of size, newSize.
 *
 * Runs in O(n) time where n is the current size of the list..
 *
 * @param newSize the new size to make this ArrayList.
 */
template<class T>
void ArrayList<T>::reallocate(int newSize) {

    capacity = newSize;
    T * temp = new T[newSize];

    for (int i = 0; i < size; i++) {

        temp[i] = array[i];

        delete [] array;

        array = temp;
    }
}

//~Basic Add/Remove etc Functions------------------------------------
/**
 * Adds the passed in element to the end of the ArrayList.
 *
 * Runs in O(n) in worst case, where reallocate is called.
 * O(1) for most cases.
 *
 * @param element the element to add to the array.
 */
template<class T>
void ArrayList<T>::add(const T & element) {

    if ((size - 1) == capacity) {

        reallocate();
    }

    array[size] = element;
    size++;

    sorted = false;
}

/**
 * Adds the passed in element to the specified index. Provided
 * that the index is valid.
 *
 * A valid index is: 0 <= index <= size
 *
 * Runs in O(n) where n is either the number of elements that must
 * be shifted to fit element in index, or the size of the array if
 * the array has to be reallocated.
 *
 * @param element the element to add to the ArrayList.
 * @param index the index to add the element to.
 */
template<class T>
void ArrayList<T>::add(const T & element, int index) {

    if (index >= 0 && index <= size) {

        //Reallocate if necessary.
        if (index >= capacity || size == capacity) {

            int multiplicand = (index >= capacity) ? index : size;
            reallocate(multiplicand * 2);
        }

        //Shift elements to the right.
        for (int i = size; i > index; i--) {

            array[i] = array[i - 1];
        }

        array[index] = element;
        size++;

        sorted = false;
    }
}

/**
 * Adds an ArrayList<T> to the end of this ArrayList.
 *
 * Runs in O(n) time, where n = the size of the passed list.
 *
 * @param list the ArrayList<T> to add to this one.
 */
template<class T>
void ArrayList<T>::add(const ArrayList<T> & list) {

    for (int i = 0; i < list.Obt_tamano(); i++) {

        add(list.get(i));
    }
}

/**
 * Adds an ArrayList<T> to this ArrayList<T> at the specified index.
 *
 * Note: If index is larger than the capacity of the ArrayList, the
 *          ArrayList is enlarged to a size that is two times the index plus
 *          the size of the arrayList.
 *          If you want a check on the index size, use Obt_tamano() to check.
 *
 * Runs in O(n) time where n is the size of the passed in list, or the number
 * of elements which are shifted in this list. Whichever one is larger.
 *
 * @param list the ArrayList<T> to add to this one.
 * @param index the index to add the passed in ArrayList<T> at.
 */
template<class T>
void ArrayList<T>::add(const ArrayList<T> & list, int index) {

    //If passed in list will overflow off of this one.
    if (index >= capacity || (index + list.Obt_tamano()) >= capacity) {

        reallocate((index + list.Obt_tamano()) * 2);
    }

    T* temp = new T[capacity + list.Obt_tamano()];

    //Loop through array, and passed list, adding them where they are appropriate.
    for (int i = 0, j = 0, k = 0; i < size + list.Obt_tamano(); i++) {

        if (i >= index && i < index + list.Obt_tamano()) {

            temp[i] = *list.get(j);
            j++;
        }
        else {

            temp[i] = array[k];
            k++;
        }
    }

    delete [] array;
    array = temp;
    size += list.Obt_tamano();

    sorted = false;
}

/**
 * Takes in an element of type T and adds it to the correct point
 * in the ArrayList such that the sort is preserved.
 *
 * NOTE: If the ArrayList is NOT sorted, the element is not inserted,
 *          and false is returned.
 *
 * Runs in O(n) time where n is the number of elements that must be shifted to
 * accommodate the inserted element.
 *
 * @param element the element to insert.
 * @return true if ArrayList was sorted (meaning the element was inserted),
 *          false if the ArrayList was NOT sorted (the element was NOT inserted)
 */
template<class T>
bool ArrayList<T>::agrega_ordena(const T & element) {

    if (sorted) {

        add(element, binarySearch(element));

        sorted = true;

        return true;
    }

    return false;
}

/**
 * Removes the passed in element from the ArrayList if
 * it's present. Returns a boolean value indicating
 * if the element was present in the array.
 *
 * Runs in O(n) time where n is the number of elements that must be shifted
 * to fill the hole.
 *
 * @param element the element to eliminar from the array.
 * @return value true if the element was present, false otherwise.
 */
template<class T>
bool ArrayList<T>::eliminar_elemento(const T & element) {

    int index = binarySearch(element);

    if (index >= 0 && index < size) {

        eliminar(index);

        return true;
    }
    else {

        return false;
    }
}

/**
 * Removes the element at the passed in index.
 *
 * Runs in O(n) time where n is the number of elements that must be shifted.
 *
 * @param index the index of the element to eliminar.
 * @return eliminard a pointer to the eliminard element, or NULL/0 if
 *          the index is not valid.
 */
template<class T>
const T * ArrayList<T>::eliminar(int index) {

    T * removed = NULL;

    if (index < size && index >= 0) {

        for (int i = index; i < size; i++) {

            array[i] = array[i + 1];
        }

        removed = array + index;
        size--;
    }

    return removed;
}

//Vacea la lista
template<class T>
void ArrayList<T>::eliminar_todo() {

    delete [] array;
    array = new T[capacity];

    sorted = false;
    size = 0;
}

//vacea y crea una nueva
template<class T>
void ArrayList<T>::eliminar_todo(int newCapacity) {

    delete [] array;
    array = new T[newCapacity];

    sorted = false;
    capacity = newCapacity;
    size = 0;
}

//meuve del indice uno al dos
template<class T>
bool ArrayList<T>::move(int index1, int index2) {

    if (index1 >= 0 && index2 >= 0 &&
            index1 < size && index2 < size) {

        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;

        sorted = false;

        return true;
    }

    return false;
}

// obtiene elemento indexado atras
template<class T>
const T * ArrayList<T>::get(int index) const {

    return (index >= 0 && index < size) ? (array + index) : NULL;
}

// da el tamano que tiene el arreglo
template<class T>
int ArrayList<T>::Obt_tamano() const {

    return size;
}

//da la capacidad
template<class T>
int ArrayList<T>::Obt_capacidad() const {

    return capacity;
}


template<class T>
const ArrayList<T> & ArrayList<T>::subList(int index1, int index2) const {

    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 <= size && index1 < index2) {

        ArrayList<T> returnList = new ArrayList<T>(index2 - index1);

        //Loop through all elements, so there isn't just a reference
        //copy performed.
        for (int i = index1; i < index2; i++) {

            returnList.add(this->get(i));
        }

        return returnList;
    }

    return NULL;
}

// devuevlve una copia del array
template<class T>
T * ArrayList<T>::getArray() const {

    T * arrayCopy = new T[size];

    for (int i = 0; i < size; i++) {

        arrayCopy[i] = array[i];
    }

    return arrayCopy;
}


template<class T>
T * ArrayList<T>::getSubArray(int index1, int index2) const {

    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 <= size && index1 < index2) {

        T* returnList = new T[index2 - index1];

        //Loop through all elements, so there isn't just a reference
        //copy performed.
        for (int i = index1; i < index2; i++) {

            returnList[i] = this->get(i);
        }

        return returnList;
    }

    return NULL;
}

//hace SelectionSort
template<class T>
void ArrayList<T>::SelectionSort() {

    SelectionSort(0, size - 1);

    sorted = true;
}

// core con dos indices
template<class T>
void ArrayList<T>::SelectionSort(int index1, int index2) {

    if (index1 < index2
            && index1 >= 0 && index1 < size
            && index2 >= 0 && index2 < size) {

        //valor temporal
        T element;


        for (int i = index1; i <= index2; i++) {

            element = array[i];


            for (int j = i; j >= 0; j--) {


                if (j == 0 || array[j - 1] <= element) {

                    array[j] = element;
                    break;
                }

                else {

                    array[j] = array[j - 1];
                }
            }
        }
    }
}

// aleatorio

template<class T>
void ArrayList<T>::shuffle() {

    T temp;
    int random;


    for (int i = 0; i < size; i++) {


        random = rand() % size;

        temp = array[i];
        array[i] = array[random];
        array[random] = temp;
    }

    sorted = false;
}


template<class T>
std::string ArrayList<T>::toString() const {

    std::ostringstream streamOut;

    streamOut << "(";

    for (int i = 0; i < size; i++) {

        streamOut << array[i];

        if (i != (size - 1)) {

            streamOut << ", ";
        }
    }

    streamOut << ")\n";

    std::string returnString = streamOut.str();

    return returnString;
}

#endif 
