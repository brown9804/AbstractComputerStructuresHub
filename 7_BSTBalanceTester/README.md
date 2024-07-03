# Binary Search Tree (BST) Balance Tester in C++

Costa Rica

Belinda Brown, belindabrownr04@gmail.com

[![GitHub](https://img.shields.io/badge/--181717?logo=github&logoColor=ffffff)](https://github.com/)
[brown9804](https://github.com/brown9804)

June 2019

----------

A **Binary Search Tree (BST)** is a node-based binary tree data structure with the following properties:
- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.
- There must be no duplicate nodes.

## Balanced Binary Search Tree (BBST)

A **Balanced Binary Search Tree (BBST)** is a type of BST where each node in the tree has approximately the same number of descendant nodes on each subtree underneath it. This means that the "height" of the tree has been minimized. For a tree that is not "Balanced", it is possible to have a binary tree where all the "left" child nodes are null, and it still otherwise has the properties of a "binary search tree". This is called a degenerate tree, as it is structurally more like a Linked List, and therefore would have O(N) search time instead of O(log(N)).

## Balance Tester in BST

In the context of Binary Search Trees (BST), a "Balance Tester" would be a function or algorithm that checks if the BST is balanced or not. A BST is considered balanced if, for every node in the tree, the depth difference between its left and right subtrees is no more than 1.

Here's a general approach to test if a BST is balanced:

1. **Calculate the height of the left and right subtrees for each node**: This can be done using a depth-first search (DFS) traversal. Starting from the root, recursively calculate the height of the left and right subtrees. The height of a tree is the maximum of the heights of its left and right subtrees, plus one.

2. **Check the balance condition**: For each node, check if the absolute difference between the heights of the left and right subtrees is at most 1. If this condition is violated for any node, then the BST is not balanced.

If you want to balance an unbalanced BST, you can follow these steps:

1. **In-Order Traversal**: Perform an in-order traversal of the BST and store each node's value in an array. An in-order traversal of a BST will process all nodes in ascending order.

2. **Building the Balanced BST**: Using the sorted array, recursively select the middle element as the root node, then build the left subtree from the elements before it and the right subtree from the elements after it. This step is akin to a binary search where we use the middle of the current array (or subarray) as the root and apply the logic recursively to the left and right halves.

This approach ensures that the number of nodes on the left and right of any node is as equal as possible, thus creating a balanced tree. However, please note that this process does not preserve the original structure of the tree, but it does maintain the BST property (left child < parent < right child) and ensures the tree is balanced.

## Execution

To run the program, navigate to the folder containing the program using your console or terminal. The program is located in either the "BST" or "Balance tester" folder. Once inside the folder, type the following command in the console or terminal:

```bash
$ make
