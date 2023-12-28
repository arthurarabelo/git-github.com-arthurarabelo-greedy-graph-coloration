#include "linkedList.hpp"
#include <iostream>

using namespace std;

//construtor: inicializa a célula head e atribui seu valor a tail
LinkedList::LinkedList(){
    head = new Node;
    tail = head;
}

//insere um node na lista assim que encontra um node maior
//a cor e o rótulo do node são passados como parâmetro
void LinkedList::Insert(int r, int c){
    int helper = 0;
    Node* newNode = new Node; 
    newNode->rotulo = r;
    newNode->cor = c;

    //testa se a lista está sem nenhum elemento
    //se sim, insere o node na primeira posição após o cabeçalho
    if (head->next == NULL) {
        head->next = newNode;
        newNode->prev = head;
        tail = newNode; 
        return;
    }

    //percorre a lista até achar um node que seja maior que o que será inserido
    //se a condição é verdadeira, os ponteiros são organizados de forma a a estruturar a lista com o novo elemento
    Node* temp = head->next; 
    while (temp != NULL){
        if(helper) break;
        if(*newNode < *temp){
            newNode->next = temp;
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            helper = 1;
        } 
        temp = temp->next;
    }

    //se a variável helper não foi atualizada para 1, então não há um node maior que o newNode
    //sendo assim, ele é inserido no final da lista
    if(!helper){
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

//destrutor: deleta a memória para cada node da lista
LinkedList::~LinkedList(){
    Node* n = head;
    Node* prox;
    while(n != NULL){
        prox = n->next;
        delete n;
        n = prox;
    }
}