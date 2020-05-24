#include <iostream>
#include "StorageDialogue.h"

int main() {
    try {
        StorageDialogue dialogue;
        dialogue.startDialogue();
    } catch (const string& e) {
        cout << e << endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch(...){
        std::cout << "FATAL ERROR" << endl;
    }
    return 0;
}
