#include <iostream>
#include <string>
#include "Article.h"
using namespace std;

Article::Article(int articleNr, string description, int stock){
    if (articleNr > 9999 || articleNr < 1000) {
        throw "The article number must be 4 digits";
    }
    if (description.empty(){
        throw "The article description cannot be empty";
    }
    if (stock < 0){
        throw "The stock must be positive";
    }
    this->articleNr = articleNr;
    this->description = description;
    this->stock = stock;
}

void Article::addQuantity(int amount){
    if (amount < 0){
        throw "When adding quantity, the amount must be positive";
    }
    this->stock += amount;
}

void Article::removeQuantity(int amount){
    if (amount < 0){
        throw "When removing quantity, the amount must be positive";
    }
    if (this->stock < amount){
        throw "The stock cannot be negative";
    }
    this->stock -= amount;
}

int Article::getArticleNr(){
    return articleNr;
}

int Article::getStock(){
    return stock;
}

string Article::getDescription(){
    return description;
}

void Article::setDescription(string newDescription){
    if (newDescription.length() > STRING_LIMIT){
        throw "The article description is greater than the set string limit of 128";
    }
    if (newDescription.empty(){
        throw "Article description cannot be empty";
    }
    this->description = newDescription;
}