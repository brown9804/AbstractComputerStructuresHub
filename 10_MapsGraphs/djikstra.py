# coding=utf-8
from header import *


def Dijkstra(gph, raiz):
    previous = [-1] * gph.count
    distancia = [sys.maxint] * gph.count

    distancia[raiz] = 0
    previous[raiz] = -1

    pqarray = []
    node = Graph.AdjNode(raiz, raiz, 0)
    heapq.heappush(pqarray, (0, node))

    while len(pqarray) != 0:
        val = heapq.heappop(pqarray)
        node = val[1]

        adl = gph.array[node.destino_ver_dat]
        adn = adl.head

        while adn != None:
            alt = adn.cost + distancia[adn.raiz]
            if alt < distancia[adn.destino_ver_dat]:
                distancia[adn.destino_ver_dat] = alt
                previous[adn.destino_ver_dat] = adn.raiz
                node = Graph.AdjNode(adn.raiz, adn.destino_ver_dat, alt)
                heapq.heappush(pqarray, (alt, node))
            adn = adn.next
    count = gph.count
    i = 0
    while i < count:
        if distancia[i] == sys.maxint:
            print "Este es el vertice" , i , "...antes..." , previous[i] , "a una distancia  → → → incalzanble"
        else:
            print "Este es el vertice" , i , "...antes..." , previous[i] , "a una distancia  → →" , distancia[i]
        i += 1
