#include <iostream>
#include <fstream>
#include <string.h>
#include "Grafo.h"
#include <time.h>
#include <stdlib.h>


using namespace std;

int main(int argc, char *argv[]){

    //Inicializando a sead para criar um mecanismo de busca sempre diferente entre dois vertices
    time_t t;
    srand(time(&t));
    
    //Vertice de busca no grafo
    int s;
    int d;

    Grafo grafo(argv[1]);
    
    cout << "GRAFO COM MATRIZ DE ADJACENCIA\n";
    grafo.matriz_adj_init();
    grafo.matriz_adj_exibir();
    
    cout << "GRAFO COM LISTA DE ADJACENCIA\n";
    grafo.lista_adj_init();
    grafo.lista_adj_exibir();
    
    if(strcmp(argv[1], "instncias_grafo/pcv4.txt") == 0){
        do{
            s = rand()%4;
            d = rand()%4;
        }while(s == d);
        cout << "BUSCA NO GRAFO\n";
        grafo.bfs(s, d);
        grafo.dfs(s, d);
    }else if(strcmp(argv[1], "instncias_grafo/pcv10.txt") == 0){
        do{
            s = rand()%10;
            d = rand()%10;
        }while(s == d);
        cout << "BUSCA NO GRAFO\n";
        grafo.bfs(s, d);
        grafo.dfs(s, d);
    }else if(strcmp(argv[1], "instncias_grafo/pcv50.txt") == 0){
        do{
            s = rand()%50;
            d = rand()%50;
        }while(s == d);
        cout << "BUSCA NO GRAFO\n";
        grafo.bfs(s, d);
        grafo.dfs(s, d);
    }else{
        do{
            s = rand()%177;
            d = rand()%177;
        }while(s == d);
        cout << "BUSCA NO GRAFO\n";
        grafo.bfs(s, d);
        grafo.dfs(s, d);
    }
        

    return 0;
}
