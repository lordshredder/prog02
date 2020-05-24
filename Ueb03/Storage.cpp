/**
 *
 *  @file Storage.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 24.05.2020
 */

#include "Storage.h"
#include "Article.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


const string Storage::ARTICLE_TAKEN = "This ArticleNr. is already taken";
const string Storage::ARTICLE_NOT_FOUND = "This ArticleNr. could not be found";
const string Storage::STORAGE_SPACE = "Not Enough Space in this Storage";
const string Storage::AMOUNT_TOO_SMALL = "The given amount is too small";
const string Storage::STOCK_MUST_BE_POSITIVE = "The stock must be positive.";


Storage::Storage(string name, int size_database)
{
    this->size_database = size_database;
    this->name = name;
    article_database = new Article*[size_database];
    article_count = 0;
}




int Storage::find_Article(int articleNr)
{
    for (int i = 0; i < article_count; i++)
    {
        if (article_database[i]->getArticleNr() == articleNr)
            return i;
    }
    return -1;
}




void Storage::change_price(int articleNr, double price)
{

    int position = find_Article(articleNr);


    if (position == -1) throw ARTICLE_NOT_FOUND;
    if(price < 0.0) throw AMOUNT_TOO_SMALL;


    article_database[position]->setprice(price);
}




void Storage::addArticle(int articleNr, double price, string description, int stock = 0)
{
    int existing_articleNr = -1;
    existing_articleNr = find_Article(articleNr);
    if(article_count == size_database)
    {
        throw STORAGE_SPACE;
    }
    else if(existing_articleNr != -1)
    {
        throw ARTICLE_TAKEN;
    }
    else if (articleNr < 1)
    {
        throw ARTICLE_NOT_FOUND;
    }
    else if (stock < 0)
    {
        throw STOCK_MUST_BE_POSITIVE;
    }
    else
    {
        article_database[article_count] = new Article(articleNr, price, stock, description);
        article_count++;
    }
}




void Storage::adjustPriceByPercent(double percent)
{
    double old_price = 0.0;
    double new_price = 0.0;
    double percentage = percent/100;

    for (int i = 0; i < article_count; i++)
    {
        old_price = article_database[i]->getPrice();
        new_price = old_price + (percentage * old_price);
        article_database[i]->setPrice(new_price);
    }
}


void Storage::addQuantity(int articleNr, int amount)
{
    int position = find_Article(articleNr);

    if (position == -1)
    {
        throw ARTICLE_NOT_FOUND;
    }
    else if (amount < 1)
    {
        throw AMOUNT_TOO_SMALL;
    }
    else
    {
        article_database[position]->???;
    }
}


void Storage::removeQuantity(int articleNr, int amount)
{
    int position = find_Article(articleNr);

    if (position == -1)
    {
        throw ARTICLE_NOT_FOUND;
    }
    else if (amount < 1)
    {
        throw AMOUNT_TOO_SMALL;
    }
    else
    {
        article_database[position]->???;
    }
}


void Storage::removeArticle(int articleNr)
{
    int position = find_Article(articleNr);

    if (position == -1)
    {
        throw ARTICLE_NOT_FOUND;
    }
    else
    {
        delete article_database[position];
        for (int i = position; i < size_database; i++)
        {
            article_database[i] = article_database[i+1];
        }
        article_database[size_database-1] = nullptr;
        article_count--;
    }
}


string Storage::getName() const
{
    return this->name;
}

int Storage::getSize_database() const
{
    return this->size_database;
}

int Storage::getArticle_count() const
{
    return this->article_count;
}
