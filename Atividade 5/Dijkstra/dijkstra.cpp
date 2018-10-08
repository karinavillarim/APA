#include <iostream>
#include <limits>
#include <bits/stdc++.h>
#include <vector>

int INF = std::numeric_limits<int>::max();

using namespace std;

int dijMST(vector<pair<int, int> > adj[], int raiz, int vertice, int fim){
    int chave[vertice];
    int pai[vertice];
    for(int u = 0; u < vertice; u++){ //Inicializando todas as chaves com infinito e o pai como -1
        chave[u] = INF;
        pai[u] = -1;
    }

    chave[raiz] = 0; //Chave da raiz inicializada com zero
    std::vector<bool> inMST(vertice, false);
    priority_queue < pair<int, int>, vector <pair<int, int> > , greater<pair<int, int> > > pq;
    pq.push(make_pair(0, raiz)); 

    while(!pq.empty()){ //Enquanto a lista de prioridade nao esta vazia
        int u = pq.top().second; //Extrai vertice com menor valor da chave
        pq.pop(); 
        inMST[u] = true;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first; //Vertice adjacente
            int w = adj[u][i].second; //Pega o valor do peso da aresta (u,v)

            if(inMST[v] == false && chave[v] > chave[u] + w){ //Se existe um menor caminho pra v atraves de u
                pai[v] = u;
                chave[v] = chave[u] + w; //Atualiza a distancia ate v 
                pq.push(make_pair(chave[v], v));
            }
        }
    }

    for(int i = 0; i <= fim; i++){  
        cout << chave[i] << "-" << pai[i] << endl;
    }
    return chave[fim];
}

int main(){
    
    //Arquivo
    FILE *fp;
    fp = fopen("dij40.txt", "r");

    if (fp == NULL){
        puts("Arquivo nao encontrado");
        exit(1);
    }
    
    int qLines = 0;
    int size;
    int tamanho;
    char line[1000];
    char *token;

    fgets(line, 1000,fp);

    size = atoi(line);

    int x[size][size] = {0};

	std::vector<pair<int, int> > adj[size];

    std::vector<int> v[size];

    while(1){
        int  i = qLines;
        fgets(line, 1000, fp);
        if (feof(fp)){
            break;
        }
        token = strtok(line, "\t");
        while(token!=NULL){
        	int index = ++i;
            x[qLines][index] = atoi(token);
            adj[qLines].push_back(make_pair(index, x[qLines][index])); 
			adj[index].push_back(make_pair(qLines, x[qLines][index])); 
            token = strtok(NULL, "\t");
        }
        qLines++;
    }
    fclose(fp); //Fim da leitura do arquivo
   
    int MST;
    int raiz = 0;
    int fim = size - 1;
    MST = dijMST(adj, raiz, size, fim);

    cout << "Custo final - " << MST << endl;
    
    return 0;
}
