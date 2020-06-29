/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#include <iostream>
#include <memory>
#include "StorageDialogue.h"

int main() {
    try {
        StorageDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }
    return 0;
}
