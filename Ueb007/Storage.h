/**
 *
 *  @file Storage.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Article.h"
#include <stdexcept>

/**
 * Exception class
 */
class StorageException : public logic_error {
public:
    StorageException(const std::string& msg = "") : logic_error(msg) {

    }
};

/**
 * A storage class that can manage multiple articles
 * with various tasks, such as adding and removing articles as well as changing
 * their price by a set percentage.
 */
class Storage {
public:
    static const int MAX_STORAGE_NAME_SIZE = 20;
    static const int STANDARD_STORAGE_SIZE = 20;
    static const int ARTICLE_NOT_FOUND = -1;
    static const std::string EMPTY_STORAGE_NAME;
    static const std::string NAME_LIMIT_EXCEEDED;
    static const std::string ARTICLE_DOES_NOT_EXIST;
    static const std::string ARTICLE_ID_ALREADY_EXISTS;
    /**
     * Creating a Storage without providing a name is not allowed.
     */
    Storage() = delete;
    /**
     * Constructor for the storage class.
     * @param storageName The name must be smaller than 20 letters and cannot be empty.
     */
    explicit Storage(const std::string& storageName);
    /**
     * Copy constructor.
     * @param storage Storage to copy.
     */
    Storage(const Storage& storage);
    /**
     * Will delete all articles inside the vector.
     */
    ~Storage();
    /**
     * Equals operator
     * @param storage The storage we're copying from.
     * @return The storage with new values from the parameter storage.
     */
    Storage& operator=(const Storage& storage);
    /**
     * Adds an already created article.
     * @param article The article to add.
     */
    void addArticle(shared_ptr<Article> article);
    /**
     * Removes the article from the article vector.
     * Throws an exception if the article does not exist.
     * @param articleId The ID of the article to remove from the storage.
     */
    void removeArticle(int articleId);
    /**
     * Increases the stock of an article.
     * @param articleId The ID of the article that should have its stock increased.
     * @param quantity The amount to add to the article; Cannot be negative.
     */
    void addQuantity(int articleId, int quantity);
    /**
     * Decreases the stock of an article.
     * @param articleId The ID of the article to remove stock from.
     * @param quantity The amount to remove from the article; Cannot be negative.
     */
    void removeQuantity(int articleId, int quantity);
    /**
     * Adjusts the price of all articles by a specific percent.
     * @param percent Can be positive or negative.
     */
    void adjustPriceByPercent(long double percent);
    /**
     * Adjusts the price of the article
     * @param articleId The ID of the article to be adjusted.
     * @param percent Can be positive or negative.
     */
    void adjustPriceByPercent(int articleId, long double percent);
    /**
     * Prints the article.
     * @param articleId The ID of the article to print.
     */
    void printArticle(int articleId);
    /**
     * Prints all articles in this storage.
     */
    void printArticles();
    int getArticleAmount() const;
    std::string getName() const;

    void setPrice(int articleId, long double newPrice);
    void setArticleName(int articleId, const std::string& newDescription);

    /**
     * Adjust the name of the Storage
     * @param newName has to be smaller than 20 letters and cannot be empty.
     */
    void setName(const std::string& newName);
    /**
     * It prints out the storage object. This includes all articles it is currently storing.
     * @return The storage as string.
     */
    std::string toString() const;

    /**
     * Basically toString() but a little more comfortable to use.
     */
    friend std::ostream& operator<<(std::ostream& stream, const Storage& storage);

private:
    std::string storageName;
    std::vector<shared_ptr<Article>> articles;

    /**
     * Finds a specific Article in the storage.
     * @param articleNr This is used to find the specific article.
     * @return position of the article inside the vector; -1 if nothing was found.
     */
    int findArticle(const int& articleId);
    /**
     * Deletes the articles in the vector.
     */
    void deleteStorage();
};

