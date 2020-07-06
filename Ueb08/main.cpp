/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <iomanip>
#include "ProjectComponent.h"
#include "Task.h"
#include "ProjectDialogue.h"

using namespace std;


int main() {

    try {
        ProjectDialogue dialogue;
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
