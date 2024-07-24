#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include "InsertionSort.h"

int main(int argc, char *argv[]){

    srand(time(NULL));

    int tamanho;
    double *vetor;
    clock_t tempo_exec;

    tamanho = tamanho_vetor(argv[1]);

    vetor = new double[tamanho];

    readFile(vetor, argv[1]);
    
    tempo_exec = clock();
    InsertionSort(vetor, tamanho);
    tempo_exec = clock() - tempo_exec;

    std::cout << "\n\nVetor Ordenado\n";
    
    show(vetor, tamanho);

    delete vetor;
    
    std::cout << "\nTempo de Execucao em segundos: " << (((float)tempo_exec)/CLOCKS_PER_SEC) << " s\n";
    return 0;
}
