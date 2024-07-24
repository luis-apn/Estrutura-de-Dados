#include "InsertionSort.h"
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
void InsertionSort(double *v, int n){

    double temp;

    for(int i=0; i<n; i++){
        for(int j=i+1; j>=0; j--){
            if(j == n)
                break;
            else if(v[j-1] > v[j]){
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
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
