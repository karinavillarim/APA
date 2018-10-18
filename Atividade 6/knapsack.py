from sys import argv
from itertools import islice

def load(arq='entrada.txt'):
    n, m, obj = [],[],[] #Inicializa n, m e a lista de objetos
    with open(arq,'r') as entrada:
        n, m = (entrada.readline()).rstrip().split(" ") #Extrai o n e m da primeira linha 
        obt = (list((islice(entrada,0,None)))) #Salva o resto do arquivo em uma lista temporária
        for x in obt:
            unidade = list(map(int, x.rstrip().split(" "))) #Converte em inteiros, salva na lista obj
            obj.append(unidade)
    m, n = int(m), int(n)
    
    return n,m,obj

def knapsack(n,m,obj):

    tabela = [[0 for q in range(m+1)] for t in range(n+1)] #Cria uma tabela com linhas para cada item, e colunas para cada peso.
    for i in range(1,n+1): #Loop de colunas
        for j in range(1,m+1): #Loop das linhas
            if obj[i-1][0] <= j: 
                tabela[i][j] = max(tabela[i-1][j], obj[i-1][1] + tabela[i-1][j - obj[i-1][0]]) #Procura o valor máximo
            else: tabela[i][j] = tabela[i-1][j] #Caso contrário, retorna o valor da linha na coluna anterior

    #Impressao de quais itens foram selecionados
    t_n, t_m, t_it = n, m, []

    while t_n and t_m > 0:
        if tabela[t_n][t_m] != tabela[t_n-1][t_m]: #Se o valor da linha na coluna for diferente da coluna acima imediatamente desta, marca o valor 
            t_it.append(t_n)
            t_n -= 1
            t_m -= obj[t_n][0]
        else:
                t_n -= 1

    print("Solução: \n Um total de " + str(len(t_it)) + " itens: " ,end='')
    for x in t_it: print(x, end=', ')
    print("com o valor total de " + str(tabela[n][m]))


n,m,obj = load("mochila1000.txt")

knapsack(n,m,obj)
