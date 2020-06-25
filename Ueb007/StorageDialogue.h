/**
 *
 *  @file StorageDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#pragma once
#include "Storage.h"
#include "safeRead.h"

enum Select : unsigned char {
    SELECT_NONE,
    SELECT_CREATE_STORAGE,
    SELECT_SHOW_STORAGE,
    SELECT_SHOW_ARTICLE_COUNT,
    SELECT_ADD_ARTICLE,
    SELECT_REMOVE_ARTICLE,
    SELECT_SHOW_ARTICLE,
    SELECT_SHOW_ARTICLES,
    SELECT_ADD_QUANTITY,
    SELECT_REMOVE_QUANTITY,
    SELECT_SET_NAME,
    SELECT_SET_PRICE,
    SELECT_ADJUST_PRICE,
    SELECT_ADJUST_PRICE_ALL,
    SELECT_TEST_COPY,
    SELECT_TEST_EQUALS_OPERATOR,
    SELECT_CREATE_DUMMY_ARTICLES,
    SELECT_QUIT
};

/**
 * Storage dialogue to managed a storage with articles.
 * Every action gives the user feedback.
 */
class StorageDialogue {
public:
    /**
     * The standard constructor.
     * It could initialize the storage as it's needed for every
     * Option but the exercise requires an option to create a storage so we have
     * Decided to omit this feature.
     */
    StorageDialogue();
    /**
     * Destructor.
     * Just to delete the storage pointer.
     */
    ~StorageDialogue();
    /**
     * Starts the dialogue loop.
     */
    void startDialogue();

private:
    static const int AMOUNT_DUMMY_ARTICLES = 10;
    static const std::string STORAGE_NOT_READY;
    static const std::string BAD_USER_INPUT;
    Select currentSelection = Select::SELECT_NONE;
    Storage* storage = nullptr;
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
     * Calling this will delete any existing storage first.
     */
    void createStorage();
    /**
     * Prints out the storage with all its articles by using the overloaded operator.
     */
    void showStorage();
    /**
     * Requests the user for a an article ID.
     * @return The article ID that was provided by the user.
     */
    int readArticleId();

    /**
     * All of these methods are just there to make the switch block a little cleaner and easier to read.
     */
    void addArticle();
    void removeArticle();
    void showArticleAmount();
    void printArticle();
    void listArticles();
    void addQuantity();
    void removeQuantity();
    void setArticleName();
    void setPrice();
    void adjustPrice();
    void adjustPrices();
    void testEqualArticle();
    void copyArticle();

    /**
     * Called every time the user makes a selection to make sure a storage was created.
     */
    void checkStorageState();

    /**
     * Creates completely random articles.
     * Makes testing easier.
     */
    void createDummyArticles();
};