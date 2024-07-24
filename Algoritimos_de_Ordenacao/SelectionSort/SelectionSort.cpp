#include "SelectionSort.h"
#include <iostream>
#include <fstream>

//Exibir o conteudo do vetor
void show(double *v, int n){
    std::cout << "Vetor[ " << n << " ]" << std::endl;
    
    for(int i=0; i< n; i++){
        std::cout << "V [ "<< i << "]: " << v[i] << std::endl;
    }    
}

//Metodo de ordenacao
void SelectionSort(double *v, int n){
    double menor;
    double troca;
    int indice;

    for(int i=0; i<n; i++){
        menor = v[i];
        troca = v[i];
        for(int j=i+1; j<n; j++){
            if(menor > v[j]){ 
                menor = v[j];
                indice = j;
            }
        }
        if(menor != v[i]){ 
            v[i] = menor;
            v[indice] = troca;
        }
    }
}

void readFile(double *v, char file[50]){
    int i=0, lixo;
    
    std::ifstream arquivo;

    arquivo.open(file);

    if(!arquivo.is_open()){
        std::cout << "Error ao abrir o arquivo\n";
        return;
    }
    
    //Definindo a posicao do ponteiro do arquivo para o segundo
    arquivo >> lixo; //-> Pega esse valor para eliminar
    
    while (true)
    {
        
        if(arquivo.eof())
            break;
        arquivo >> v[i];
        //std::cout << "Valor do vetor: " << v[i] << std::endl;
        i++;
    
    }

    arquivo.close();    
}

int tamanho_vetor(char file[50]){
    std::ifstream arquivo;

    int size_vector;

    arquivo.open(file);

    if(!arquivo.is_open()){
        std::cout << "Error ao abrir o arquivo\n";
        return -1;
    }

    arquivo >> size_vector;
    arquivo.close();

    return size_vector;
}
