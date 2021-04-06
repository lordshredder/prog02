/**
 *
 *  @file ListElement.h
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */
#pragma once
#include <string>
using namespace std;
//typedef string ContentType;


/**
 * Listenelement fuer eine doppelt-verkettete Lineare Liste
 *
 * @author	folz
 * @version
 * @date	20.05.2012
 */
template<typename ContentType>
class ListElement;

template<typename  ContentType>
std::ostream& operator<<(std::ostream& stream, const ListElement<ContentType>& element);

template<typename ContentType>
class ListElement {
public:
    explicit ListElement(const ContentType& type, ListElement<ContentType>* previousElement = nullptr, ListElement<ContentType>* nextElement = nullptr);
    ListElement(const ListElement<ContentType>& element);
    ~ListElement();
    ListElement<ContentType>& operator=(const ListElement<ContentType>& list);
    std::string toString() const;
    friend std::ostream& operator<< <>(std::ostream& stream, const ListElement& element);
    friend class LinList;
private:
    ContentType content;
    ListElement* previousElement;
    ListElement* nextElement;
};
