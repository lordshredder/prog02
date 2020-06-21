/**
 *
 *  @file FileDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.1979
 */
#pragma once
#include "safeRead.h"
#include "FileAnalyzer.h"

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
 * Linked analyzer dialogue to manage a analyzer.
 * Every action gives the user feedback.
 */
class FileDialogue {
public:
    /**
     * The standard constructor.
     * It could initialize the analyzer as it's needed for every
     * Option but the exercise requires an option to create a analyzer so we have
     * Decided to omit this feature.
     */
    FileDialogue(FileAnalyzer& analyzer);
    /**
     * Destructor.
     * Just to delete the analyzer pointer.
     */
    ~FileDialogue();
    /**
     * Starts the dialogue loop.
     */
    void startDialogue();

private:
    static const std::string BAD_USER_INPUT;
    Select currentSelection = Select::SELECT_NONE;
    FileAnalyzer* analyzer = nullptr;
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
};
