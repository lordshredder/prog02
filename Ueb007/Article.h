/**
 *
 *  @file Article.h
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
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
    static const int MAX_ARTICLE_ID = 9999;
    static const int MIN_ARTICLE_ID = 1000;
    static const int MAX_STOCK = 10;
    static const int MAX_ARTICLE_DESCRIPTION_SIZE = 16;
    static const std::string EMPTY_ARTICLE_DESCRIPTION;
    static const std::string DESCRIPTION_LIMIT_EXCEEDED;
    static const std::string ARTICLE_MUST_BE_FOUR_DIGITS;
    static const std::string STOCK_MUST_BE_POSITIVE;
    static const std::string PRICE_MUST_BE_POSITIVE;
    static const std::string ADD_POSITIVE_QUANTITY_ONLY;
    static const std::string REMOVE_POSITIVE_QUANTITY_ONLY;
    static const std::string STOCK_LIMIT_EXCEEDED;
    /**
     *  Constructor for the class Article
     *  @param articleNr The Number used to identify the article. Must be 4 digits and positive.
     *  @param description The description used for additional information. Cannot be empty or above the set limit.
     *  @param stock The quantity of the article. Cannot be negative.
     */
    Article(int articleNr, const std::string& description, long double price, int stock = 0);
    /**
     * Copy constructor.
     * @param article The article we're copying from.
     */
    Article(const Article& article);
    /**
     * Destructor.
     * Doesn't do much in this case.
     * We're printing a debug line to test if it is called.
     */
    ~Article();
    /**
     * Equals operator
     * @param article The article we're copying from.
     * @return The article with new values from the parameter.
     */
    Article& operator=(Article article);
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
    long double getPrice() const;
    std::string getDescription() const;
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual shared_ptr<Article> copy() const;
    /**
     * Simple toString method.
     * @return String of this object.
     */
    virtual std::string toString() const;
    /**
     *  Changes the description of an article.
     *  @param newDescription cannot exceed the set limit and cannot be empty.
     */
    void setDescription(const std::string& newDescription);
    /**
     * Directly sets the price of the article.
     * @param newPrice Cannot be negative.
     */
    void setPrice(const long double& newPrice);
    /**
     * Storage is a friend for performance reasons... and to try out the friend concept.
     */
    friend class Storage;
    friend std::ostream& operator<<(std::ostream& stream, const Article& article);

protected:
    int articleNr;
    std::string description;
    long double price;
    int stock;
};


