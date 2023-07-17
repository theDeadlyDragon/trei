#include <iostream>
#include "trie.h"

void printHello(){
    std::cout << "hello" << std::endl;
}

int main() {

    root *test = new root();


    int a =0;
    int b =10;
    int x =20;



    test->add("test1",&printHello);
    test->add("tes",&printHello);

    test->add("abc",&b);

    test->add("dom",&x);

    void* function =test->find("tes");

    test->print();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
