#include "list.hpp"
#include <iostream>

using namespace std;

List::List(){
    this->first = nullptr;
    this->last = nullptr;
    this->length = 0;
}

List::~List(){
    if(empty())
        return;
    Node *aux = this->first, *p;
    while (aux != nullptr)
    {
        p = aux;
        aux = aux->next;
        delete[] p;
    }
}

int List::len(){
    return this->length;
}

bool List::empty(){
    return this->length==0;
}

void List::print(){
    if(this->empty())
        return;
    Node *aux = first;
    for (int i = 0; i < len(); i++, aux = aux->next)
        cout << aux->info << " ";
    cout << endl;
}

bool List::pushFront(Data data){
    Node *node = new Node;
    if(node==nullptr)
        return false;
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
    if(node==nullptr)
        return false;
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

bool List::popFront(){
    if(empty())
        return false;
    Node *aux = this->first;
    this->first = aux->next;
    this->length--;
    delete[] aux;
    return true;
}

bool List::popBack(){
    if(empty())
        return false;
    Node *aux = this->first;
    for(int i = 0 ; i < this->len() - 1 ; i++)
        aux = aux->next;
    this->last = aux;
    this->last->next = nullptr;
    this->length--;
    delete[] aux->next;
    return true;
}

bool List::search(Data data){
    if(empty())
        return false;
    Node *aux = this->first;
    for(int i ; i < this->len() ; i++){
        if(aux->info == data)
            return true;
        aux = aux->next;
    }
    return false;
}

Data List::at(int pos){
    if((this->empty()) || (pos >= this->len())){
        cerr << "Invalid position" << endl;
        return -1;
    }
    Node *aux = this->first;
    for (int i = 0; i < pos; i++)
        aux = aux->next;
    return aux->info;
}