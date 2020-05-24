/**
 *
 *  @file TestStorage.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Article.h"
using namespace std;

class TestStorage {
public:
    TestStorage() = delete;
    explicit TestStorage(string storageName);
    ~TestStorage();
    bool addArticle(int articleId, const string& articleName, double price, int stock = 0);
    bool removeArticle(int articleId);
    bool addQuantity(int articleId, int quantity);
    bool removeQuantity(int articleId, int quantity);
    void adjustPriceByPercent(float percent);
    void adjustPriceByPercent(int articleId, float percent);
    string getName() const;
    void setName(const string& newName);

private:
    static const int STANDARD_STORAGE_SIZE = 20;
    static const int ARTICLE_NOT_FOUND = -1;
    static const int MAX_STORAGE_NAME_SIZE = 20;
    static const std::string EMPTY_STORAGE_NAME;
    static const std::string NAME_LIMIT_EXCEEDED;
    string storageName;
    vector<Article> articles;
    int findArticle(int articleId);
};

