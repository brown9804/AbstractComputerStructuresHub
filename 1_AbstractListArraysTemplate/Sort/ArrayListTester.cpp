#include "header.h"
#include "ArrayList.h"


using namespace std;


int main(void)
{
	ArrayList<int> List;

	cout << "Agregando 16 valores\n\n";
	List.add(438787);
	List.add(17);
	List.add(147);
	List.add(3);
	List.add(-37);
	List.add(584);
	List.add(-2147);
	List.add(0);
	List.add(-98);
	List.add(247);
	List.add(-37);
	List.add(0);
	List.add(27);
	List.add(187);
	List.add(824);
	List.add(-17);

	cout << "Los valores que hemos agregado son:\n";
	cout << "El tamano de la lista es de: " << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Obteniendo el elemento en la posicion 0\n";
	cout << "El elemento que se encuentra en esta posicion es: " << *List.get(0) << endl << endl;

	cout << "Obteniendo elemento en " << List.Obt_tamano() - 1 << endl;
	cout << "El elemento en " << List.Obt_tamano() - 1
					<< " es: " << *List.get(List.Obt_tamano() - 1) << endl << endl;

	cout << "Eliminando el índice 22 (fuera de límites)\n";
	List.eliminar(22);
	cout << "El tamaño de la lista es: " << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Eliminando el índice 0\n";
	const int * removed = List.eliminar(0);
	cout << "Fue eliminado " << *removed << endl;
	cout << "Ahora, el tamano de esta lista es de: " << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Eliminando el valor en el índice 5\n";
	List.eliminar(5);
	cout << "Ahora, el tamano de esta lista es de:" << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Se eliminara el elemento: -2147 \n";
	List.eliminar_elemento(-2147);
	cout << "Ahora, el tamano de esta lista es de: " << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Se eliminara el elemento 17 \n";
	List.eliminar_elemento(17);
	cout << "Ahora, el tamano de esta lista es de: " << List.Obt_tamano() << endl;
	cout << List.toString() << endl;

	cout << "Probando Selection Sort\n";
	List.SelectionSort();
	cout << List.toString() << endl;

	cout << "Haciendo aleatoria el ArrayList\n";
	List.shuffle();
	cout << "Ahora la lista contiene:\n";
	cout << List.toString() << endl;

	cout << "Probando Quick Sort\n";
	List.quickSort();
	cout << "La lista ordenada es:\n";
	cout << List.toString() << endl;

	cout << "Volviendo aleatoria la lista\n";
	List.shuffle();
	cout << "Ahora la lista contiene:\n";
	cout << List.toString() << endl;

	cout << "Probando Merge Sort\n";
	List.mergeSort();
	cout << List.toString() << endl;

	cout << "Binary Search Test\n";
	cout << "Buscando el 584\n";
	int bsIndex = List.binarySearch(584);
	cout << "El índice de 584 es: " << bsIndex << endl;
	cout << "\n" <<  endl;

	cout << "Buscando el -888\n";
	bsIndex = List.binarySearch(-888);
	cout << "El indice de -888 es: " << bsIndex << endl;
	cout << "Se espera un -1, lo que significa que no esta en la lista\n\n";

	cout << "Agregando el numero 49 al ArrayList\n";
	List.agrega_ordena(49);
	cout << "Ahora contiene\n" << List.toString() << endl;

	cout << "Agregando 523 al indice 7\n";
	List.add(523, 7);
	cout << "La lista contiene:\n" << List.toString() << endl;

	cout << "Agregando el 28 al indice 97 (Fuera de limite del array)\n";
	List.add(-9, 45);
	cout << "Ahora la lista contiene:\n" << List.toString();
	cout << "Como se puede no notar no fue agregado porque sobrepasa el limite \n\n";

	cout << "Creando un nuevo ArrayList es mucho mas grande con la lista como base\n Lo llamaremos ArrayList2";
	ArrayList<int> hugeList = ArrayList<int>(List);
	cout << "La lista contiene\n" << hugeList.toString() << endl;

	cout << "Agregando a ArrayList2 0 a la nueva lista en el indice 9 y 8\n";
	hugeList.add(0, 8);
	hugeList.add(0, 9);
	cout << "Ahora contiene: \n" << hugeList.toString() << endl;

	cout << "Agregando la lista a ArrayList2, en el indice 9\n";
	hugeList.add(List, 9);
	cout << "La lista contiene\n" << hugeList.toString() << endl;

	cout << "La prueba fue finalizada\n";
	return 0;


}
