#include <iostream>
#include "Example.h"
#include "ArticleTest.h"

void f(){

}

int main() {

    ArticleTest test;
    try {
        test.runFullTest();
    } catch (const string& e) {
        cout << e << endl;
    } catch (std::exception &e) {
        std::cout << "main: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "main error" << std::endl;

    }

/*    Example test2('c');
    auto* example = new Example();
    example->lol = 44;

    void (*fp)();
    fp = f;*/
    std::cout << "Hello, World! " << std::endl;
    return 0;
}
