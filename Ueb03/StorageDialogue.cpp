/**
 *
 *  @file StorageDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "StorageDialogue.h"

StorageDialogue::StorageDialogue() {

}

void StorageDialogue::readUserSelection() {
    int selection = -1;
    cout << "Please Select an option by entering a valid number:\n"
    << Select::SelectCreateStorage << " : Create new TestStorage\n"
    << Select::SelectAddArticle << " : Add new Article\n"
    << Select::SelectRemoveArticle << " : Remove existing Article\n"
    << Select::SelectShowArticle << " : Print Article\n"
    << Select::SelectShowArticles << " : Print all Articles\n"
    << Select::SelectAddQuantity << " : Add Stock to Article\n"
    << Select::SelectRemoveQuantity << " : Remove Stock from Article\n"
    << Select::SelectAdjustPrice << " : Adjust Price of Article\n"
    << Select::SelectAdjustPriceAll << " : Adjust Price of all Articles\n"
    << Select::SelectQuit << " : Quit\n";
    cin >> selection;
    currentSelection = static_cast<Select>(selection);
}

void StorageDialogue::executeSelection(const Select& selection) {
    switch (currentSelection) {

        case SelectNone:
            break;
        case SelectCreateStorage:
            break;
        case SelectAddArticle:
            break;
        case SelectRemoveArticle:
            break;
        case SelectShowArticle:
            break;
        case SelectShowArticles:
            break;
        case SelectAddQuantity:
            break;
        case SelectRemoveQuantity:
            break;
        case SelectAdjustPrice:
            break;
        case SelectAdjustPriceAll:
            break;
        case SelectQuit:
            break;
    }

}

void StorageDialogue::startDialogue() {
    while (currentSelection != Select::SelectQuit) {
        readUserSelection();
        executeSelection(currentSelection);
    }

}
