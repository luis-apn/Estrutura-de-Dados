#include "Lista.h"

Lista::Lista(){
	cabeca = NULL;
	cauda = NULL;
}

Lista::Lista(int v){
	cabeca = new No(v);
	cauda = cabeca;
}

Lista::~Lista(){
	delete cabeca;
}

void Lista::mostrar(){
                cout << "\nImprimindo todos os elementos...\n";
                No* c = cabeca;

                if(vazia())
                    cout << "A lista NAO possui elementos!!\n";
                else
                {
                    while(c) // percorre a lista
                    {
                        cout << c->obterValor() << endl;
                        c = c->obterProx();
                    }
                    cout << endl;
                }
}

bool Lista::vazia() 
	{
		return (cabeca == NULL);
	}

void Lista::inserir_inicio(int v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->setProx(cabeca);
			cabeca = novo_no;
		}
}

void Lista::inserir_final(int v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

int Lista::tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
}

bool Lista::existe(int v)
	{
		No* c = cabeca;
		
		while(c)
		{
			if(c->obterValor() == v)
				return true;
			c = c->obterProx();
		}
		return false;
	}

void Lista::remover()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(cabeca->obterProx() == NULL)
				cabeca = NULL;
			else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
				cabeca->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = cabeca;
				No* ant = cabeca->obterProx();
				No* corrente = cabeca->obterProx()->obterProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			}
		}
	}