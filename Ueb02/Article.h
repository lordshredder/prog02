#pragma once
#include <iostream>
#include <string>
using namespace std;



class Article {
public:
    Article(int articleNr, const string& description, int stock = 0);

    void addQuantity(int amount);

    void removeQuantity(int amount);

    int getArticleNr() const;

    int getStock() const;

    string getDescription() const;

    void printArticle(const Article &article);

    void setDescription(const string& newDescription);

private:
    int articleNr;
    int stock;
    string description;
};


