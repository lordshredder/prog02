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
    static const int MAX_ARTICLE_ID = 9999;
    static const int MIN_ARTICLE_ID = 1000;
    static const int MAX_STOCK = 10;
    static const int MAX_ARTICLE_DESCRIPTION_SIZE = 20;
    static const std::string EMPTY_ARTICLE_DESCRIPTION;
    static const std::string DESCRIPTION_LIMIT_EXCEEDED;
    static const std::string ARTICLE_MUST_BE_FOUR_DIGITS;
    static const std::string STOCK_MUST_BE_POSITIVE;
    static const std::string ADD_POSITIVE_QUANTITY_ONLY;
    static const std::string REMOVE_POSITIVE_QUANTITY_ONLY;
    static const std::string STOCK_LIMIT_EXCEEDED;

    int articleNr;
    int stock;
    string description;

};


