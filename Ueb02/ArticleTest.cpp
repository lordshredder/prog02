#include "ArticleTest.h"
#include <iostream>

namespace {
    const std::string SUCCESS = "\nS U C C E S S, message: ";
    const std::string FAILURE = "\n----- F A I L E D -----\n";

}

void ArticleTest::runFullTest() {
    try {
        Article* article = new Article(1122,"777");
        printArticle(*article);
        testArticleConstructor();
        testArticleName();
        testArticleStock();
    } catch (const string& e) {
        cout << e << endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }catch (...) {
        std::cout << "error" << std::endl;

    }

}

void ArticleTest::testArticleConstructor() {
    articleId_is_positive();
    articleId_is_more_than_four_digits();
    articleId_is_less_than_four_digits();
    articleName_is_not_null();
    articleName_is_not_empty();
    articleName_size_is_smaller_than_limit();
    articleStock_is_positive();
    articleStock_is_smaller_than_limit();
}

void ArticleTest::testArticleName() {

    articleSetDescription_string_is_not_null();
    articleSetDescription_string_is_not_empty();
    articleSetDescription_string_size_is_smaller_than_limit();

}

void ArticleTest::testArticleStock() {
    articleAddQuantity_amount_is_positive();
    articleAddQuantity_stock_plus_amount_is_smaller_than_limit();
    articleRemoveQuantity_amount_is_positive();
    articleRemoveQuantity_stock_minus_amount_is_positive();
}

void ArticleTest::articleId_is_more_than_four_digits() {
    testResult = FAILURE;
    try {
        Article* test = new Article(10000, "test");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleId_is_more_than_four_digits " << testResult << endl;
}

void ArticleTest::articleId_is_less_than_four_digits() {
    testResult = FAILURE;
    try {
        Article* test = new Article(999, "test");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleId_is_less_than_four_digits " << testResult << endl;
}

void ArticleTest::articleId_is_positive() {
    testResult = FAILURE;
    try {
        Article* test = new Article(-1999, "test");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleId_is_positive " << testResult << endl;
}

void ArticleTest::articleName_is_not_empty() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleName_is_not_empty " << testResult << endl;
}

void ArticleTest::articleName_is_not_null() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, nullptr);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleName_is_not_null " << testResult << endl;
}

void ArticleTest::articleName_size_is_smaller_than_limit() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "012345678901234567891");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleName_size_is_smaller_than_limit " << testResult << endl;
}

void ArticleTest::articleStock_is_smaller_than_limit() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 500000);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleStock_is_smaller_than_limit " << testResult << endl;
}

void ArticleTest::articleStock_is_positive() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", -555);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleStock_is_positive " << testResult << endl;
}

void ArticleTest::articleAddQuantity_amount_is_positive() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test");
        test->addQuantity(5);
        test->addQuantity(-5);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleAddQuantity_amount_is_positive " << testResult << endl;
}

void ArticleTest::articleAddQuantity_stock_plus_amount_is_smaller_than_limit() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test");
        test->addQuantity(11);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleAddQuantity_stock_plus_amount_is_smaller_than_limit " << testResult << endl;
}

void ArticleTest::articleRemoveQuantity_amount_is_positive() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 10);
        test->removeQuantity(-5);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleRemoveQuantity_amount_is_positive " << testResult << endl;
}

void ArticleTest::articleRemoveQuantity_stock_minus_amount_is_positive() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 10);
        test->removeQuantity(-15);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleRemoveQuantity_stock_minus_amount_is_positive " << testResult << endl;
}

void ArticleTest::articleSetDescription_string_is_not_null() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 10);
        test->setDescription(nullptr);
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleSetDescription_string_is_not_null " << testResult << endl;
}

void ArticleTest::articleSetDescription_string_is_not_empty() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 10);
        test->setDescription("");
    }  catch (const string& e) {

        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleSetDescription_string_is_not_empty " << testResult << endl;
}

void ArticleTest::articleSetDescription_string_size_is_smaller_than_limit() {
    testResult = FAILURE;
    try {
        Article* test = new Article(1999, "Test", 10);
        test->setDescription("012345678901234567890");
    }  catch (const string& e) {
        testResult = SUCCESS + e + "\n";
    } catch (std::exception &e) {
        testResult += e.what();
    } catch (...) {
        testResult += "Unknown exception";
    }
    cout << "\narticleSetDescription_string_size_is_smaller_than_limit " << testResult << endl;
}

void ArticleTest::printArticle(const Article &article) {
    cout << "Article: \nID: "
    << article.getArticleNr()
    << "\nName: " << article.getDescription()
    << "\nStock: " << article.getStock() << std::endl;
}
