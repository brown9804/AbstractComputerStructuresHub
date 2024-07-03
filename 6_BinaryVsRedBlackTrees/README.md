# Binary Search Trees (ABB) vs Red-Black Trees in C++

Costa Rica

Belinda Brown, belindabrownr04@gmail.com

[![GitHub](https://img.shields.io/badge/--181717?logo=github&logoColor=ffffff)](https://github.com/)
[brown9804](https://github.com/brown9804)

June 2019

----------

This project explores two types of self-balancing binary search trees: Binary Search Trees (ABB) and Red-Black Trees.

## Binary Search Trees (ABB)
A Binary Search Tree (BST) is a tree in which all the nodes follow the below property: The left sub-tree of a node has a key less than or equal to its parent node's key. The right sub-tree of a node has a key greater than to its parent node's key. Thus, BST divides all its sub-trees into two segments; the left sub-tree and the right sub-tree and can be defined as – left_subtree (keys) ≤ node (key) ≤ right_subtree (keys).

Basic operations include:
- **Insertion**: Adds an element to the tree.
- **Deletion**: Removes an element from the tree.
- **Location**: Finds an element in the tree.

## Red-Black Trees
A Red-Black Tree is a kind of self-balancing binary search tree where each node contains an extra bit for denoting the color of the node, either red or black. A Red-Black Tree is a balanced binary search tree with the following properties:
1. Every node is either red or black.
2. The root is black.
3. All leaves (NULL) are black.
4. If a node is red, then both its children are black.
5. Every simple path from a node to a descendant leaf contains an equal number of black nodes.

The same basic operations (insertion, deletion, location) are performed in Red-Black Trees.

## Execution

To run the program, navigate to the folder containing the program using your console or terminal. The program is located in either the "Arboles_Rojo_y_Negro" or "Arboles_ABB" folder. Once inside the folder, type the following command in the console or terminal:

```bash
$ make

