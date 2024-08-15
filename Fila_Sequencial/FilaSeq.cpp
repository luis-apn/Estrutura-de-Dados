#include "FilaSeq.h"

//Construtor: Inicia todos os valores dos parametros zerados
FilaSeq::FilaSeq(){
    //Como o frente indica um espaco preenchido que esta na vez da fila, no inicio eh necessario utilizar o menos um para indicar comeco vazio da lista 
    frente =  0; 
    tras = 0;
}

//METODO QUE REPRESENTA SE A FILA ESTA VAZIA
bool FilaSeq::vazia(){
    
    //Quando ambos apontam para a mesma posicao, significa que a fila esta vazia
    if(frente == tras )
        return true;
    else
        return false;
}

//METODO QUE ADICIONA NO FINAL DA FILA
void FilaSeq::addFim(int valor){
    //Primeiro iremos verificar se a fila esta cheia pois n eh possivel inserir elementos em uma fila cheia
    if((tras+1)%TAM_MAX == frente)
        std::cout << "Erro: Fila esta Cheia\n";
    else{
        fila[tras] = valor; //-> Insere o valor no ultimo lugar da fila
        tras  = (tras + 1)%TAM_MAX; //-> Condicao para manter a circularidade, pois quando atingir o tamanho maximo que o vetor pode armazenar o tras eh zerado
    }

}

//METODO QUE REMOVE O ELEMENTO DO INICIO DA FILA (ORDEM DE PRIORIADADE)
int FilaSeq::removeInicio(){
    int valor;
    if(vazia()){
        std::cout << "Erro: Fila esta Vazia\n";
        return -1;
    }else{
        valor = fila[frente]; //-> Recebe o valor que sera lido retirado da fila pelo inicio
        frente = (frente + 1)%TAM_MAX; //-> Incrementa na frente com a condicao de circularidade
        return valor; //-> Retorna o valor para o usuario
    }
}

//METODO QUE RETORNA O ELEMENTO DO INICIO DA FILA
int FilaSeq::getInicio(){
    if(vazia()){
        std::cout << "Erro: Fila esta vazia\n";
        return -1;
    }
    else{
        return fila[frente];
    }
}


//METODO QUE VERIFICA SE A FILA ESTA CHEIA
bool FilaSeq::cheia(){
    if((tras+1)%TAM_MAX == frente){ 
        std::cout << "Erro: Fila esta Cheia\n";
        return true;
    }else  
        return false;
}


//METODO QUE IRA EXIBIR OS ELEMENTOS DA FILA
void FilaSeq::exibir(){

    std::cout << "Fila = [ ";
    for(int i=frente; i<tras; i++){
        if(i == (tras-1)){ 
            std::cout << fila[i] << " ]\n";
            break;
        }
        else
            std::cout << fila[i] << ", ";
    }
}