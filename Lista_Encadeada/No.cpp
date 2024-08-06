#include "No.h"

No::No(int v){
		this->v = v;
		this->prox = NULL;
}

int No::obterValor(){
		return v;
}

No* No::obterProx(){
		return prox;
}

void No::setProx(No* p){
		prox = p;
}