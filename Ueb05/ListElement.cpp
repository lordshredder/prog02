/**
 *
 * @file	ListElement.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "ListElement.h"


ListElement::ListElement(ContentType content, ListElement* previousElement, ListElement* nextElement) {
    this->content = content;
    this->previousElement = previousElement;
    this->nextElement = nextElement;
}

ListElement::~ListElement() {
    // TODO Auto-generated destructor stub
}

std::string ListElement::toString() const {
    return std::__cxx11::string();
}

