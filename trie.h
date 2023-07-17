//
// Created by Maurice on 14/07/2023.
//

#ifndef TREI_TRIE_H
#define TREI_TRIE_H

struct root;
struct leaf;
struct branch;

struct branch{
    branch *next;
    branch *child;
    void* (*funcP)();

    char value;

    branch(char *input, void (*funcP)());
    void add(char *input, void (*funcP)());

    void print();
    void(*func)() find(char *input);
};

struct root{
    branch *start;
    void add(char data[],void (*funcP)());
    void print();
    ptr find(char input[]);

    root();
};




struct leaf:branch{


};



#endif //TREI_TRIE_H
