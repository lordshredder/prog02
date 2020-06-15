/**
 *
 * @file	ListElement.h
 * @author	folz
 * @date	20.05.2012
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
    explicit ListElement(const ContentType& type, ListElement* previousElement = nullptr, ListElement* nextElement = nullptr);
    ListElement(const ListElement& element);
    ~ListElement();
    ListElement& operator=(const ListElement& list);
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const ListElement& element);
    friend class LinList;
private:
    ContentType content;
    ListElement* previousElement;
    ListElement* nextElement;
};
