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

    int i, j;
    double temp;
    for (i = 1; i < n; i++) {
        temp = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > temp) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
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
