/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#include <iostream>
#include "StorageDialogue.h"

int main() {
    try {
        StorageDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cout << e << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch(...){
        std::cout << "FATAL ERROR" << std::endl;
    }
    return 0;
}
