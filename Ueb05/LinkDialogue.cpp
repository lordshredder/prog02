/**
 *
 *  @file LinkDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 02.06.2020
 */

#include "LinkDialogue.h"
#include "MockInput.h"
#include <string>
using namespace std;

const string LinkDialogue::BAD_USER_INPUT = "Invalid input.";

LinkDialogue::LinkDialogue() {
    createList();
}

LinkDialogue::~LinkDialogue() {
    delete list;
}

void LinkDialogue::startDialogue() {
    while (currentSelection != SELECT_QUIT) {
        try {
            readUserSelection();
            executeSelection(currentSelection);
            showList();
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

void LinkDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
            << SELECT_SHOW_LIST << " : Show the current list\n"
            << SELECT_SHOW_LIST_COUNT << " : Show the current list count\n"
            << SELECT_PUSH_BACK << " : Append new item(s) at the end\n"
            << SELECT_PUSH_FRONT << " : Append new item at the start\n"
            << SELECT_POP_BACK << " : Remove last item\n"
            << SELECT_POP_FRONT << " : Remove first item\n"
            << SELECT_INSERT << " : Insert item at position\n"
            << SELECT_ERASE << " : Remove item at position\n"
            << SELECT_CLEAR << " : Clear list\n"
            << SELECT_AT << " : Test operator[ ]\n"
            << SELECT_CONCATENATE_LISTS << " : Concatenate list\n"
            << SELECT_APPEND_LIST << " : Append list\n"
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

void LinkDialogue::executeSelection(const Select& selection) {
    if (selection == SELECT_QUIT) return;
    switch (currentSelection) {
        case SELECT_SHOW_LIST:
            showList();
            break;
        case SELECT_SHOW_LIST_COUNT:
            showListCount();
            break;
        case SELECT_PUSH_BACK:
            pushBack();
            break;
        case SELECT_PUSH_FRONT:
            pushFront();
            break;
        case SELECT_POP_BACK:
            popBack();
            break;
        case SELECT_POP_FRONT:
            popFront();
            break;
        case SELECT_INSERT:
            insertItem();
            break;
        case SELECT_ERASE:
            eraseItem();
            break;
        case SELECT_CLEAR:
            clear();
            break;
        case SELECT_AT:
            testAt();
            break;
        case SELECT_CONCATENATE_LISTS:
            concatenateList();
            break;
        case SELECT_APPEND_LIST:
            appendList();
            break;
        case SELECT_LIST_EQUAL:
            checkEquality();
            break;
        case SELECT_SET_LIST:
            setList();
            break;
        case SELECT_CREATE_DUMMY_ARTICLES:
            *list += createDummyArticles();
            break;
        default:
            throw BAD_USER_INPUT;
    }

}

void LinkDialogue::createList() {
    if (list != nullptr) {
        delete list;
        list = nullptr;
    }
    list = new LinList();
}

void LinkDialogue::pushBack() {
    clearUserInput();
    cin >> *list;
}

void LinkDialogue::pushFront() {
    ContentType content;
    clearUserInput();
    cout << "\nPlease enter a string: ";
    getline(cin, content);
    list->push_front(content);
    cout << "\nThe item with the content: "
         << content << " was successfully added to the start of the list." << endl;
}

void LinkDialogue::popBack() {
    if (!list->pop_back()) return;
    cout << "\nThe last item in the list was removed successfully." << endl;
}

void LinkDialogue::popFront() {
    if (!list->pop_front()) return;
    cout << "\nThe first item in the list was removed successfully." << endl;
}

int LinkDialogue::readPositionFromUser() {
    int position = -1;
    cout << "\nPlease enter the position: ";
    safeRead(cin, position);
    clearUserInput();
    return position;
}

void LinkDialogue::insertItem() {
    int position = readPositionFromUser();
    ContentType content;
    cout << "\nPlease enter a string: ";
    safeRead(cin, content);
    list->insert(position-1, content);
    cout << "\nThe item with the content: "
         << content << " was successfully added in front of the position: " << position << "." << endl;
}

void LinkDialogue::eraseItem() {
    int position = readPositionFromUser();
    list->erase(position-1);
    cout << "\nThe item at the position: " << position << " has been removed successfully." << endl;
}

void LinkDialogue::clear() {
    if (warnUserClear()) {
        list->clear();
        cout << "You shouldn't have done that." << endl;
    } else{
        cout << "Cancelled deletion." << endl;
    }
}

void LinkDialogue::testAt() {
    clearUserInput();
    cout << "First, we will change the content of an element at a certain position."
    << "\nThis is using the at() method that throws exceptions and the first index is 1." << endl;
    int position = readPositionFromUser();
    list->at(position) = "testAt";
    cout << "The item at position " << position << " has been set to testAt." << endl;
    showList();
    cout << "\nNext, please enter another position to test the overloaded operator[ ]."
    << "\nThe index starts at 0 and there will be no exceptions thrown. "
    << "\nThe element will be shown on the screen." << endl;
    position = readPositionFromUser();
    cout << (*list)[position] << endl;
}

void LinkDialogue::appendList() {
    cout << "Creating a new random list to be added at the end via += operator..." << endl;
    LinList temp;
    temp.push_back("testONE");
    temp.push_back("testTWO");
    temp.push_back("testTHREE");
    *list += createDummyArticles();
}

void LinkDialogue::concatenateList() {
    cout << "Creating two random lists to combine them..." << endl;
    LinList temp = createDummyArticles() + createDummyArticles();
    cout << "Combined list:\n" << temp << endl;
}

void LinkDialogue::checkEquality() {
    cout << "Creating three lists to check: " << endl;
    LinList list1;
    LinList list2;
    LinList list3;
    list1.push_back("test1");
    list1.push_back("Hello");
    list1.push_back("World");
    list2.push_back("test1");
    list2.push_back("Hello");
    list2.push_back("World");
    list3.push_back("other test");
    list3.push_back("Hello");
    list3.push_back("World");
    cout << "\nList 1: " << list1 << "\n\nList 2: " << list2 << "\n\nList 3: " << list3 << endl;
    bool equal = list1 == list2;
    bool notEqual = list1 != list3;
    cout << "Comparing list 1 == list2... : " << boolalpha << equal << endl;
    cout << "Comparing list 1 != list3... : " << boolalpha << notEqual << endl;
    equal = list1 == list3;
    cout << "Comparing list 1 == list3... : " << boolalpha << equal << endl;
}

void LinkDialogue::setList() {
    cout << "Creating new random list which overwrites the current list via the operator=...." << endl;
    *list = createDummyArticles();
}

void LinkDialogue::showListCount() {
    cout << "Size: " << list->size() << endl;
}

void LinkDialogue::showList() {
    cout << *list << endl;
}

void LinkDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}

LinList& LinkDialogue::createDummyArticles() {
    MockInput mock;
    LinList* temp = new LinList();
    for (int i = 0; i < AMOUNT_DUMMY_ITEMS; ++i) {
        string content = mock.RandomString(20, 9);
        temp->push_back(content);
    }
    cout << AMOUNT_DUMMY_ITEMS
         << " items with random values have been created." << endl;
    return *temp;
}

bool LinkDialogue::warnUserClear() {
    string input = "1";
    cout << "------ WARNING ------" << endl << "This will delete your current list. Are you sure?";
    while (input[0] != 'y' && input[0] != 'n'){
        cout << "\ny/n:";
        safeRead(cin, input);
    }
    if (input[0] == 'n') return false;
    clearUserInput();
    cout << "Please enter \"CONFIRM\" to proceed with the deletion. You will be UNABLE to recover your data." << endl;
    safeReadln(cin, input);
    if (input != "CONFIRM") return false;
    cout << "What was the name of your first pet?" << endl;
    safeReadln(cin, input);
    return true;
}
