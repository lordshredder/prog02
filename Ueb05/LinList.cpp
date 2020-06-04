/**
 *
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "LinList.h"


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
    ++size;
}

void LinList::push_front(ContentType content) {

}

void LinList::pop_back() {

}

void LinList::pop_front() {

}

void LinList::insert(int position, ContentType content) {

}

void LinList::erase(int position) {

}

void LinList::clear() {

}

std::string LinList::toString() const {
    return std::__cxx11::string();
}

ostream &operator<<(ostream& stream, const LinList& list) {
    return stream;
}

istream &operator>>(istream& stream, LinList& list) {
    return stream;
}


