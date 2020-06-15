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
/*    LinList liste1;
    liste1.push_back("alpha");
    liste1.push_back("beta");
    liste1.push_back("34423423cgdg");
    liste1.push_front("lol");
    liste1.push_back("AAAAAAAAAAA");
    liste1.push_back("dfkshfhsjfh");
    cout << liste1 << endl;
    liste1.insert(15, "vor beta");
    cout << liste1 << endl;
    liste1.erase(5);
    cout << liste1 << endl;*/
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
