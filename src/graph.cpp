#include "graph.hpp"
#include <iostream>

using namespace std;

//construtor: aloca a memória para os vértices
//tamanho inicializado em 0 e todos os rótulos (0 a n-1) inseridos
Graph::Graph(int n){
    vertices = (Vertice *) malloc(n * sizeof(Vertice));
    tamanho = 0;

    for(int i = 0; i < n; i++){
        vertices[i].rotulo = i;
        tamanho++;
    }
}

//aloca memória para os vizinhos de determinado vértice
//incializa n_vizinhos e seta max_vizinhos
void Graph::InicializaVizinhos(int v, int n){
    //testa se o número de vizinhos está no intervalo possível de 0 a n-1
    if(n > tamanho-1 || n < 0){
        NumVizinhosInvalido e;
        cerr << "Número de vizinhos inválido." << endl;
        throw e;
    }
    vertices[v].max_vizinhos = n;
    vertices[v].vizinhos = (int *) malloc(n * sizeof(int));
    vertices[v].n_vizinhos = 0;
}

//insere um vizinho no array de vizinhos de um determinado vértice
//incrementa o n_vizinhos deste vértice
void Graph::InsereVizinho(int v, int x){
    //testa se o vizinhos inserido é vértice existente
    if(x >= tamanho || x < 0){
        VerticeInvalido e;
        cerr << "Número de vértice inválido." << endl;
        throw e;
    }  
    //testa se o n_vizinhos já chegou ao máximo fornecido pela entrada
    if(vertices[v].n_vizinhos == vertices[v].max_vizinhos){
        NumVizinhosInvalido e;
        cerr << "O vértice " << v << " já possui todos os vizinhos." << endl;
        throw e;
    }
    vertices[v].vizinhos[vertices[v].n_vizinhos] = x;
    vertices[v].n_vizinhos++;
}

//retorna o array de vizinhos do vértice
int* Graph::GetVizinhos(int v){
    return this->vertices[v].vizinhos;
}

//retorna o número de vizinhos do vértice
int Graph::GetNumVizinhos(int v){
    return this->vertices[v].n_vizinhos;
}

//insere uma cor para o vértice
void Graph::SetCor(int v, int c){
    vertices[v].cor = c;
}

//retorna a menor cor do grafo
int Graph::MenorCor(){
    int m = vertices[0].cor;
    for(int i = 1; i < tamanho; i++){
        if(vertices[i].cor < m){
            m = vertices[i].cor;
        }
    }
    return m;
}

//retorna a cor do vértice
int Graph::GetCor(int v){
    return this->vertices[v].cor;
}

//retorna a quantidade de vértices do grafo
int Graph::GetTamanho(){
    return this->tamanho;
}

//destrutor: desaloca a memória dos vértices e dos vizinhos de cada um
Graph::~Graph(){
    for(int i = 0; i < tamanho; i++){
        free(vertices[i].vizinhos);
    }
    free(vertices);
}