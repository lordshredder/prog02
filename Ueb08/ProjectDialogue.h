/**
 *
 *  @file ProjectDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Project.h"

using namespace std;

enum Select : unsigned char {
    SELECT_NONE,
    SELECT_CREATE_PROJECT,
    SELECT_CREATE_TASK,
    SELECT_CREATE_PRODUCT,
    SELECT_REMOVE_COMPONENT,
    SELECT_SHOW_CURRENT_PROJECT,
    SELECT_SHOW_FULL_PROJECT,
    SELECT_CALCULATE_COST,
    SELECT_SWITCH_ACTIVE_PROJECT,
    SELECT_CREATE_DUMMY_COMPONENTS,
    SELECT_QUIT
};

/**
 * Exception class
 */
class ProjectDialogueException : public logic_error {
public:
    ProjectDialogueException(const std::string& msg = "") : logic_error(msg) {

    }
};

/**
 * Project dialogue to managed a storage with articles.
 * Every action gives the user feedback.
 */
class ProjectDialogue {
public:
    /**
     * The standard constructor.
     */
    ProjectDialogue();
    /**
     * Destructor.
     * Just to delete the storage pointer.
     */
    ~ProjectDialogue();
    /**
     * Starts the dialogue loop.
     */
    void startDialogue();

private:
    static const int AMOUNT_DUMMY_COMPONENTS = 10;
    static const std::string PROJECT_NOT_READY;
    static const std::string BAD_USER_INPUT;
    static const std::string ID_DOES_NOT_EXIST;
    Select currentSelection = Select::SELECT_NONE;
    map<int, shared_ptr<Project>> projects;
    int currentProjectId = 0;
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
    void createProject();
    /**
     * Prints out the storage with all its articles by using the overloaded operator.
     */
    void createTask();
    /**
     * Requests the user for the component ID.
     * @return The component ID that was provided by the user.
     */
    int readComponentId();

    /**
     * All of these methods are just there to make the switch block a little cleaner and easier to read.
     */
    void removeComponent();
    void showProject();
    void showFullProject();
    void createProduct();
    void calculateCost();
    void switchProject();


    /**
     * Creates completely random articles.
     * Makes testing easier.
     */
    void createDummyProjects();
};


