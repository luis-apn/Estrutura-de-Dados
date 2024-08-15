#include "FilaSeq.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(){

    srand(time(NULL));
    int valor;
    int elemento;

    //Criacao do objeto do meu tipo fila
    FilaSeq fila, fCheia;

    //TESTE DO METODO VAZIA - PRIMEIRA CONDICAO
    if(fila.vazia())
        cout << "A FILA ESTA VAZIA" << endl << endl;
    else 
        cout << "A FILA NAO ESTA VAZIA" << endl << endl;
    
    //TESTE DO METODO CHEIA - PRIMEIRA CONDICAO
    if(fila.cheia())
        cout << "A FILA ESTA CHEIA" << endl << endl;
    else
        cout << "A FILA NAO ESTA CHEIA" << endl << endl;

    //TESTE DO METODO DE ADICAO NO FIM DA FILA
    cout <<  "ADICIONANDO ELEMENTOS NO FIM DA LISTA\n";
    for(int i=0; i<10; i++){
        valor = rand()%20 + 1;
        cout << "Valor(" << i << ") = " << valor << endl;
        fila.addFim(valor);
    }  
    fila.exibir();

    //TESTE DO METODO DE REMOCAO DO INICIO DA FILA
    cout << endl << "REMOVENDO ELEMENTOS PELA ORDEM DE ADICAO\n";
    for(int i=0; i<3; i++){   
        elemento = fila.removeInicio();
        cout << "ELEMENTO REMOVIDO = " << elemento << endl;
        fila.exibir();
        sleep(2);
    }

    //TESTE DO METODO DE LEITURA DO PRIMEIRO ELEMENTO DA FILA
    cout << endl << "PRIMEIRO ELEMENTO DA FILA = " << fila.getInicio() << endl << endl;

    //TESTE DO METODO VAZIA - SEGUNDA CONDICAO
    if(fila.vazia())
        cout << "A FILA ESTA VAZIA" << endl << endl;
    else 
        cout << "A FILA NAO ESTA VAZIA" << endl << endl;

    //TESTE DO METODO CHEIA - SEGUNDA CONDICAO
    for( int i = 0; i <= 98 ; i++){
        valor = rand()%100;
        fCheia.addFim(valor);
    }
    if(fCheia.cheia())
        cout << "A FILA ESTA CHEIA" << endl << endl;
    else
        cout << "A FILA NAO ESTA CHEIA" << endl << endl; 

    return 0;
}