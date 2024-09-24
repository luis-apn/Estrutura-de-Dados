#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <string.h>
#include <utility> //biblioteca para utilizar a biblioteca pair
#include "Fila_Sequencial/FilaSeq.h"
#include <algorithm>
#include <stack> //biblioteca para trabalhar com pilhas em c++

/*
pair -> O pair é um container para armazenar par de dados que podem ser de diferentes tipos

sintaxe:
pair <primeiro tipo, segundo tipo> nome_do_par_de_dados;

lendo os dados:
nome_do_par_de_dados.first
nome_do_par_de_dados.second

Criando pares:
make_pair(primeiro dado, segundo dado)

nome_do_dado.first = dado
nome_do_dado.second = dado
*/

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
    //int calcularDistancia(const vector<int>& caminho);


private:
    int ordem;
    int **matriz_adj; // Ponteiro para a matriz de adjacencia
    char file[50];
    list<pair<int, int>> *lista_adj; // Vetor da lista de adjacencia

};

