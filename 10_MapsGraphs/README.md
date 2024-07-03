# Maps (Graphs)


Costa Rica

Belinda Brown, belindabrownr04@gmail.com

[![GitHub](https://img.shields.io/badge/--181717?logo=github&logoColor=ffffff)](https://github.com/)
[brown9804](https://github.com/brown9804)

----------

This project is based on the implementation and modification of an existing code to work with graphs. The code has been modified to accept **directed edges**.

## Implemented Algorithms

The following algorithms have been implemented:

1. **Breadth-First Search and Depth-First Search**: These are graph traversal algorithms. Breadth-First Search (BFS) explores all the vertices of a graph in breadth-first order, i.e., it explores all the vertices at the present "depth" before going to the next level of depth. Depth-First Search (DFS) explores as far as possible along each branch before backtracking.
2. **Dijkstra's Algorithm (Shortest Path)**: This algorithm finds the shortest path between two nodes in a graph. It works by visiting vertices in the graph starting with the object's source vertex, and gradually spreading through the graph like a wavefront, until it reaches the destination vertex.
3. **Kruskal's Algorithm (MST)**: This algorithm finds the minimum spanning tree in a graph. It works by sorting all the edges from the lowest weight to the highest, then adding the edges to the minimum spanning tree in order, skipping those whose addition would create a cycle.
4. **Articulation Points**: The implementation of articulation points is in progress. Articulation points are vertices that, when removed along with associated edges, increase the number of connected components in a graph.

## How to run

```
$ make
```
