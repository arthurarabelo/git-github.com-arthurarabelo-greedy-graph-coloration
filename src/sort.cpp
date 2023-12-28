#include "sort.hpp"
#include "iostream"
#include "linkedList.hpp"

void Bolha(Vertice *v, int n){
    int i;
    int j;
    int trocou;
    Vertice aux;

    for(i = 0; i < n-1; i++){
        trocou = 0;
        for(j = 1; j < n-i; j++){
            if (v[j] < v[j-1]){ 
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
                trocou = 1;
            } 
        }
        if (!trocou) break;
    } 
}


void Selecao(Vertice *v, int n){
    int i, j, min;
    Vertice aux;

    for (i = 0; i < n - 1; i++){ 
        min = i;
        for (j = i + 1 ; j < n; j++){
            if (v[j] < v[min]){
                min = j;                
            }
        }
    aux = v[i];
    v[i] = v[min];
    v[min] = aux;
    }
}


void Insercao(Vertice *v, int n){
    int i,j;
    Vertice aux;
    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (( j >= 0 ) && (aux < v[j])){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}


void Particao(int Esq, int Dir, int *i, int *j, Vertice *v){
    Vertice x, w;
    *i = Esq;
    *j = Dir;
    x = v[(*i + *j)/2]; // obtém o pivô x
    do
    { 
        while (x > v[*i]) (*i)++;
        while (x < v[*j]) (*j)--;
        if (*i <= *j){ 
            w = v[*i]; 
            v[*i] = v[*j]; 
            v[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Vertice *v){
    int i, j;
    Particao(Esq, Dir, &i, &j, v);
    if (Esq < j) Ordena(Esq, j, v);
    if (i < Dir) Ordena(i, Dir, v);
}

void QuickSort(Vertice *v, int n){ 
    Ordena(0, n-1, v); 
}


void Merge(Vertice *v, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;    
       
    Vertice *a = new Vertice[n1];
    Vertice *b = new Vertice[n2];
       
    for(int i = 0; i < n1; i++){   
        a[i] = v[l+i];
    }
       
    for(int i = 0 ; i<n2 ; i++){
        b[i] = v[i+m+1];
    }

    int i = 0;
    int j = 0;
    int k = l; 
    while((i < n1) && (j < n2)){       
        if(a[i] < b[j]){
            v[k] = a[i];
            i++;
        }  
        else{
            v[k] = b[j];
            j++;
        }
        k++;
    }
       
    while(i<n1){       
        v[k] = a[i];
        i++;
        k++;
    }
       
    while(j < n2){   
        v[k] = b[j];
        j++;
        k++; 
    }

    delete [] a;
    delete [] b;   
}

void MergeSort(Vertice *v, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSort(v , l , mid);
        MergeSort(v , mid+1 , r);
        Merge(v , l , mid , r);
    }
}

void Heapify(Vertice *v, int n, int i){
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[max]){
        max = l;
    }
 
    if (r < n && v[r] > v[max]){
        max = r;
    }

    Vertice aux;
    if (max != i) {
        aux = v[i];
        v[i] = v[max];
        v[max] = aux;
        Heapify(v, n, max);
    }
}

void Heapsort(Vertice *v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        Heapify(v, n, i);
    }
 
    Vertice aux;
    for (int i = n - 1; i > 0; i--) {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        Heapify(v, i, 0);
    }
}


void MySort(Vertice *v, int n){
    LinkedList list;

    //insere elementos na lista de acordo com as cores e os rótulos dos vértices do grafo
    for(int i = 0; i < n; i++){
        list.Insert(v[i].rotulo, v[i].cor);
    }

    Node* aux = list.head->next;
    int i = 0;
    //percorre lista substituindo as cores e os rótulos dos vértices do grafo pelos dos elementos da lista
    //no fim do loop, os vértices estão ordenados nos atributos de cor e rótulo
    while(aux != NULL){
        v[i].cor = aux->cor;
        v[i].rotulo = aux->rotulo;
        aux = aux->next;
        i++;
    }
}

