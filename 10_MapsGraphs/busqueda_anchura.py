# coding=utf-8
from header import *

def busqueda_por_anchura(gph):
    count = gph.count
    visitado_verti = [0] * count
    i = 0
    while i < count:
        if visitado_verti[i] == 0:
            busqueda_por_anchura_Queue(gph, i, visitado_verti)
        i += 1

def ShortestPath(gph, raiz):
    count = gph.count
    distancia_cada_uno = [-1] * count
    path = [-1] * count
    rastro = deque([])

    rastro.append(raiz)
    distancia_cada_uno[raiz] = 0
    while len(rastro) != 0:
        curr = rastro.popleft()
        head = gph.array[curr].head
        while head != None:
            if distancia_cada_uno[head.destino_ver_dat] == -1:
                distancia_cada_uno[head.destino_ver_dat] = distancia_cada_uno[curr] + 1
                path[head.destino_ver_dat] = curr
                rastro.append(head.destino_ver_dat)
            head = head.next
    i = 0
    while i < count:
        print path[i] , "a" , i , "para" , distancia_cada_uno[i]
        i += 1


def busqueda_por_anchura_Queue(gph, index, visitado_verti):
    rastro = deque([])
    visitado_verti[index] = 1
    rastro.append(index)
    while len(rastro) != 0:
        curr = rastro.popleft()
        head = gph.array[curr].head
        while head != None:
            if visitado_verti[head.destino_ver_dat] == 0:
                visitado_verti[head.destino_ver_dat] = 1
                rastro.append(head.destino_ver_dat)
            head = head.next
