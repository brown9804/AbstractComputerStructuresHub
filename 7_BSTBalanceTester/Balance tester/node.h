#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cmath>

using namespace std;

class BST_node {
	public:
		int valores;
		BST_node* izquierda;
		BST_node* derecha;
		BST_node(int d) {
			valores = d;
			izquierda = NULL;
			derecha = NULL;
		}
};

BST_node* ingresar_en_binary_search_tree(BST_node* base, int x) {
	if (base == NULL) {
		BST_node* tmp = new BST_node(x);
	return tmp;
}

if (x < base->valores) {
	base->izquierda = ingresar_en_binary_search_tree(base->izquierda , x);
		return base;
	} else {
		base->derecha = ingresar_en_binary_search_tree(base->derecha, x);
		return base;
	}
}

BST_node* creando_binary_search_tree() {
	BST_node* base = NULL;
	int x;
	cin >> x;

	while (true) {
		if (x == 0) break;
		base = ingresar_en_binary_search_tree(base, x);
		cin >> x;
	}
	return base;
}

int altura_bst(BST_node* base) {
	if (base == NULL) return 0;

	int izquierdaHt = altura_bst(base->izquierda);
	int derechaHt = altura_bst(base->derecha);
	int curHt = max(izquierdaHt, derechaHt) + 1;
	return curHt;
}

bool se_encuentra_balanceado(BST_node* base) {
	if (!base) {
		return true;
	}

	int izquierdaHt = altura_bst(base->izquierda);
	int derechaHt = altura_bst(base->derecha);

	if (abs(izquierdaHt - derechaHt) > 1)
			return false;
	return se_encuentra_balanceado(base->izquierda) && se_encuentra_balanceado(base->derecha);
}



#endif
