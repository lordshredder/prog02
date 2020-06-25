/**
 *
 *  @file Storage.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "Storage.h"
using namespace std;

const string Storage::EMPTY_STORAGE_NAME = "The name cannot be empty.";
const string Storage::NAME_LIMIT_EXCEEDED = "The name must be smaller than " + std::to_string(MAX_STORAGE_NAME_SIZE);
const string Storage::ARTICLE_DOES_NOT_EXIST = "The article with this ID does not exist.";
const string Storage::ARTICLE_ID_ALREADY_EXISTS = "The article ID is already in use.";

Storage::Storage(const string& storageName) {
    setName(storageName);
    articles.reserve(STANDARD_STORAGE_SIZE);
}

Storage::Storage(const Storage &storage) {
    cout << "DEBUG CHECK: Storage copy constructor called..." << endl;
    cout << "Memory Address of article to be copied: " << &storage << endl;
    cout << "Memory Address of new article: " << this << endl;
    this->storageName = storage.storageName;
    articles.reserve(STANDARD_STORAGE_SIZE);
    for (auto article : storage.articles) {
        articles.push_back(article->copy());
    }
}

Storage::~Storage() {
    cout << "DEBUG CHECK: Storage destructor called." << endl;
    int count = articles.size();
    deleteStorage();
    cout << "Deleted storage " << storageName
         << " which stored " << count << " exotic articles." << endl;
}

Storage &Storage::operator=(const Storage &storage) {
    cout << "DEBUG CHECK: Storage operator= called." << endl;
    if (this == &storage) return *this;
    deleteStorage();
    this->storageName = storage.storageName;
    for (auto article : storage.articles) {
        articles.push_back(article->copy());
    }
    return *this;
}

void Storage::addArticle(Article& article) {
    int position = findArticle(article.articleNr);
    if (position != ARTICLE_NOT_FOUND) throw ARTICLE_ID_ALREADY_EXISTS;
    articles.push_back(&article);
}

void Storage::addArticle(int articleId, const string& articleName, long double price, int stock) {
    int position = findArticle(articleId);
    if (position != ARTICLE_NOT_FOUND) throw ARTICLE_ID_ALREADY_EXISTS;
    auto article = new Article(articleId, articleName, price, stock);
    articles.push_back(article);
}

void Storage::removeArticle(int articleId) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    delete articles[position];
    articles.erase(articles.begin() + position);
}

void Storage::addQuantity(int articleId, int quantity) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    articles[position]->addQuantity(quantity);
}

void Storage::removeQuantity(int articleId, int quantity) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    articles[position]->removeQuantity(quantity);
}

void Storage::adjustPriceByPercent(long double percent) {
    long double actualPercent = 1.0f + percent/100.0f;
    long double newPrice = 0.0L;
    for (auto article : articles) {
        newPrice = article->price * actualPercent;
        article->setPrice(newPrice);
    }
}

void Storage::adjustPriceByPercent(int articleId, long double percent) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    long double actualPercent = 1.0f + percent/100.0f;
    long double newPrice = articles[position]->price * actualPercent;
    articles[position]->setPrice(newPrice);
}

string Storage::getName() const {
    return storageName;
}

int Storage::getArticleAmount() const {
    return articles.size();
}

void Storage::printArticle(int articleId) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    cout << endl << *articles[position] << endl;
}

void Storage::printArticles() {
    for (const auto article : articles) {
        cout << *article << endl;
    }
}

void Storage::setName(const string& newName) {
    if (newName.empty()) {
        throw EMPTY_STORAGE_NAME;
    }
    if (newName.length() > MAX_STORAGE_NAME_SIZE) {
        throw NAME_LIMIT_EXCEEDED;
    }
    this->storageName = newName;
}

void Storage::setPrice(int articleId, long double newPrice) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    articles[position]->setPrice(newPrice);
}

void Storage::setArticleName(int articleId, const string& newDescription) {
    int position = findArticle(articleId);
    if (position == ARTICLE_NOT_FOUND) throw ARTICLE_DOES_NOT_EXIST;
    articles[position]->setDescription(newDescription);
}

string Storage::toString() const {
    ostringstream oStr;
    oStr << "Storage Name: " << storageName << "\t"
         << "Number of Articles: " << getArticleAmount() << endl;
    if (articles.size() < 1) return oStr.str();
    oStr << "Articles: " << endl;
    for (auto article : articles) {
        oStr << *article << endl;
    }
    oStr << endl;
    return oStr.str();
}

int Storage::findArticle(const int& articleId) {
    int count = articles.size();
    for (int i = 0; i < count; ++i) {
        if(articles[i]->articleNr == articleId) return i;
    }
    return ARTICLE_NOT_FOUND;
}

void Storage::deleteStorage() {
    for (auto i = articles.begin(); i != articles.end(); ++i) {
        delete (*i);
    }
}

ostream& operator<<(ostream& stream, const Storage& storage) {
    return stream << storage.toString();
}
