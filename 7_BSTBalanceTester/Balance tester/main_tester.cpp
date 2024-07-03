#include "node.h"

int main() {
	cout<<"Digite los elementos qu edesea para el árbol, debe digitar como último elemento 0 para detener el ingreso de posibles elementos:\n ";
	BST_node* base = creando_binary_search_tree();

	cout << "El árbol se encuentra balanceado?\n ";
	if (se_encuentra_balanceado(base)) {
		cout << "Sí \n";
	}
	else {
		cout << "No \n";
	}

	return 0;
}
