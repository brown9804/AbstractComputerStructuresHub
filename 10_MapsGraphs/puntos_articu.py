# coding=utf-8
from header import *

def PathExist(gph, raiz, destino_ver_dat):
    count = gph.count
    visitado_verti = [False] * count
    visitado_verti[raiz] = True
    DFSRec(gph, raiz, visitado_verti)
    return visitado_verti[destino_ver_dat]



def isConnected(gph):
    count = gph.count
    visitado_verti = [False] * count
    visitado_verti[0] = True
    DFSRec(gph, 0, visitado_verti)
    i = 0
    while i < count:
        if visitado_verti[i] == False:
            return False
        i += 1
    return True
