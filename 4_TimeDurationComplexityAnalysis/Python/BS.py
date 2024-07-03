from time import time
import re
import numpy
import os
import sys
import string 

def bs (objetivo):


    fname = input("Digite nombre del archivo (con su .txt): ")

    #lectura de la primera linea
    f = open(fname, 'r')
    l = f.readline()
    nuevol = int(l)

    #Lectura de la segunda linea, se obtiene una lista
    for index,line in enumerate(open(fname, 'r').readlines()):
        w = line.split(' ')
        l1 = w[0:nuevol]

    #Se convierte cada entrada de la lista en numeros en un array
    array = [int(i) for i in l1]
    
    #Se ordenan los números del array
    array.sort()

    print("Cantidad de datos", nuevol)
    print("Objetivo:", objetivo)

    tiempoinicial = time()

    min = 0
    max = len(array)-1
    iteracion = 0
    fin = False
    while min <= max and not fin:
        iteracion = iteracion + 1
        promedio = (min+max)//2

        if array[promedio] == objetivo:
            print("Objetivo encontrado, igual al promedio")
            fin = True

        if array[promedio] < objetivo:
            #print("Objetivo no encontrado, buscando más a la derecha")
            min = promedio + 1
            #promedio = (min+max)//2
            fin=False

        if array[promedio] > objetivo: 
            #print("Objetivo no encontrado, buscando más a la izquierda")
            max = promedio -1
            fin=False
            #promedio = (min+max)//2

        else:
            print("Objetivo no está")
            fin = True


    tiempofinal = time()
    tiempototal = tiempofinal - tiempoinicial

    print("Iteraciones:", iteracion)
    print("Tiempo de ejecución:", tiempototal)
    return fin




objetivo = 75

bs(objetivo)


