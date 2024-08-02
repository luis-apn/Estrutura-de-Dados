#include "Lista.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    
    //Criando Uma variavel do tipo da lista para inteiro passando 
    Lista<int> list;

    if(list.vazia())
        cout << "A lista esta vazia" << endl;

    //Inserindo os elementos na lista
    for(int i=0; i<20; i++)
        list.inserir(i+1, i+1);
    
    //Exibindo os elementos do vetor na lista
    list.exibir();

    if(list.cheia())
        cout << "A lista esta cheia\n";

    cout << "Tamanho da lista: " << list.tamanho() << endl;

    cout << "Elemento na posicao 4: " << list.elemento(4) << endl;

    cout << "Posicao do elemento 4: " << list.posicao(4) << endl;

    cout << "Removendo o elemento da posicao 4" << endl;
    list.remover(4);
    list.exibir();

    return 0;    
}