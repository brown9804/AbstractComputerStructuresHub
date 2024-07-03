import os, sys
import stat 
import numpy as np
from time import time 

def ss():

    fname = input("Digite nombre del archivo (con su .txt): ")

    #lectura de la primera linea
    f = open(fname, 'r')
    l = f.readline()
    nuevol = int(l)

    #print(nuevol)

    #Lectura de la segunda linea, se obtiene una lista
    for index,line in enumerate(open(fname, 'r').readlines()):
        w = line.split(' ')
        l1 = w[0:nuevol]

    #Se convierte cada entrada de la lista en numeros en un array
    array = [int(i) for i in l1]
    
    print("Cantidad de datos:", nuevol)

    tiempoinicial = time()

    #Procedimiento del SS
    for i in range(nuevol):
        menor = i

        for j in range(i+1, nuevol):
            if array[j] < array[menor]:
                menor = j

        swap = array[i]
        array[i] = array[menor]
        array[menor] = swap

    tiempofinal = time()
    tiempototal = tiempofinal - tiempoinicial


    #print("Nuevo arreglo ordenado:", array)
    print("Tiempo de ejecución:" ,tiempototal)

    return array



ss()



