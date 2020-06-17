/**
 *
 *  @file LinList.h
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */

#pragma once
#include "safeRead.h"
#include "ListElement.h"

/**
 * A doubly linked list that can add and remove elements at the start, end and middle of the list.
 */
class LinList {
public:
    static const std::string INDEX_OUT_OF_BOUNDS;
    /**
     * Basic Constructor of the list.
     */
    LinList();
    /**
     * Simple copy constructor.
     * @param list List to be copied.
     */
    LinList(const LinList& list);
    /**
     * Destructor of the list.
     */
    ~LinList();
    bool operator==(const LinList& list) const;
    bool operator!=(const LinList& list) const;
    LinList operator+(const LinList& list);
    LinList& operator+=(const LinList& list);
    LinList& operator=(const LinList& list);
    ContentType& operator[](ssize_t position) noexcept;
    ContentType operator[](ssize_t position) const noexcept;
    /**
     * Function used for adding an element at the end of the list.
     * @param content User input that will be stores inside the element.
     */
    void push_back(const ContentType& content);
    /**
     * Function used for adding an element at the start of the list.
     * @param content User input that will be stores inside the element.
     */
    void push_front(const ContentType& content);
    /**
     * Function used for removing an element at the end of the list.
     */
    bool pop_back();
    /**
     * Function used for removing an element at the start of the list.
     */
    bool pop_front();
    /**
     * Function used for inserting an element before the given position.
     * @param position User input that determines the position.
     * @param content User input that will be stores inside the element.
     */
    void insert(ssize_t position, const ContentType& content);
    /**
     * Function used for removing an element at the given position.
     * @param position User input that determines the position.
     */
    void erase(ssize_t position);
    /**
     * Function used for removing all elements of the list.
     */
    void clear();
    /**
     * Returns the content at the specified position of the list.
     * The difference between the at method and the operator[] is
     * that this method throws an exception if the position is out of bounds.
     * Furthermore, the index starts at 1 instead of 0.
     * @param position The index starts at 1.
     * @return The content at the position.
     */
    ContentType at(ssize_t position) const;
    /**
     * Returns the content at the specified position of the list.
     * The difference between the at method and the operator[] is
     * that this method throws an exception if the position is out of bounds.
     * Furthermore, the index starts at 1 instead of 0.
     * @param position The index starts at 1.
     * @return The content at the position.
     */
    ContentType& at(ssize_t position);
    /**
     * Returns the current size of the list.
     * @return Size of the list.
     */
    ssize_t size();
    /**
     * Converts the entire list into a string.
     * @return returns the string.
     */
    std::string toString() const;
    friend ostream& operator<< (ostream& stream, const LinList& list);
    friend istream& operator>> (istream& stream, LinList&list);
private:
    ssize_t listSize;
    ListElement* first;
    ListElement* last;
};

