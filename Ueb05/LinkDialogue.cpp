/**
 *
 *  @file LinkDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "LinkDialogue.h"
#include <string>
using namespace std;

const string LinkDialogue::LIST_NOT_READY = "Please initialize the list first.";
const string LinkDialogue::BAD_USER_INPUT = "Invalid input.";

LinkDialogue::LinkDialogue() {

}

LinkDialogue::~LinkDialogue() {
    delete list;
}

void LinkDialogue::startDialogue() {
    while (currentSelection != SELECT_QUIT) {
        try {
            readUserSelection();
            executeSelection(currentSelection);
        } catch (const string& e) {
            clearUserInput();
            cout << "\nERROR: " << e << "\n";
        } catch (std::exception &e) {
            clearUserInput();
            cout << e.what() << std::endl;
        } catch (...) {
            clearUserInput();
            cout << "\nSomething went terribly wrong." << endl;
        }
    }
    cout << "Goodbye." << endl;
}

void LinkDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
         << SELECT_CREATE_LIST << " : Create new list\n"
         << SELECT_SHOW_LIST << " : Show the current list\n"
         << SELECT_SHOW_ARTICLE_COUNT << " : Show the current amount of articles in the list\n"
         << SELECT_ADD_ARTICLE << " : Add new article\n"
         << SELECT_REMOVE_ARTICLE << " : Remove existing article\n"
         << SELECT_SHOW_ARTICLE << " : Print article\n"
         << SELECT_SHOW_ARTICLES << " : Print all articles\n"
         << SELECT_ADD_QUANTITY << " : Add stock to article\n"
         << SELECT_REMOVE_QUANTITY << " : Remove stock from article\n"
         << SELECT_SET_NAME << " : Set name of article\n"
         << SELECT_SET_PRICE << " : Set Price of article\n"
         << SELECT_ADJUST_PRICE << " : Adjust Price of article\n"
         << SELECT_ADJUST_PRICE_ALL << " : Adjust Price of all articles\n"
         << SELECT_TEST_COPY << " : Create then Clone a new article and add it to the list.\n"
         << SELECT_TEST_EQUALS_OPERATOR << " : Create then set a new article to the created article and add it to the list.\n"
         << SELECT_CREATE_DUMMY_ARTICLES << " : Create random articles for testing purposes.\n"
         << SELECT_QUIT << " : Quit\n";
    if (safeRead(cin, selection)) {
        currentSelection = static_cast<Select>(selection);
    } else{
        throw BAD_USER_INPUT;
    }
}

void LinkDialogue::executeSelection(const Select& selection) {
    if (selection == SELECT_QUIT) return;
    if (selection != SELECT_CREATE_LIST) checkListState();
    switch (currentSelection) {
        case SELECT_SHOW_LIST:
            showList();
            break;
        case SELECT_ADD_ARTICLE:
            addArticle();
            break;
        case SELECT_REMOVE_ARTICLE:
            removeArticle();
            break;
        case SELECT_SHOW_ARTICLE:
            printArticle();
            break;
        case SELECT_SHOW_ARTICLES:
            listArticles();
            break;
        case SELECT_ADD_QUANTITY:
            addQuantity();
            break;
        case SELECT_REMOVE_QUANTITY:
            removeQuantity();
            break;
        case SELECT_SET_NAME:
            setArticleName();
            break;
        case SELECT_SET_PRICE:
            setPrice();
            break;
        case SELECT_ADJUST_PRICE:
            adjustPrice();
            break;
        case SELECT_ADJUST_PRICE_ALL:
            adjustPrices();
            break;
        case SELECT_TEST_COPY:
            copyArticle();
            break;
        case SELECT_TEST_EQUALS_OPERATOR:
            testEqualArticle();
            break;
        case SELECT_CREATE_DUMMY_ARTICLES:
            createDummyArticles();
            break;
        default:
            throw BAD_USER_INPUT;
    }

}

void LinkDialogue::addArticle() {
    int articleId = readArticleId();
    string articleDescription;
    cout << "\nPlease enter an article description with a maximum length of "
         << ListElement::MAX_CONTENT_SIZE << ": ";
    getline(cin, articleDescription);
    cout << "\nThe article with the ID: "
         << articleId << " was added successfully." << endl;
}

void LinkDialogue::removeArticle() {
    int articleId = readArticleId();
    //list->removeArticle(articleId);
    cout << "\nThe article with the ID: "
         << articleId << " was removed successfully." << endl;
}

void LinkDialogue::printArticle() {
    int articleId = readArticleId();
    //list->printArticle(articleId);
}

void LinkDialogue::listArticles() {
    //list->printArticles();
}

int LinkDialogue::readArticleId() {
    int articleId = -1;
    cout << "\nPlease enter an article ID consisting of 4 digits: ";
    safeRead(cin, articleId);
    clearUserInput();
    return articleId;
}

void LinkDialogue::addQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    safeRead(cin, quantity);
    //list->addQuantity(articleId, quantity);
    cout << "\nThe article with the ID: "
         << articleId << " has had its stock increased by "
         << quantity  << "." << endl;
}

void LinkDialogue::removeQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    safeRead(cin, quantity);
    //list->removeQuantity(articleId, quantity);
    clearUserInput();
    cout << "\nThe article with the ID: "
         << articleId << " has had its stock decreased by "
         << quantity  << "." << endl;
}

void LinkDialogue::setArticleName() {
    int articleId = readArticleId();
    string newDescription;
    cout << "\nPlease enter a new name for the article:";
    clearUserInput();
    getline(cin, newDescription);
    //list->setArticleName(articleId, newDescription);
    cout << "The name of the article with ID: "
         << articleId << " has been changed to "
         << newDescription << "." << endl;
}

void LinkDialogue::setPrice() {
    int articleId = readArticleId();
    long double newPrice = 0;
    cout << "\nPlease enter a new price:";
    cin >> newPrice;
    safeRead(cin, newPrice);
    //list->setPrice(articleId, newPrice);
    clearUserInput();
    cout << "Price of the article with ID: "
         << articleId << " has been changed to "
         << newPrice << "." << endl;
}

void LinkDialogue::adjustPrice() {
    int articleId = readArticleId();
    long double percent = 0;
    cout << "\nPlease enter a percentage in the following format:"
         << "\n50.3 -> increases the price by 50.3%"
         << "\n-18 -> decreases the price by 18.0%\n";
    safeRead(cin, percent);
   // list->adjustPriceByPercent(articleId, percent);
    clearUserInput();
    cout << "Price of the article with ID: "
         << articleId << " adjusted by " << percent << "%." << endl;
}

void LinkDialogue::adjustPrices() {
    long double percent = 0;
    cout << "\nPlease enter a percentage in the following format:"
         << "\n50.3 -> increases the price by 50.3%"
         << "\n-18 -> decreases the price by 18.0%\n";
    safeRead(cin, percent);
    //list->adjustPriceByPercent(percent);
    clearUserInput();
    cout << "Prices of all articles adjusted by " << percent << "%." << endl;
}

void LinkDialogue::checkListState() {
    if(list == nullptr) throw LIST_NOT_READY;
}

void LinkDialogue::showList() {
    cout << *list << endl;
}

void LinkDialogue::copyArticle() {
    ListElement* article = new ListElement("CopyTest", nullptr, nullptr);
   /* cout << "\nThe article with the ID: "
         << articleId << " was created. Attempting to copy..." << endl;*/
   // ListElement* copy = article->copy();
    //list->addArticle((*copy));
