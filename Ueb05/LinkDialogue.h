/**
 *
 *  @file LinkDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#pragma once
#include "safeRead.h"
#include "LinList.h"

enum Select : unsigned char {
    SELECT_NONE,
    SELECT_SHOW_LIST,
    SELECT_SHOW_LIST_COUNT,
    SELECT_PUSH_BACK,
    SELECT_PUSH_FRONT,
    SELECT_POP_BACK,
    SELECT_POP_FRONT,
    SELECT_INSERT,
    SELECT_ERASE,
    SELECT_CLEAR,
    SELECT_AT,
    SELECT_CONCATENATE_LISTS,
    SELECT_APPEND_LIST,
    SELECT_LIST_EQUAL,
    SELECT_SET_LIST,
    SELECT_CREATE_DUMMY_ARTICLES,
    SELECT_QUIT
};

/**
 * Linked list dialogue to manage a list.
 * Every action gives the user feedback.
 */
class LinkDialogue {
public:
    /**
     * The standard constructor.
     * It could initialize the list as it's needed for every
     * Option but the exercise requires an option to create a list so we have
     * Decided to omit this feature.
     */
    LinkDialogue();
    /**
     * Destructor.
     * Just to delete the list pointer.
     */
    ~LinkDialogue();
    /**
     * Starts the dialogue loop.
     */
    void startDialogue();

private:
    static const int AMOUNT_DUMMY_ITEMS = 10;
    static const std::string BAD_USER_INPUT;
    Select currentSelection = Select::SELECT_NONE;
    LinList* list = nullptr;
    /**
     * Reads the user input to determine the selection.
     * Bad input is filtered.
     */
    void readUserSelection();
    /**
     * Deletes anything after the first input.
     */
    void clearUserInput();
    /**
     * Calls a giant, ugly switch block to execute the selected option.
     * @param selection The user input.
     */
    void executeSelection(const Select& selection);
    /**
     * Prints out the list with all its articles by using the overloaded operator.
     */
    void showList();
    /**
     * Requests the user for a position.
     * @return The position that was provided by the user.
     */
    int readPositionFromUser();

    /**
     * All of these methods are just there to make the switch block a little cleaner and easier to read.
     */
    void createList();
    void showListCount();
    void pushBack();
    void pushFront();
    void popBack();
    void popFront();
    void insertItem();
    void eraseItem();
    void clear();
    void testAt();
    void concatenateList();
    void appendList();
    void checkEquality();
    void setList();

    /**
     * Asks the user if they are ABSOLUTELY sure they want to delete the list.
     * Just for fun.
     * @return The user's decision.
     */
    bool warnUserClear();

    /**
     * Creates completely random articles.
     * Makes testing easier.
     */
    LinList& createDummyArticles();
};
