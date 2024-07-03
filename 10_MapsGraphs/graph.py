# coding=utf-8
from header import *

class Graph(object):
    class AdjNode(object):
        def __init__(self, src, dst, cst=1):
            self.raiz = src
            self.destino_ver_dat = dst
            self.cost = cst
            self.next = None

    class AdjList(object):
        def __init__(self):
            self.head = None


    def __init__(self, cnt):
        self.count = cnt
        self.array = [None] * cnt
        i = 0
        while i < cnt:
            self.array[i] = self.AdjList()
            self.array[i].head = None
            i += 1

    def AddEdge(self, raiz, destino_ver_dat, cost=1):
        node = self.AdjNode(raiz, destino_ver_dat, cost)
        node.next = self.array[raiz].head
        self.array[raiz].head = node

    def AddBiEdge(self, raiz, destino_ver_dat, cost=1):
        self.AddEdge(raiz, destino_ver_dat, cost)
        self.AddEdge(destino_ver_dat, raiz, cost)

    def Print(self):
        ad = self.AdjNode()
        i = 0
        while i < self.count:
            ad = self.array[i].head
            if ad != None:
                print "El vertice" , i , " se encuentra conectado a ",
                while ad != None:
                    print ad.destino_ver_dat,
                    ad = ad.next
                print ""
            i += 1
