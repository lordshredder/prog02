#pragma once
#include <iostream>
#include <string>
#define STRING_LIMIT 128
using namespace std;



class Article {
    public:
        Article(int articleNr, string description, int stock = 0);
        void addQuantity(int amount);
        void removeQuantity(int amount);
        int getArticleNr();
        int getStock();
        string getDescription();
        void setDescription(string newDescription);
    private:
        int articleNr;
        int stock;
        string description;
};


