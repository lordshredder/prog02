/**
 *
 *  @file ArticleTest.h
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#pragma once
#include "Article.h"
using namespace std;

/**
 * Simple test class for the class Article.
 */
class ArticleTest {
public:
    /**
     * Runs all tests in the following order:
     * - testArticleConstructor
     * - testArticleName
     * - testArticleStock
     */
    void runFullTest();
    /**
     * Prints the provided article.
     * @param article The article to print.
     */
    void printArticle(const Article &article);
    /**
     * Runs all tests that test the constructor.
     */
    void testArticleConstructor();
    /**
     * Runs all tests that test the functions for the article description.
     */
    void testArticleName();
    /**
     * Runs all tests that test the functions for the stock for the artciel.
     */
    void testArticleStock();

    void articleId_is_more_than_four_digits();
    void articleId_is_less_than_four_digits();
    void articleId_is_positive();
    void articleName_is_not_empty();
    void articleName_size_is_smaller_than_limit();
    void articleStock_is_smaller_than_limit();
    void articleStock_is_positive();
    void articleAddQuantity_amount_is_positive();
    void articleAddQuantity_stock_plus_amount_is_smaller_than_limit();
    void articleRemoveQuantity_amount_is_positive();
    void articleRemoveQuantity_stock_minus_amount_is_positive();
    void articleSetDescription_string_is_not_empty();
    void articleSetDescription_string_size_is_smaller_than_limit();
private:
    string testResult;
    static const string TEST_SUCCESS;
    static const string TEST_FAILURE;
};
