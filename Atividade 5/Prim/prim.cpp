#include <iostream>
#include <limits>
#include <bits/stdc++.h>
#include <vector>

int INF = std::numeric_limits<int>::max();

using namespace std;

int primMST(vector<pair<int, int> > adj[], int raiz, int vertice){
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

        inMST[u] = true; //Coloca vertice na arvore geradora minima

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first; //Vertice adjacente
            int w = adj[u][i].second; //Pega o valor do peso da aresta (u,v)

            if(inMST[v] == false && w < chave[v]){ //Se o vertice nao estiver na arvore e o valor do peso adj a u for menor que sua chave atual
                pai[v] = u; //Atualiza o valor do pai
                chave[v] = w; //Atualiza o valor da chave 
                pq.push(make_pair(chave[v], v));
            }
        }
    }

    int custo = 0;
    int p = 0;

    for(int i = 0; i < vertice; i++){
        custo += chave[i];
        p = pai[i];  
        cout << chave[i] << "-" << p << endl;
    }
    return custo;
}

int main(){
    
    //Arquivo
    FILE *fp;
    fp = fopen("dij50.txt", "r");

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

    MST = primMST(adj, raiz, size);

    cout << "Custo final - " << MST << endl;
    
    return 0;
}
