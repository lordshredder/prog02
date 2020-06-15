/**
 *
 * @file	ListElement.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "ListElement.h"

ListElement::ListElement(const ContentType& content, ListElement* previousElement, ListElement* nextElement) {
    this->content = content;
    this->previousElement = previousElement;
    this->nextElement = nextElement;
}

ListElement::ListElement(const ListElement& element) : content(element.content) { }

ListElement::~ListElement() {
    previousElement = nullptr;
    nextElement = nullptr;
}

std::string ListElement::toString() const {
    return content;
}

ListElement &ListElement::operator=(const ListElement& list) {
    if (this == &list) return *this;
    this->content = list.content;
    this->nextElement = list.nextElement;
    this->previousElement = list.previousElement;
    return *this;
}

ostream& operator<<(ostream& stream, const ListElement& element) {
    return stream << element.toString();
}
