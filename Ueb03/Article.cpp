/**
 *
 *  @file Article.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#include <string>
#include <sstream>
#include "Article.h"

const string Article::EMPTY_ARTICLE_DESCRIPTION = "The description cannot be empty.";
const string Article::DESCRIPTION_LIMIT_EXCEEDED = "The description must be smaller than "+std::to_string(MAX_ARTICLE_DESCRIPTION_SIZE);
const string Article::ARTICLE_MUST_BE_FOUR_DIGITS = "The number must be 4 digits and positive.";
const string Article::STOCK_MUST_BE_POSITIVE = "The stock must be positive.";
const string Article::PRICE_MUST_BE_POSITIVE = "The price must be positive.";
const string Article::ADD_POSITIVE_QUANTITY_ONLY = "When adding quantity, the amount must be positive.";
const string Article::REMOVE_POSITIVE_QUANTITY_ONLY = "When removing quantity, the amount must be positive.";
const string Article::STOCK_LIMIT_EXCEEDED = "You have exceeded the maximum stock capacity.";

Article::Article(int articleNr, const string &description, long double price, int stock) {
    if (articleNr > MAX_ARTICLE_ID || articleNr < MIN_ARTICLE_ID) {
        throw ARTICLE_MUST_BE_FOUR_DIGITS;
    }
    if (stock < 0) {
        throw STOCK_MUST_BE_POSITIVE;
    }
    if (stock > MAX_STOCK) {
        throw STOCK_MUST_BE_POSITIVE;
    }
    setDescription(description);
    setPrice(price);
    this->articleNr = articleNr;
    this->stock = stock;
}

Article::Article(const Article &article) :
articleNr(article.articleNr), description(article.description),
price(article.price), stock(article.stock)
{
    cout << "DEBUG CHECK: Article copy constructor called" << endl;
}

Article::~Article() {
    cout << "DEBUG CHECK: Article destructor called" << endl;
}

void Article::addQuantity(int amount) {
    if (amount < 0) {
        throw ADD_POSITIVE_QUANTITY_ONLY;
    }
    if (amount+stock > MAX_STOCK) throw STOCK_LIMIT_EXCEEDED;
    this->stock += amount;
}

void Article::removeQuantity(int amount) {
    if (amount < 0) {
        throw REMOVE_POSITIVE_QUANTITY_ONLY;
    }
    if (this->stock < amount) {
        throw STOCK_MUST_BE_POSITIVE;
    }
    this->stock -= amount;
}

int Article::getArticleNr() const {
    return articleNr;
}

int Article::getStock() const {
    return stock;
}

string Article::getDescription() const {
    return description;
}

long double Article::getPrice() const {
    return price;
}

void Article::setDescription(const string &newDescription) {
    if (newDescription.empty()) {
        throw EMPTY_ARTICLE_DESCRIPTION;
    }
    if (newDescription.length() > MAX_ARTICLE_DESCRIPTION_SIZE) {
        throw DESCRIPTION_LIMIT_EXCEEDED;
    }
    this->description = newDescription;
}

void Article::setPrice(const long double& newPrice) {
    if (newPrice < 0.0) {
        throw PRICE_MUST_BE_POSITIVE;
    }
    this->price = newPrice;
}

Article *Article::copy() const {
    return new Article(*this);
}

string Article::toString() const {
    int space = 32;
    ostringstream oStr;
    oStr << "Article Number: " << articleNr << "\t"
    << "Name: "  << description << std::setw(space-description.length()) << "\t"
    << "Price: " << setprecision(2) << fixed << left << price << right <<" EUR\t"
    << "Current Stock: " << stock;
    return oStr.str();
}

ostream& operator<<(ostream& stream, const Article& article) {
    return stream << article.toString();
}

