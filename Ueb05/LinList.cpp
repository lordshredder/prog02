/**
 *
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "LinList.h"
#include <string>
#include <sstream>

const string LinList::INDEX_OUT_OF_BOUNDS = "Position cannot be negative or greater than the size of the list.";


LinList::LinList() {
    this->first = nullptr;
    this->last = nullptr;
    this->listSize = 0;
}

LinList::LinList(const LinList &list) : first(nullptr), last(nullptr), listSize(0) {
    ListElement* temp = list.first;
    for (int i = 0; i < list.listSize; ++i) {
        push_back(temp->content);
        temp = temp->nextElement;
    }
}

LinList::~LinList() {
    cout << "DEBUG: LinList Destructor called." << endl;
    clear();
}

void LinList::push_back(const ContentType &content) {
    if (listSize == 0) {
        this->first = new ListElement(content);
        this->last = first;
        ++listSize;
        return;
    }
    ListElement* currentLast = this->last;
    this->last = new ListElement(content, currentLast, nullptr);
    currentLast->nextElement = this->last;
    ++listSize;
}

void LinList::push_front(const ContentType &content) {
    if (listSize == 0) {
        this->first = new ListElement(content);
        this->last = first;
        ++listSize;
        return;
    }
    ListElement* currentFirst = this->first;
    this->first = new ListElement(content, nullptr, currentFirst);
    currentFirst->previousElement = this->first;
    ++listSize;

}

bool LinList::pop_back() {
    if (listSize < 1) return false;
    if (listSize == 1) {
        delete first;
        first = nullptr;
        last = nullptr;
        --listSize;
        return true;
    }
    ListElement* newLast = last->previousElement;
    delete last;
    last = newLast;
    last->nextElement = nullptr;
    --listSize;
    return true;
}

bool LinList::pop_front() {
    if (listSize < 1) return false;
    if (listSize == 1) {
        delete first;
        first = nullptr;
        last = nullptr;
        --listSize;
        return true;
    }
    ListElement* newFirst = first->nextElement;
    delete first;
    first = newFirst;
    first->previousElement = nullptr;
    --listSize;
    return true;
}

void LinList::insert(ssize_t position, const ContentType& content) {
    if(position < 1) {
        push_front(content);
        return;
    }
    if (position > listSize){
        push_back(content);
        return;
    }
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    ListElement* newElement = new ListElement(content, findPos->previousElement, findPos);
    findPos->previousElement = newElement;
    newElement->previousElement->nextElement = newElement;
    ++listSize;
}

void LinList::erase(ssize_t position) {
    if (position < 0 || position > listSize) throw INDEX_OUT_OF_BOUNDS;
    if (position == 0) {
        pop_front();
        return;
    }
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    findPos->previousElement->nextElement = findPos->nextElement;
    findPos->nextElement->previousElement = findPos->previousElement;
    delete findPos;
    --listSize;
}

void LinList::clear() {
    while (listSize > 0) {
        pop_front();
    }
    first = nullptr;
    last = nullptr;
}

std::string LinList::toString() const {
    ostringstream oStr;
    ListElement* findPos = this->first;
    if (findPos == nullptr) return "";
    int counter = 1;
    while (findPos != nullptr){
        oStr << "\nListElement " << counter << ": " << findPos->content;
        findPos = findPos->nextElement;
        ++counter;
    }
    return oStr.str();
}

ContentType LinList::at(ssize_t position) const {
    if (position < 0 || position > listSize) throw INDEX_OUT_OF_BOUNDS;
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    return findPos->content;
}

ContentType& LinList::at(ssize_t position) {
    if (position < 0 || position > listSize) throw INDEX_OUT_OF_BOUNDS;
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    return findPos->content;
}

ostream& operator<<(ostream& stream, const LinList& list) {
    return stream << list.toString();
}

istream& operator>>(istream& stream, LinList& list) {
    ContentType input;
    const string cancel = "#DONE";
    while (input != cancel) {
        cout << "Enter a string to add to the list. Enter #DONE to finish the process." << endl;
        safeReadln(cin, input);
       if (input != cancel) list.push_back(input);
    }
    return stream;
}

ssize_t LinList::size() {
    return listSize;
}

bool LinList::operator==(const LinList &list) const {
    if (this->listSize != list.listSize) return false;
    ListElement* listElem1 = this->first;
    ListElement* listElem2 = list.first;
    for (int i = 0; i < this->listSize; ++i) {

        if (listElem1->content != listElem2->content) return false;
        listElem1 = listElem1->nextElement;
        listElem2 = listElem2->nextElement;
    }
    return true;
}

bool LinList::operator!=(const LinList &list) const {
    return !(*this == list);
}

ContentType& LinList::operator[](ssize_t position) noexcept {
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    return findPos->content;
}

ContentType LinList::operator[](ssize_t position) const noexcept {
    ListElement* findPos = this->first;
    for(int i = 0; i < position; i++) {
        findPos = findPos->nextElement;
    }
    return findPos->content;
}

LinList &LinList::operator=(const LinList &list) {
    if (this == &list) return *this;
    ListElement* findPos = list.first;
    clear();
    for (int i = 0; i < list.listSize; ++i) {
        push_back(findPos->content);
        findPos = findPos->nextElement;
    }
    return *this;
}

LinList LinList::operator+(const LinList &list) {
    return LinList(*this) += list;
}

LinList& LinList::operator+=(const LinList &list) {
    ListElement* elem = list.first;
    for (int i = 0; i < list.listSize; ++i) {
        push_back(elem->content);
        elem = elem->nextElement;
    }
    return *this;
}


