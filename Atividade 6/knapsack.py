entrada = 'mochila1000.txt'

def load(entrada):
    
    valores = []
    pesos = []
    obj = []
    
    with open(entrada,'r') as entrada: 
            for line in entrada: 
                linha = list(map(int, line.rstrip().split(" ")))
                obj.append(linha)

    n = obj[0][0]
    m = obj[0][1] #Guarda a capacidade da mochila

    for i in range(1,(len(obj))):
        pesos.append(obj[i][0]) #Ordena os pesos num vetor
    
    for i in range(1,(len(obj))):
        valores.append(obj[i][1]) #Ordena os valores num vetor

    return n,m,pesos,valores

def knapSack(n,m,pesos,valores):
    K = [[0 for x in range(m+1)] for x in range(n+1)]
 
    for i in range(n+1):
        for w in range(m+1):
            if i==0 or w==0:
                K[i][w] = 0
            elif pesos[i-1] <= w:
                K[i][w] = max(valores[i-1] + K[i-1][w-pesos[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]

    a = n
    b = m
    itens = []

    while a and b > 0:
        if K[a][b] != K[a-1][b]:
            itens.append(a)
            b = b - pesos[a-1]
            a = a - 1
        else:
            a = a - 1

    print("Total de " + str(len(itens)) + " itens, sendo eles: " + str(itens) + "\nCom valor total: " + str(K[n][m]))

n,m,pesos,valores = load(entrada)
knapSack(n,m,pesos,valores)
