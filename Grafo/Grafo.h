#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <string.h>
#include <utility> 
#include "Fila_Sequencial/FilaSeq.h"
#include <algorithm>
#include <stack> 

using namespace std;

class Grafo
{
public:
    Grafo();
    Grafo(char arq[50]);

    //Metodos da matriz de adjacencia
    void matriz_adj_init();
    void matriz_adj_exibir();
    
    //Metodos da lista de adjacencia
    void lista_adj_init(); 
    void lista_adj_exibir();

    //Algoritmo de busca
    void bfs(int s, int d);
    void dfs(int s, int d);

private:
    int ordem;
    int **matriz_adj; // Ponteiro para a matriz de adjacencia
    char file[50];
    list<pair<int, int>> *lista_adj; // Vetor da lista de adjacencia

};

