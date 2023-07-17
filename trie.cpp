//
// Created by Maurice on 14/07/2023.
//

#include "trie.h"
#include <stdio.h>
#include <iostream>

int findSizeString(char* input){
    int i =0;
    while(input[i++] != '\0'){
    }
    return i;
}



root::root() {
    this->start = nullptr;
}

void root::print() {
    start->print();
}

void* root::find(char *input) {
    return (start== nullptr? nullptr:start->find(input));
}

void root::add(char input[],void (*funcP)()) {
    if(start== nullptr){
        std::cout<<input << "test \n";
        this->start = new branch(input,funcP);
        return;
    }

    start->add(input,funcP);
}

branch::branch(char *input, void(*funcP)()) {
    this->value = input[0];
    if(input[1] != '\0')
        this->child = new branch(&input[1], funcP);
    else
        this->funcP = funcP;
}

void branch::add(char *input,void (*funcP)()) {
    //std::cout << input[0] << " " << this->value << std::endl;
    if(input[0] != this->value){
        if(this->next != nullptr)
            this->next->add(input,funcP);
        else
            this->next = new branch(input,funcP);
    }

    if(input[1] != '\0'){
        this->child->add(&input[1], funcP);
    }
    else
        this->funcP = funcP;
}


void branch::print() {
    std::cout << value;
    if(next != nullptr)
        next->print();
;

    if(child != nullptr)
        child->print();
    else
        std::cout << "\n";
}

void(*func) branch::find(char *input) {
    if(input[0] == value) {
        if (input[1] == '\0' && this->funcP != nullptr)
            return this->funcP;
        else
            return (this->child == nullptr? nullptr : this->child->find(&input[1]));
    }
    return (this->next == nullptr ? nullptr : this->next->find(input));
}



