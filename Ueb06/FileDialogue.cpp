/**
 *
 *  @file FileDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 02.06.2020
 */

#include "FileDialogue.h"
#include <string>
using namespace std;

const string FileDialogue::BAD_USER_INPUT = "Invalid input.";

FileDialogue::FileDialogue(FileAnalyzer& analyzer) {
    this->analyzer = &analyzer;
}

FileDialogue::~FileDialogue() {
    delete analyzer;
}

void FileDialogue::startDialogue() {
    while (currentSelection != SELECT_QUIT) {
        try {
            readUserSelection();
            executeSelection(currentSelection);
        } catch (const string& e) {
            clearUserInput();
            cout << "\nERROR: " << e << "\n";
        } catch (std::exception &e) {
            clearUserInput();
            cout << e.what() << std::endl;
        } catch (...) {
            clearUserInput();
            cout << "\nSomething went terribly wrong." << endl;
        }
    }
    cout << "Goodbye." << endl;
}

void FileDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
         << SELECT_SHOW_LIST << " : Show the current analyzer\n"
         << SELECT_SHOW_LIST_COUNT << " : Show the current analyzer count\n"
         << SELECT_PUSH_BACK << " : Append new item(s) at the end\n"
         << SELECT_PUSH_FRONT << " : Append new item at the start\n"
         << SELECT_POP_BACK << " : Remove last item\n"
         << SELECT_POP_FRONT << " : Remove first item\n"
         << SELECT_INSERT << " : Insert item at position\n"
         << SELECT_ERASE << " : Remove item at position\n"
         << SELECT_CLEAR << " : Clear analyzer\n"
         << SELECT_AT << " : Test operator[ ]\n"
         << SELECT_CONCATENATE_LISTS << " : Concatenate analyzer\n"
         << SELECT_APPEND_LIST << " : Append analyzer\n"
         << SELECT_LIST_EQUAL << " : Check equality\n"
         << SELECT_SET_LIST << " : Test operator=\n"
         << SELECT_CREATE_DUMMY_ARTICLES << " : Create random articles for testing purposes\n"
         << SELECT_QUIT << " : Quit\n";
    if (safeRead(cin, selection)) {
        currentSelection = static_cast<Select>(selection);
    } else{
        throw BAD_USER_INPUT;
    }
}

void FileDialogue::executeSelection(const Select& selection) {
    if (selection == SELECT_QUIT) return;
    switch (currentSelection) {
        case SELECT_SHOW_LIST:
            break;
        default:
            throw BAD_USER_INPUT;
    }

}

void FileDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}
