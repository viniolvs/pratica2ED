#include "queue.hpp"
#include <iostream>

Queue::Queue(){}
Queue::~Queue(){}

int Queue::size(){
    return this->len();
}

bool Queue::insert(Data data){
    return this->pushBack(data);
}

bool Queue::remove(){
    return this->popFront();
}

bool Queue::emptyQueue(){
    return this->empty();
}

void Queue::printQueue(){
    this->print();
}

Data Queue::getFirst(){
    return this->at(0);
}
Data Queue::getLast(){
    return this->at(this->len()-1);
}