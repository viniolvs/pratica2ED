#include "modulo.hpp"
#include <iostream>

using namespace std;

List::List(){
    this->first = nullptr;
    this->last = nullptr;
    this->length = 0;
}

List::~List(){

}

int List::len(){
    return this->length;
}

bool List::empty(){
    return this->length==0;
}

void List::print(){
    Node *aux = first;
    for (int i = 0; i < len(); i++, aux = aux->next)
        cout << aux->info << " ";
    cout << endl;
}

bool List::pushFront(Data data){
    Node *node = new Node;
    node->info = data;
    node->next = nullptr;

    if(empty()){
        this->first = node;
        this->last = node;
    }
    else{
        node->next = this->first;
        this->first = node;
    }
    this->length++;
    return true;
}

bool List::pushBack(Data data){
    Node *node = new Node;
    node->info = data;
    node->next = nullptr;

    if(empty()){
        this->first = node;
        this->last = node;
    }
    else{
        this->last->next = node;
        this->last = node;
    }
    this->length++;
    return true;
}

Data List::popFront(){
    
}

Data List::popBack(){

}