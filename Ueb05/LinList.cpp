/**
 *
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "LinList.h"
#include <string>
#include <sstream>

const string LinList::POSITION_INVALID = "Position cannot be negative or greater than the size of the list";


LinList::LinList() {
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}

LinList::~LinList() {
    // TODO Auto-generated destructor stub
}

void LinList::push_back(ContentType content) {
    if (size == 0) {
        this->first = new ListElement(content);
        this->last = first;
        ++size;
        return;
    }
    ListElement* currentLast = this->last;
    this->last = new ListElement(content, currentLast, nullptr);
    currentLast->nextElement = this->last;
    ++size;
}

void LinList::push_front(ContentType content) {
    if (size ==0) {
        this->first = new ListElement(content);
        this->last = first;
        ++size;
        return;
    }
    ListElement* currentFirst = this->first;
    this->first = new ListElement(content, nullptr, currentFirst);
    currentFirst->previousElement = this->first;
    ++size;

}

void LinList::pop_back() {
    if (size == 0) return;
    ListElement* newLast = last->previousElement;
    delete last;
    last = newLast;
    last->nextElement = nullptr;
    --size;
}

void LinList::pop_front() {
    if (size == 0) return;
    if (size == 1) {
        delete first;
        first = nullptr;
        last = nullptr;
        --size;
        return;
    }
    ListElement* newFirst = first->nextElement;
    delete first;
    first = newFirst;
    first->previousElement = nullptr;
    --size;
}

void LinList::insert(int position, ContentType content) {
    --position;
    if (position < 0) throw POSITION_INVALID;

    if(position == 0) {
        push_front(content);
        return;
    }
    if (position > size){
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
    ++size;
}

void LinList::erase(int position) {
    --position;

    if (position < 0 ) throw POSITION_INVALID;

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
    --size;
}

void LinList::clear() {
    while (size > 0) {
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

ostream &operator<<(ostream& stream, const LinList& list) {
    return stream << list.toString();
}

istream &operator>>(istream& stream, LinList& list) {
    string temp;
    stream >> temp;
    list.push_back(temp);
    return stream;
}


