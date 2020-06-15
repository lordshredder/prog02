/**
 *
 *  @file LinList.h
 *  @authors David Berres, Nico Schorr
 *  @date 14.06.2020
 */

#pragma once
#include "ListElement.h"

/**
 * A doubly linked list that can add and remove elements at the start, end and middle of the list.
 */
class LinList {
public:
    /**
     * Basic Constructor of the list.
     */
    LinList();
    /**
     * Destructor of the list.
     */
    ~LinList();
    /**
     * Function used for adding an element at the end of the list.
     * @param content User input that will be stores inside the element.
     */
    void push_back (ContentType content);
    /**
     * Function used for adding an element at the start of the list.
     * @param content User input that will be stores inside the element.
     */
    void push_front(ContentType content);
    /**
     * Function used for removing an element at the end of the list.
     */
    void pop_back();
    /**
     * Function used for removing an element at the start of the list.
     */
    void pop_front();
    /**
     * Function used for inserting an element before the given position.
     * @param position User input that determines the position.
     * @param content User input that will be stores inside the element.
     */
    void insert(int position, ContentType content);
    /**
     * Function used for removing an element at the given position.
     * @param position User input that determines the position.
     */
    void erase(int position);
    /**
     * Function used for removing all elements of the list.
     */
    void clear();
    /**
     * Converts the entire list into a string.
     * @return returns the string.
     */
    std::string toString() const;
    /**
     * Overloading the << operator to output the entire list.
     * @param stream
     * @param list The list that needs to be printed.
     * @return
     */
    friend ostream& operator<< (ostream& stream, const LinList& list);
    /**
     *
     * @param stream
     * @param list
     * @return
     */
    friend istream& operator>> (istream& stream, LinList&list);
    /**
     * Error warnings.
     */
    static const std::string POSITION_INVALID;
private:
    size_t size;
    ListElement* first;
    ListElement* last;
};

