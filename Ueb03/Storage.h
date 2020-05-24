/**
 *
 *  @file Storage.h
 *  @authors David Berres, Nico Schorr
 *  @date 24.05.2020
 */
#pragma once
#include <iostream>
#include <string>
#include <Article.h>
using namespace std;

/**
 * A class called Storage, used to simulate a storage that can manage multiple articles
 * with various tasks, such as adding and removing articles as well as changing
 * their price by a set percentage.
 */
class Storage
{
private:
    string name;
    Article** article_database;
    int size_database;
    int article_count;

public:
    static const string ARTICLE_TAKEN;
    static const string ARTICLE_NOT_FOUND;
    static const string STORAGE_SPACE;
    static const string AMOUNT_TOO_SMALL;
    static const string STOCK_MUST_BE_POSITIVE;

    /**
     * Constructor for the class Storage
     * @param name Name of the Storage.
     * @param size_database The Size of the Database.
     */
    Storage(string name, int size_database);


    /**
     * Function used for finding a specific Article in the Storage.
     * @param articleNr This is used to find the specific Article.
     * @return -1 if nothing was found.
     */
    int find_Article(int articleNr);

    /**
     * Function used for adding an article to the Storage.
     * @param articleNr the identification Number used for labelling the article.
     * @param price used for setting a price.
     * @param description additional information for the article.
     * @param stock used for setting the quantity of the article.
     */
    void addArticle(int articleNr, double price, string description, int stock = 0);


    /**
     * Function used for removing an Article from the Storage.
     * @param articleNr used for finding the specific Article to remove.
     */
    void removeArticle(int articleNr);

    /**
     * Function used for adding a specific quantity to a specific Article.
     * @param articleNr used for finding the specific Article.
     * @param amount used for adding a specific quantity to the Article.
     */
    void addQuantity(int articleNr, int amount);

    /**
     * Function used for removing a specific quantity to a specific Article.
     * @param articleNr used for finding the specific Article.
     * @param amount used for adding a specific quantity to the Article.
     */
    void removeQuantity(int articleNr, int amount);

    /**
     * Function used for changing the price of all articles by a set percent.
     * @param percent this is the specific percentage that changes the articles.
     */
    void adjustPriceByPercent(double percent);

    /**
     * Function used for changing the price of a specific article.
     * @param articleNr used for finding the specific Article.
     * @param price used for setting a price.
     */
    void change_price(int articleNr, double price);

    string getName() const;
    int getArticle_count() const;
    int getSize_database() const;
};

