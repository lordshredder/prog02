/**
 *
 *  @file ListElement.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */

#include "ListElement.h"

template<typename ContentType>
ListElement<ContentType>::ListElement(const ContentType& content, ListElement<ContentType>* previousElement, ListElement<ContentType>* nextElement) {
    this->content = content;
    this->previousElement = previousElement;
    this->nextElement = nextElement;
}

template<typename ContentType>
ListElement<ContentType>::ListElement(const ListElement<ContentType>& element) : content(element.content) { }

template<typename ContentType>
ListElement<ContentType>::~ListElement() {
    previousElement = nullptr;
    nextElement = nullptr;
}

template<typename ContentType>
std::string ListElement<ContentType>::toString() const {
    return std::to_string(content);
}

template<typename ContentType>
ListElement<ContentType> &ListElement<ContentType>::operator=(const ListElement<ContentType>& list) {
    if (this == &list) return *this;
    this->content = list.content;
    this->nextElement = list.nextElement;
    this->previousElement = list.previousElement;
    return *this;
}

template<typename ContentType>
ostream& operator<< <>(ostream& stream, const ListElement<ContentType>& element) {
    return stream << element.toString();
}
