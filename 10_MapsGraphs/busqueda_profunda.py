# coding=utf-8
from header import *

def DFSStack(gph):
    count = gph.count
    visitado_verti = [0] * count
    stk = []
    visitado_verti[0] = 1
    stk.append(object)
    while len(stk) != 0:
        curr = stk.pop()
        head = gph.array[curr].head
        while head != None:
            if visitado_verti[head.destino_ver_dat] == 0:
                visitado_verti[head.destino_ver_dat] = 1
                append(head.destino_ver_dat)
            head = head.next

def busqueda_por_profundidad(gph):
    count = gph.count
    visitado_verti = [0] * count
    i = 0
    while i < count:
        if visitado_verti[i] == 0:
            visitado_verti[i] = 1
            DFSRec(gph, i, visitado_verti)
        i += 1


def DFSRec(gph, index, visitado_verti):
    head = gph.array[index].head
    while head != None:
        if visitado_verti[head.destino_ver_dat] == False:
            visitado_verti[head.destino_ver_dat] = True
            DFSRec(gph, head.destino_ver_dat, visitado_verti)
        head = head.next
