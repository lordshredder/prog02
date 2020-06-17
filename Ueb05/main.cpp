/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */
#include <iostream>
using namespace std;

#include "LinList.h"
#include "LinkDialogue.h"

int main() {
    try {
        LinkDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }
    return 0;
}
