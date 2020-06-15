/**
 *
 * @file	LinList.h
 * @author	folz
 * @date	20.05.2012
 */

#pragma once
#include "safeRead.h"
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
    static const std::string INDEX_OUT_OF_BOUNDS;
    LinList();
    LinList(const LinList& list);
    ~LinList();
    bool operator==(const LinList& list) const;
    bool operator!=(const LinList& list) const;
    LinList operator+(const LinList& list);
    LinList& operator+=(const LinList& list);
    LinList& operator=(const LinList& list);
    ContentType& operator[](ssize_t position) noexcept;
    ContentType operator[](ssize_t position) const noexcept;
    void push_back(const ContentType& content);
    void push_front(const ContentType& content);
    bool pop_back();
    bool pop_front();
    void insert(ssize_t position, const ContentType& content);
    void erase(ssize_t position);
    void clear();
    ContentType at(ssize_t position) const;
    ContentType& at(ssize_t position);
    ssize_t size();
    std::string toString() const;
    friend ostream& operator<< (ostream& stream, const LinList& list);
    friend istream& operator>> (istream& stream, LinList&list);
private:
    ssize_t listSize;
    ListElement* first;
    ListElement* last;
};

