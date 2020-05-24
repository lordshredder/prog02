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
    /**
     *  Constructor for the class Article
     *  @param articleNr The Number used to identify the article. Must be 4 digits and positive.
     *  @param description The description used for additional information. Cannot be empty or above the set limit.
     *  @param stock The quantity of the article. Cannot be negative.
     */
    Article(int articleNr, const string& description, double price, int stock = 0);
    ~Article();
    Article(const Article& article);
    /**
     *  Function used for adding a specific amount to the article's stock.
     *  An arbitrary maximum was chosen for the stock which cannot be exceeded.
     *  @param amount cannot be negative.
     */
    void addQuantity(int amount);
    /**
     *  Function used for removing a specific amount of the article's stock.
     *  The stock cannot become negative.
     *  @param amount cannot be negative.
     */
    void removeQuantity(int amount);
    int getArticleNr() const;
    int getStock() const;
    double getPrice() const;
    string getDescription() const;
    string toString() const;

    /**
     *  Function used for changing the description of an article.
     *  @param newDescription cannot exceed the set limit and cannot be empty.
     */
    void setDescription(const string& newDescription);
    void setPrice(const double& newPrice);
    friend class TestStorage;
    friend ostream& operator<<(ostream& stream, const Article& article);

private:
    static const int MAX_ARTICLE_ID = 9999;
    static const int MIN_ARTICLE_ID = 1000;
    static const int MAX_STOCK = 10;
    static const int MAX_ARTICLE_DESCRIPTION_SIZE = 20;
    static const std::string EMPTY_ARTICLE_DESCRIPTION;
    static const std::string DESCRIPTION_LIMIT_EXCEEDED;
    static const std::string ARTICLE_MUST_BE_FOUR_DIGITS;
    static const std::string STOCK_MUST_BE_POSITIVE;
    static const std::string PRICE_MUST_BE_POSITIVE;
    static const std::string ADD_POSITIVE_QUANTITY_ONLY;
    static const std::string REMOVE_POSITIVE_QUANTITY_ONLY;
    static const std::string STOCK_LIMIT_EXCEEDED;

    int articleNr;
    int stock;
    double price;
    string description;

};


