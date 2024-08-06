#pragma once
#include "No.h"

// classe Lista
class Lista
{
private:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento

public:
	Lista();
    Lista(int v);
    virtual ~Lista();
	void mostrar();
	bool vazia();
	void inserir_inicio(int v);
	void inserir_final(int v);
    int tamanho();
	bool existe(int v);
	void remover();
};