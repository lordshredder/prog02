/**
 *
 *  @file Article.h
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */


#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 *  A class called Article, used to simulate inventory management by
 *  working with an article number, a description and a given stock.
 *  The class is also able to add and remove quantity from the stock as well as
 *  changing the description of the article.
 */



class Article {
public:
    Article(int articleNr, const string& description, int stock = 0);

    void addQuantity(int amount);

    void removeQuantity(int amount);

    int getArticleNr() const;

    int getStock() const;

    string getDescription() const;

    void setDescription(const string& newDescription);

private:
    int articleNr;
    int stock;
    string description;
};


