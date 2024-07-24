#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

//Funcao para mostrar o vetor
void show(double *v, int n);

//Metodo de ordenacao
void InsertionSort(double *v, int n);

//Conversao do arquivo .in para o vetor
void readFile(double *v, char file[50]);

int tamanho_vetor(char file[50]);

#endif 