/*    cout << "\nThe article with the ID: "
         << articleId << " was copied and added successfully." << endl;*/
}

void LinkDialogue::testEqualArticle() {
/*    int articleId = 1000 + list->getArticleAmount();
    Article* article = new Article(articleId, "equalsTest", 0.0, 5);
    cout << "\nThe article with the ID: "
         << articleId << " was created. Attempting Article* copy = article..." << endl;
    Article* copy = article;
    list->addArticle((*copy));
    cout << "\nThe article with the ID: "
         << articleId << " was set and added successfully." << endl;*/
}

void LinkDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}

void LinkDialogue::createDummyArticles() {
/*    MockInput mock;
    int stock = 1;
    int articleId = 1000 + list->getArticleAmount();
    for (int i = 0; i < AMOUNT_DUMMY_ARTICLES; ++i) {
        string articleDesc = mock.RandomString(20, 9);
        long double price = mock.RandomNumber(250.0L, 10.5L);
        float roundedPrice = (float)((int)(price * 100 + 0.5f))/100;
        list->addArticle(articleId, articleDesc, roundedPrice, stock);
        articleId++;
    }
    cout << AMOUNT_DUMMY_ARTICLES
         << " articles with random values have been created and added to the list "
         << list->getName() << "." << endl;*/
}
