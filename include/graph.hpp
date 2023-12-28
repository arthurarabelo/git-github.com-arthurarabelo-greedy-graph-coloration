#ifndef GRAPH_HPP
#define GRAPH_HPP

typedef struct s_subset{

    int rotulo;
    int cor;
    int *vizinhos;
    int n_vizinhos;
    int max_vizinhos;

    //sobrecarga do operador maior para o vértice
    //sobrecarga do operador menor para o vértice: compara as cores
    //se estas forem iguais compara o rotulo
    bool operator > (s_subset& v2){
        if(cor > v2.cor) return true;
        else if(cor == v2.cor && rotulo > v2.rotulo) return true;
        return false; 
    }

    //sobrecarga do operador menor para o vértice: compara as cores
    //se estas forem iguais compara o rotulo
    bool operator < (s_subset& v2){
        if(cor < v2.cor) return true;
        else if(cor == v2.cor && rotulo < v2.rotulo) return true;
        return false; 
    }

  
} Vertice;

class Graph{

    public:
        Graph(int n);
        ~Graph();

        void InicializaVizinhos(int v, int n);
        void InsereVizinho(int v, int x);
        int GetNumVizinhos(int v);
        int* GetVizinhos(int v);

        void SetCor(int v, int c);
        int GetCor(int v);
        int MenorCor();

        int GetTamanho();

        struct NumVizinhosInvalido{};
        struct VerticeInvalido{};

    private:  
        int tamanho;
        Vertice *vertices;
};


#endif