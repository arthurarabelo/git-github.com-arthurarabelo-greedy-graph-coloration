#ifndef SORT_HPP
#define SORT_HPP

#include "graph.hpp"

//bolha
void Bolha(Vertice *v, int n);

//seleção
void Selecao(Vertice *v, int n);

//inserção
void Insercao(Vertice *v, int n);

//quicksort
void Particao(int Esq, int Dir, int *i, int *j, Vertice *v);
void Ordena(int Esq, int Dir, Vertice *v);
void QuickSort(Vertice *v, int n);

//mergesort
void Merge(Vertice *v, int l, int m, int r);
void MergeSort(Vertice *v, int l, int r);

//heapsort
void Heapify(Vertice *v, int n, int i);
void Heapsort(Vertice *v, int n);

//mysort
void MySort(Vertice *v, int n);

#endif
