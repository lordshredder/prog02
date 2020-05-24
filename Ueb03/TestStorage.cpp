/**
 *
 *  @file TestStorage.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "TestStorage.h"

const string TestStorage::EMPTY_STORAGE_NAME = "The name cannot be empty.";
const string TestStorage::NAME_LIMIT_EXCEEDED = "The name must be smaller than " + std::to_string(MAX_STORAGE_NAME_SIZE);

TestStorage::TestStorage(string storageName) {
    setName(storageName);
    articles.reserve(STANDARD_STORAGE_SIZE);
}

TestStorage::~TestStorage() {
    delete &articles;
}

bool TestStorage::addArticle(int articleId, const string& articleName, double price, int stock) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) return false;
    articles.emplace_back(articleId, articleName, price, stock);
    return true;
}

int TestStorage::findArticle(int articleId) {
    for (int i = 0; i < articles.size(); i++) {
        if(articles[i].articleNr == articleId) return i;
    }
    return ARTICLE_NOT_FOUND;
}

bool TestStorage::removeArticle(int articleId) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) return false;
    articles.erase(articles.begin() + position);
    return true;
}

bool TestStorage::addQuantity(int articleId, int quantity) {
    return false;
}

bool TestStorage::removeQuantity(int articleId, int quantity) {
    return false;
}

void TestStorage::adjustPriceByPercent(float percent) {
    for (Article& article : articles) {
        article.price *= percent;
    }

}

void TestStorage::adjustPriceByPercent(int articleId, float percent) {
    int position = findArticle(articleId);
    articles[position].price *= percent;
}

string TestStorage::getName() const {
    return storageName;
}

void TestStorage::setName(const string& newName) {
    if (newName.empty()) {
        throw EMPTY_STORAGE_NAME;
    }
    if (newName.length() > MAX_STORAGE_NAME_SIZE) {
        throw NAME_LIMIT_EXCEEDED;
    }
    this->storageName = newName;
}
