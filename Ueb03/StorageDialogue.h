/**
 *
 *  @file StorageDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#pragma once

#include "TestStorage.h"
enum Select : unsigned char {
    SelectNone,
    SelectCreateStorage,
    SelectAddArticle,
    SelectRemoveArticle,
    SelectShowArticle,
    SelectShowArticles,
    SelectAddQuantity,
    SelectRemoveQuantity,
    SelectAdjustPrice,
    SelectAdjustPriceAll,
    SelectQuit
};
class StorageDialogue {
public:
    StorageDialogue();
    void startDialogue();
    void readUserSelection();
    void executeSelection(const Select& selection);

private:
    TestStorage* storage;
    Select currentSelection = Select::SelectNone;
};