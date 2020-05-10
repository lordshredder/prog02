#include <string>
#include "Article.h"
using namespace std;

namespace {
    const int MAX_ARTICLE_ID = 9999;
    const int MIN_ARTICLE_ID = 1000;
    const int MAX_STOCK = 10;
    const int MAX_ARTICLE_DESCRIPTION_SIZE = 20;
    const std::string EMPTY_ARTICLE_DESCRIPTION = "The description cannot be empty.";
    const std::string ARTICLE_DESCRIPTION_REFERENCE_NULL = "The description does not exist.";
    const std::string DESCRIPTION_LIMIT_EXCEEDED = "The description must be smaller than "+std::to_string(MAX_ARTICLE_DESCRIPTION_SIZE);
    const std::string ARTICLE_MUST_BE_FOUR_DIGITS = "The number must be 4 digits and positive.";
    const std::string STOCK_MUST_BE_POSITIVE = "The stock must be positive.";
    const std::string ADD_POSITIVE_QUANTITY_ONLY = "When adding quantity, the amount must be positive.";
    const std::string REMOVE_POSITIVE_QUANTITY_ONLY = "When removing quantity, the amount must be positive.";
    const std::string STOCK_LIMIT_EXCEEDED = "You have exceeded the maximum stock capacity.";
}

Article::Article(int articleNr, const string &description, int stock){
    if (articleNr > MAX_ARTICLE_ID || articleNr < MIN_ARTICLE_ID) {
        throw ARTICLE_MUST_BE_FOUR_DIGITS;
    }
    if (&description == nullptr)
        throw ARTICLE_DESCRIPTION_REFERENCE_NULL;
    if (description.empty()){
        throw EMPTY_ARTICLE_DESCRIPTION;
    }
    if (description.length() > MAX_ARTICLE_DESCRIPTION_SIZE){
        throw DESCRIPTION_LIMIT_EXCEEDED;
    }
    if (stock < 0){
        throw STOCK_MUST_BE_POSITIVE;
    }
    if (stock > MAX_STOCK){
        throw STOCK_MUST_BE_POSITIVE;
    }
    this->articleNr = articleNr;
    this->description = description;
    this->stock = stock;
}

void Article::addQuantity(int amount){
    if (amount < 0){
        throw ADD_POSITIVE_QUANTITY_ONLY;
    }
    if (amount+stock > MAX_STOCK) throw STOCK_LIMIT_EXCEEDED;
    this->stock += amount;
}

void Article::removeQuantity(int amount){
    if (amount < 0){
        throw REMOVE_POSITIVE_QUANTITY_ONLY;
    }
    if (this->stock < amount){
        throw STOCK_MUST_BE_POSITIVE;
    }
    this->stock -= amount;
}

int Article::getArticleNr() const{
    return articleNr;
}

int Article::getStock() const{
    return stock;
}

string Article::getDescription() const{
    return description;
}

void Article::setDescription(const string &newDescription){
    if (&newDescription == nullptr)
        throw ARTICLE_DESCRIPTION_REFERENCE_NULL;

    if (newDescription.length() > MAX_ARTICLE_DESCRIPTION_SIZE){
        throw DESCRIPTION_LIMIT_EXCEEDED;
    }
    if (newDescription.empty()){
        throw EMPTY_ARTICLE_DESCRIPTION;
    }
    this->description = newDescription;
}

void Article::printArticle(const Article &article) {
    cout << "Article: \nID: "
         << article.getArticleNr()
         << "\nName: " << article.getDescription()
         << "\nStock: " << article.getStock() << std::endl;
}