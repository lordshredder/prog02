#include <iostream>
#include "Example.h"

void f(){

}

int main() {

    Example test2('c');
    Example* example = new Example();
    Example eexample();
    example->lol = 44;

    void (*fp)();
    fp = f;
    std::cout << "Hello, World! " << example->lol<< std::endl;
    return 0;
}
