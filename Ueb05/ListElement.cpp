/**
 *
 *  @file ListElement.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
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

