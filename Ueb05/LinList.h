/**
 *
 * @file	LinList.h
 * @author	folz
 * @date	20.05.2012
 */

#pragma once
#include "ListElement.h"

/**
 * Doppelt-verkettete Lineare Liste
 *
 * @author	folz
 * @version
 * @date	20.05.2012
 */
class LinList {
public:
    LinList();
    ~LinList();
    void push_back (ContentType content);
    void push_front(ContentType content);
    void pop_back();
    void pop_front();
    void insert(int position, ContentType content);
    void erase(int position);
    void clear();
    std::string toString() const;
    friend ostream& operator<< (ostream& stream, const LinList& list);
    friend istream& operator>> (istream& stream, LinList&list);
private:
    size_t size;
    ListElement* first;
    ListElement* last;
};

