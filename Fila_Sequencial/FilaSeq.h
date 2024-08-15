#pragma once
#define TAM_MAX 100 //Definicao do tamanho maximo da fila
#include <iostream>

class FilaSeq
{
public:
    FilaSeq();
    void addFim(int valor); 
    bool vazia(); 
    int removeInicio(); 
    int getInicio(); 
    bool cheia(); 
    void exibir(); 
    
private:
    int frente; //Variavel que ira armazenar o indice do primeiro elemento na leitura da fila
    int tras; //Variavel que ira armazenar o indice do primeiro elemento a ser inserido na fila
    int fila[TAM_MAX]; //Definicao do dado que ira guardar os dados 
};

