#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

using namespace std;

//class node: define o item da lista encadeada e seus atributos
//esta classe simula um vértice
class Node{
    public:
        int rotulo;
        int cor;
        Node* next;
        Node* prev;

    //construtor: inicializa os atributos do node com valores padrão
    Node(){
        cor = -1;
        rotulo = -1;
        next = NULL; 
        prev = NULL;
    }

    //sobrecarga de operador maior para o node
    bool operator > (Node& v2){
        if(cor > v2.cor) return true;
        else if(cor == v2.cor && rotulo > v2.rotulo) return true;
        return false; 
    }

    //sobrecarga de operador menor para o node
    bool operator < (Node& v2){
        if(cor < v2.cor) return true;
        else if(cor == v2.cor && rotulo < v2.rotulo) return true;
        return false; 
    }
};

class LinkedList{
    public:
        //head é uma célula que serve de cabeçalho para a lista
        Node* head;
        Node* tail;

        LinkedList();
        void Insert(int r, int c);
        ~LinkedList();
};

#endif