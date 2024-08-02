#pragma once
#define TAM_MAX 20 //-> O tamanho maximo da lista pode ser definido de forma arbitraria
#include <iostream>

//Criando um template para as variaveis sere definidas de forma arbitrarias, sem a necessidade de um definicao de um tipo estatico
template<class Temp> class Lista
{
private:
    
    //Conjunto de variaveis para a lista
    Temp *dados; 
    int tam_atual; 
    int t_max; 

public:
    
    //METODO CONSTRUTOR DA LISTA
    Lista(){
        t_max = TAM_MAX;
        dados = new Temp[t_max];
        tam_atual = 0;
    }

    //METODO QUE VERIFICA SE A LISTA ESTA VAZIA
    bool vazia(){
        if(tam_atual == 0)
            return true;
        else
            return false;
    }

    //METODO QUE VERIFICA SE A LISTA ESTA CHEIA
    bool cheia(){
        if(tam_atual == t_max)
            return true;
        else
            return false;
    }

    //METODO QUE RETORNA O TAMANHO DA LISTA 
    int tamanho(){ 
        return tam_atual;
    }

    //METODO QUE RETORNA O ELEMENTO NA POSICAO DETERMINADA
    Temp elemento(int posicao){
        Temp dado;
        
        if((posicao > tam_atual) || posicao <= 0)
            return -1;
        
        dado = dados[posicao - 1];
        return dado;
    }

    //METODO QUE RETORNA A POSICAO DO ELEMENTO ENVIADO
    int posicao(Temp dado){
        
        for(int i=0; i<tam_atual; i++){
            if(dados[i] == dado)
                return (i+1); 
        }
        return -1; 
    }

    //METODO QUE INSERE UM VALOR NA POSICAO DEFINIDA
    bool inserir(int posicao, Temp dado){
        
        if(cheia() || (posicao > tam_atual + 1) || (posicao <= 0))
            return false;
        
        for(int i = tam_atual; i >= posicao; i--)
            dados[i] = dados[i-1]; 

        tam_atual++; 
        dados[posicao - 1] = dado; 
        return true;
    }    

    //METODO QUE REMOVE DA POSICAO DEFINICA DE RETORNA O VALOR REMOVIDO PARA O USUARIO
    Temp remover(int posicao){
        Temp dado;

        if((posicao > tam_atual) || (posicao <= 0))
            return false;

        dado = dados[posicao - 1]; 
        
        for(int i=posicao - 1 ; i < tam_atual; i++)
            dados[i] = dados[i+1];

        tam_atual--; 
        return dado;
    }

    void exibir(){
        std::cout << "List[" << tam_atual << "] = [ ";
        for(int i=0; i<tam_atual; i++){
            if(i == tam_atual - 1){
                std::cout << dados[i] << " ]\n";
                break;
            }else{
                std::cout << dados[i] << " ,";
            
            }
        }
    }
};



