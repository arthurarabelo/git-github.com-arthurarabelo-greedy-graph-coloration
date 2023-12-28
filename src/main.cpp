#include <iostream>
#include "sort.hpp"
#include "graph.hpp"
#include <string>

using namespace std;

//retorna true se um inteiro está no array v
bool Find(int x, int *v, int n){
    for(int i = 0; i < n; i++){
        if(v[i] == x) return 1;
    }
    return 0;
}

//função booleana que diz a coloração do grafo é gulosa ou não
bool isGreedy(Graph* g){
    int min_color = g->MenorCor();
    int *v;
    int c;
    //a variável 'a' é incrementada sempre que um vértice cumpre as condições de gulosidade
    int a = 0;
    //se a cor mínima for maior que 1, então a coloração necessariamente não é gulosa
    if(min_color > 1) {
        return 0;
    }    
    //loop que percorre os vértices do grafo
    for(int i = 0; i < g->GetTamanho(); i++){
        c = g->GetCor(i);
        //se a cor do vértice for a cor mínima, o loop continua
        if(c == min_color){ 
            a++;
            continue;
        }
        int colors[c-1];
        //loop que armazena em colors todas as cores de 1 até c
        for(int k = 1; k < c; k++){
            colors[k-1] = k;
        }
        int helper = 0;
        int *anteriores = (int *) calloc(g->GetNumVizinhos(i), sizeof(int));
        v = g->GetVizinhos(i); 
        //loop que percorre os vizinhos de cada vértice
        for(int j = 0; j < g->GetNumVizinhos(i); j++){
            int c_vizinho = g->GetCor(v[j]);
            //testa se a cor do vizinho é menor do que c
            //verifica se a cor do vizinho já está inserida no array anteriores (para evitar repetição)
            //verifica se a cor do vizinho está em colors
            if((c_vizinho < c) && (!Find(c_vizinho, anteriores, g->GetNumVizinhos(i))) && Find(c_vizinho, colors, c-1)){
                //se as condições são satisfeitas, a cor do vizinho é inserida em anteriores e a helper é incrementada
                anteriores[j] = c_vizinho;
                helper++;
            }
        }
        //se helper for igual a quantidade de cores de 1 até c, a variável a é incrementada
        if(helper == c-1){
            a++;
        }
        free(anteriores);
    }
    //se a é incrementado para todos os vértices, então a coloração é gulosa
    if(a == g->GetTamanho()){
        return 1;
    }
    return 0;
}

int main(){
    
    char sort;
    int qnt_vertices;
    cin >> sort;
    cin >> qnt_vertices;

    Graph grafo(qnt_vertices);
    Vertice vertices[qnt_vertices];

    int num_vizinhos;
    int vizinho;
    //loop que seta os rótulos dos vértices, inicializa e insere os vizinhos
    for(int i = 0; i < qnt_vertices; i++){
        vertices[i].rotulo = i;
        cin >> num_vizinhos;
        grafo.InicializaVizinhos(i, num_vizinhos);

        for(int j = 0; j < num_vizinhos; j++){
            cin >> vizinho;
            grafo.InsereVizinho(i, vizinho);
        }
    }

    int cor;
    int k = 0;
    while(cin >> cor){
        vertices[k].cor = cor;
        grafo.SetCor(k, cor);
        k++;
        if(k == qnt_vertices) break;
    }

    switch (sort)
    {
        case 'b':
            Bolha(vertices, qnt_vertices);
            break;
        case 's':
            Selecao(vertices, qnt_vertices);
            break;
        case 'i':
            Insercao(vertices, qnt_vertices);
            break;
        case 'q':
            QuickSort(vertices, qnt_vertices);
            break;    
        case 'm':
            MergeSort(vertices, 0, qnt_vertices-1);
            break;
        case 'p':
            Heapsort(vertices, qnt_vertices);
            break;
        case 'y':
            MySort(vertices, qnt_vertices);
            break;
        default:
            throw runtime_error("Método de ordenação inválido.");
    }

    bool is_greedy = isGreedy(&grafo);

    if(is_greedy){
        cout << is_greedy << " ";
        for(int i = 0; i < qnt_vertices; i++){
            if(i == qnt_vertices-1){
                cout << vertices[i].rotulo << endl;
                break;
            }
            cout << vertices[i].rotulo << " ";
        }
    }
    if(!is_greedy) {
        cout << is_greedy << endl;
    } 
}