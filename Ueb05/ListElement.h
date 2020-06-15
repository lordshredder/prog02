/**
 *
 *  @file ListElement.h
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */
#pragma once
#include <string>
using namespace std;
typedef string ContentType;


/**
 * Listenelement fuer eine doppelt-verkettete Lineare Liste
 *
 * @author	folz
 * @version
 * @date	20.05.2012
 */
class ListElement {
public:
    static const int MAX_CONTENT_SIZE = 20;
    explicit ListElement(ContentType type, ListElement* previousElement = nullptr, ListElement* nextElement = nullptr);
    ~ListElement();
    std::string toString() const;
    friend class LinList;
private:
    ContentType content;
    ListElement* previousElement;
    ListElement* nextElement;
};
