#!/usr/bin/env python
# coding=utf-8
from header import *




gph = Graph(9)
gph.AddBiEdge(0, 2, 1)
gph.AddBiEdge(1, 2, 5)
gph.AddBiEdge(1, 3, 7)
gph.AddBiEdge(1, 4, 9)
gph.AddBiEdge(3, 2, 2)
gph.AddBiEdge(3, 5, 4)
gph.AddBiEdge(4, 5, 6)
gph.AddBiEdge(4, 6, 3)
gph.AddBiEdge(5, 7, 1)
gph.AddBiEdge(6, 7, 7)
gph.AddBiEdge(7, 8, 17)
print " "
print "Tester de Dijkstra:   "
Dijkstra(gph, 1)
print " "
print "Tester de Prim:   "
Prim_metodo(gph)
print " "
print "Tester de Kruskal:   "
print kruskal(graph)
print " "
print "Tester de busqueda por anchura:   "
print busqueda_por_anchura(gph)
print " "
print "Tester de busqueda por profundidad:   "
print busqueda_por_profundidad(gph)
print " "
print "¿El camino existe?:   "
print " "

print PathExist(gph, 1, 5)
print " "
print "Puntos de articulación:   "
print isConnected(gph)
ShortestPath(gph, 1)
print " "
