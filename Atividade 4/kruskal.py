entrada = 'dij10.txt'

def load(entrada): 
        global adj
        adj = []
        global n

        with open(entrada,'r') as entrada: 
            for line in entrada: 
                linha = list(map(int, line.rstrip().split(" ")))
                adj.append(linha)

        n = adj.pop(0) 
        n = n[0]
        #print(n)
        #print(adj)
        return n, adj 

class Graph:

    def __init__(self, vertices):
        self.vert = vertices #Numero de vertices
        self.grafo = [] #Armazenamento do grafo

    def addAresta(self,u,v,w): #Adicionando arestas ao grafo
        self.grafo.append([u,v,w])

    def leArestas(self):
       for i in range(0,n):
           u = i
           v = u + 1
           cc = 0
           while(v<n):
               #print(u)
               #print(cc)
               #print(adj[u][cc])
               w = adj[u][cc]
               self.addAresta(u,v,w)
               v = v+1
               cc = cc+1
       print(self.grafo)     

    def busca(self, parent, i):
        if parent[i] == i:
            return i
        return self.busca(parent, parent[i])

    def junçao(self, parent, rank, x, y): #Une x e y
        raizX = self.busca(parent, x)
        raizY = self.busca(parent, y)

        if rank[raizX] < rank[raizY]: #Anexa a menor arvore sob a raiz da maior arvore
            parent[raizX] = raizY
        elif rank[raizX] > rank[raizY]:
            parent[raizY] = raizX
        else:
            parent[raizY] = raizX
            rank[raizX] += 1

    def kruskalMST(self):

        resultado = [] #Armazena o resultado da arvore geradora minima

        i = 0 #Indice das arestas ordenadas
        e = 0 #Indice do resultado
        #Classifica todas as arestas em ordem crescente do seu peso
        self.grafo = sorted(self.grafo, key=lambda item: item[2])

        parent = []
        rank = []

        for no in range(self.vert): #Cria subconjuntos com um unico elemento
            parent.append(no)
            rank.append(0)

        while e < self.vert - 1: #Escolhe o menor vertice e incrementa o indice para a proxima iteracao

            u,v,w = self.grafo[i]
            i = i+1
            x = self.busca(parent,u)
            y = self.busca(parent, v)
            
           #Se a inclusao dessa aresta nao formar um ciclo 
           #incluimos no resultado e aumentamos seu indice para a proxima aresta

            if x != y:
                e = e+1
                resultado.append([u,v,w])
                self.junçao(parent,rank,x,y)

        for u,v,w in resultado:
            print("%d, %d, %d" % (u,v,w))    

                    

load(entrada)
g = Graph(n)
g.leArestas()
g.kruskalMST()
