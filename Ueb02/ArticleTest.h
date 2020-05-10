#pragma once
#include "Article.h"

class ArticleTest {
public:
    void runFullTest();
    void printArticle(const Article &article);
    void testArticleConstructor();
    void testArticleName();
    void testArticleStock();
    void articleId_is_more_than_four_digits();
    void articleId_is_less_than_four_digits();
    void articleId_is_positive();
    void articleName_is_not_empty();
    void articleName_is_not_null();
    void articleName_size_is_smaller_than_limit();
    void articleStock_is_smaller_than_limit();
    void articleStock_is_positive();
    void articleAddQuantity_amount_is_positive();
    void articleAddQuantity_stock_plus_amount_is_smaller_than_limit();
    void articleRemoveQuantity_amount_is_positive();
    void articleRemoveQuantity_stock_minus_amount_is_positive();
    void articleSetDescription_string_is_not_null();
    void articleSetDescription_string_is_not_empty();
    void articleSetDescription_string_size_is_smaller_than_limit();
private:
    std::string testResult;
};
