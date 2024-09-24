#include "Grafo.h"

Grafo::Grafo()
{

}
//Ok
Grafo::Grafo(char arq[50]){
    ifstream arquivo;

    arquivo.open(arq);

    if(!arquivo.is_open()){
        perror("Erro arquivo.open()\n");
        exit(EXIT_FAILURE);
    }

    arquivo >> ordem;
    arquivo.close();

    strcpy(file, arq);
}
//Ok
void Grafo::matriz_adj_init(){
    fstream arq;
    int *lixo;
    lixo = new int;

    arq.open(file);

    if(!arq.is_open()){
        perror("Erro arquivo.open()\n");
        exit(EXIT_FAILURE);
    }

    arq >> *lixo;
    delete lixo;

    //Alocacao dinamica para a matriz de adjacencias
    matriz_adj = new int*[ordem];
    for(int i=0; i<ordem; i++)
        matriz_adj[i] = new int[ordem];

    //Recendo a matriz 
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            arq >> matriz_adj[i][j];
        }
    }

    arq.close();
}
//Ok
void Grafo::matriz_adj_exibir(){
    for(int i=0; i<ordem; i++){
        cout << "| ";
        for(int j=0; j<ordem; j++){
            cout << matriz_adj[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}
//Ok
void Grafo::lista_adj_init(){
    //Inicializa a lista a quantidade de vertice que ela possui
    lista_adj = new list<pair<int, int>>[ordem];
    int temp;

    //Leitura do arquivo e amarzena na lista de adjacencias
    matriz_adj_init();

    for(int i=0; i<ordem; i++){
        for(int j= 0; j<ordem; j++){
            temp = matriz_adj[i][j]; 
            if(temp != 0 ){
                lista_adj[i].push_back(make_pair(j, temp));
                //lista_adj[j].push_back(make_pair(i, temp));
            }
        }
    }
}
//Ok
void Grafo::lista_adj_exibir(){
    for(int i=0; i<ordem; i++){
        cout << "Vertice [" << i << "] -> " ;
        for(auto adj : lista_adj[i]){
            cout << adj.first << "(" << adj.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}
//Ok
void Grafo::bfs(int s, int d) {
    // Vetor booleano para marcar vértices visitados
    bool *visitados = new bool[ordem];
    for (int i = 0; i < ordem; i++) {
        visitados[i] = false;
    }

    // Vetor para armazenar os pais de cada vértice
    int *pai = new int[ordem];
    for (int i = 0; i < ordem; i++) {
        pai[i] = -1;  // -1 indica que o vértice não tem pai (ainda)
    }

    // Vetor para armazenar as distâncias dos vértices ao vértice inicial
    int *distancias = new int[ordem];
    
    // Fila para a busca
    FilaSeq queue;

    // Marca o vértice inicial como visitado e adiciona à fila
    visitados[s] = true;
    distancias[s] = 0;
    queue.addFim(s);

    //Algoritmo de busca em largura
    while (!queue.vazia()) {
        int atual = queue.removeInicio();//-> Remove do indice do vetor quem esta na vez da fila

        // Verifica se o vértice destino foi encontrado
        if (atual == d) {
            break;
        }

        for (auto vizinho : lista_adj[atual]) {
            if (!visitados[vizinho.first]) {
                visitados[vizinho.first] = true;
                distancias[vizinho.first] = distancias[atual] + vizinho.second;
                pai[vizinho.first] = atual;
                queue.addFim(vizinho.first);
            }
        }
    }

    // Reconstrução do caminho (se o destino foi encontrado)
    if (visitados[d]) {
        int vertice = d;
        vector<int> caminho;
        while (vertice != -1) {
            caminho.push_back(vertice);
            vertice = pai[vertice];
        }
        // Inverter o caminho para obter a ordem correta
        reverse(caminho.begin(), caminho.end());

        // Imprimir o caminho e a distância total
        cout << "Caminho { "<< s << " - " << d << " } (BSF): ";
        for (int i =0; i< caminho.size(); i++) {
            if(i == (caminho.size()-1)){
                cout << caminho[i];    
            }else
                cout << caminho[i] << " -> ";
        }
        cout << endl;
        cout << "Distancia total (BSF): " << distancias[d] << endl;
    } else {
        cout << "Nao existe caminho entre " << s << " e " << d << endl;
    }

    // Liberar a memória
    delete[] visitados;
    delete[] pai;
    delete[] distancias;
}
//oK
void Grafo::dfs(int s, int d){
    
    int v_atual; //Variavel para armazenar o vertice atual que esta sendo visitado
    stack<int> pilha; //Armazena os vertices visitados
    bool visitados[ordem]; //Armazena os vertices visitados 
    bool vizinho;
    int temp;
    int distancia_total =0, x=0;
    vector<int> caminho;
    bool validacao = false;
    
    for(int i=0; i<ordem; i++)
        visitados[i] = false;

    v_atual = s;
    caminho.push_back(s);

    while(true){
        //Se o vertice nao foi visitado
        if(!visitados[v_atual]){
            visitados[v_atual] = true; //marca como visitado
            pilha.push(v_atual); //empurra na pilha
        }
        vizinho = false;
        for(auto adj : lista_adj[v_atual]){
            if(!visitados[adj.first]){
                vizinho = true;
                temp = adj.first;
                break;
            }
        }
        //Atualiza o proximo a ser lido sendo o vizinho
        if(vizinho){ 
            v_atual = temp;
            caminho.push_back(temp);
        }
        //Caso nao seja encontrado nenhum vizinho para ser lido
        else{
            //Remove da pilha para ler
            caminho.pop_back();
            pilha.pop();
            //Caso a pilha estiver vazia, encerra o algoritmo
            if(pilha.empty())
                break;
            //caso nao esteja, atualiza para procurar nos adjacentes do top
            v_atual = pilha.top();
        }

        if(v_atual == d){
            cout << "Caminho { "<< s << " - " << d << " } (DSF): ";
            for(int i=0; i<caminho.size(); i++){
                if(i == (caminho.size()-1) )
                    cout << caminho[i] << endl;
                else
                    cout << caminho[i] << " -> ";
            }
            for(int i=0; i<(caminho.size() - 1); i++){
                distancia_total = distancia_total + matriz_adj[caminho[i]][caminho[i+1]];
            }
            cout << "Distancia total (DSF): " << distancia_total << endl;
            validacao = true;
            break;
        }
    }
    //Para indicar que nao houve caminho entre os vertices do grafo
    if(!validacao)
        cout << "Nao existe caminho entre " << s << " e " << d << endl;
}