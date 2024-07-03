# coding=utf-8
from header import *


def Prim_metodo(gph):
    previous = [-1] * gph.count
    dist = [sys.maxint] * gph.count
    raiz = 1
    dist[raiz] = 0
    previous[raiz] = -1

    pqarray = []
    node = Graph.AdjNode(raiz, raiz, 0)
    heapq.heappush(pqarray, (0, node))

    while len(pqarray) != 0:
        val = heapq.heappop(pqarray)
        node = val[1]

        if dist[node.destino_ver_dat] < node.cost:
            continue

        dist[node.destino_ver_dat] = node.cost;
        previous[node.destino_ver_dat] = node.raiz;

        adl = gph.array[node.destino_ver_dat]
        adn = adl.head

        while adn != None:
            if previous[adn.destino_ver_dat]==-1:
                node = Graph.AdjNode(adn.raiz, adn.destino_ver_dat, adn.cost)
                heapq.heappush(pqarray, (adn.cost, node))
            adn = adn.next
    count = gph.count
    i = 0
    while i < count:
        if dist[i] == sys.maxint:
            print "Este es el vertice" , i , "...antes..." , previous[i] , "a una distancia  → → → incalzanble"
        else:
            print "Este es el vertice" , i , "...antes..." , previous[i] , "a una distancia  → → → " , dist[i]
        i += 1
