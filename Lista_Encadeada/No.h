#pragma once
#include <iostream>

using namespace std;

// classe No
class No
{
private:
	int v;
	No* prox;
public:
	No(int v);
	int obterValor();
    No* obterProx();
    void setProx(No* p);
};