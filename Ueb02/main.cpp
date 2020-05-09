#include <iostream>
#include "Example.h"

void f(){

}

int main() {

    Example test2('c');
    auto* example = new Example();
    example->lol = 44;

    void (*fp)();
    fp = f;
    std::cout << "Hello, World! " << example->lol<< std::endl;
    return 0;
}
