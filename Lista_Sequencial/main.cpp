#include "Lista.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    Lista<int> teste;

    srand(time(NULL));  

    if(teste.vazia())
        cout << "Lista Vazia\n";
    
    //Gerando os valores da lista
    for(int i=1; i<=100; i++){ 
        if(i == 4)
            teste.inserir(i, 10);
        else
            teste.inserir(i, rand()%100);
    
    }
    cout << "Tamanho atual da lista: " << teste.tamanho() << endl;

    cout << "Lista[ " << teste.tamanho() << "] = [ ";
    for(int i=1; i<teste.tamanho(); i++){
        if(i == teste.tamanho() - 1)
            cout << teste.elemento(i) << "]\n";
        else
            cout << teste.elemento(i) << ", ";
    }

    if(teste.cheia())
        cout << "Lista esta cheia\n";

    cout << "Elemento da posicao 4: " << teste.posicao(10) << endl;     

    teste.remover(4);    

    cout << "Lista[ " << teste.tamanho() << "] = [ ";
    for(int i=1; i<teste.tamanho(); i++){
        if(i == teste.tamanho() - 1)
            cout << teste.elemento(i) << "]\n";
        else
            cout << teste.elemento(i) << ", ";
    }

    teste.inserir(4, 10000);

    cout << "Lista[ " << teste.tamanho() << "] = [ ";
    for(int i=1; i<teste.tamanho(); i++){
        if(i == teste.tamanho() - 1)
            cout << teste.elemento(i) << "]\n";
        else
            cout << teste.elemento(i) << ", ";
    }

    return 0;    
}