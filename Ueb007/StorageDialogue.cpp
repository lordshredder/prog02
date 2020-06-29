/**
 *
 *  @file StorageDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "StorageDialogue.h"
#include "MockInput.h"
#include "Clothing.h"
#include "ElectronicDevice.h"
#include <string>
using namespace std;

const string StorageDialogue::STORAGE_NOT_READY = "Please initialize the storage first.";
const string StorageDialogue::BAD_USER_INPUT = "Invalid input.";

StorageDialogue::StorageDialogue() = default;

StorageDialogue::~StorageDialogue() = default;

void StorageDialogue::startDialogue() {
    while (currentSelection != SELECT_QUIT) {
        try {
            readUserSelection();
            executeSelection(currentSelection);
        } catch (const string& e) {
            clearUserInput();
            cout << "\nERROR: " << e << "\n";
        } catch (std::exception &e) {
            clearUserInput();
            cout << "\nERROR: " << e.what() << std::endl;
        } catch (...) {
            clearUserInput();
            cout << "\nSomething went terribly wrong." << endl;
        }
    }
    cout << "Goodbye." << endl;
}

void StorageDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
         << SELECT_CREATE_STORAGE << " : Create new storage\n"
         << SELECT_SHOW_STORAGE << " : Show the current storage\n"
         << SELECT_SHOW_ARTICLE_COUNT << " : Show the current amount of articles in the storage\n"
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
         << SELECT_TEST_COPY << " : Create then Clone a new article and add it to the storage.\n"
         << SELECT_TEST_EQUALS_OPERATOR << " : Create then set a new article to the created article and add it to the storage.\n"
         << SELECT_CREATE_DUMMY_ARTICLES << " : Create random articles for testing purposes.\n"
         << SELECT_QUIT << " : Quit\n";
    if (safeRead(cin, selection)) {
        currentSelection = static_cast<Select>(selection);
    } else{
        throw StorageException(BAD_USER_INPUT);
    }
}

void StorageDialogue::executeSelection(const Select& selection) {
    if (selection == SELECT_QUIT) return;
    if (selection != SELECT_CREATE_STORAGE) checkStorageState();
    switch (currentSelection) {
        case SELECT_CREATE_STORAGE:
            createStorage();
            break;
        case SELECT_SHOW_STORAGE:
            showStorage();
            break;
        case SELECT_SHOW_ARTICLE_COUNT:
            showArticleAmount();
            break;
        case SELECT_ADD_ARTICLE:
            getTypeOfArticleToAdd();
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
            throw StorageException(BAD_USER_INPUT);
    }

}

void StorageDialogue::createStorage() {
    if (storage != nullptr) {
        storage = nullptr;
    }
    cout << "\nPlease enter a name for the storage, maximum 20 letters:" << endl;
    string name;
    clearUserInput();
    getline(cin, name);
    storage = make_shared<Storage>(name);
    cout << "\nNew storage created. Its name is: " << storage->getName() << endl;
}

void StorageDialogue::getTypeOfArticleToAdd() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
         << SUBSELECT_CREATE_CLOTHING << " : Add new clothing\n"
         << SUBSELECT_CREATE_EDEVICE << " : Add new electronic device\n"
         << SUBSELECT_QUIT << " : Return\n";
    if (safeRead(cin, selection)) {
        addSpecificArticle(static_cast<SubSelect>(selection));
    } else{
        throw StorageException(BAD_USER_INPUT);
    }



}

void StorageDialogue::addSpecificArticle(const SubSelect& articleType) {
    switch (articleType) {
        case SUBSELECT_CREATE_CLOTHING:
            addClothing();
            break;
        case SUBSELECT_CREATE_EDEVICE:
            addElectronicDevice();
            break;
        case SUBSELECT_QUIT:
            break;
        default:
            throw StorageException(BAD_USER_INPUT);
    }
}

void StorageDialogue::addClothing() {
    int articleId = readArticleId();
    string articleDescription;
    string articleColor;
    string articleSize;
    double articlePrice;
    int stock = 0;
    cout << "\nPlease enter an article description with a maximum length of "
         << Article::MAX_ARTICLE_DESCRIPTION_SIZE << ": ";
    getline(cin, articleDescription);
    cout << "\nPlease enter the clothing size with a maximum length of "
         << Clothing::MAX_STRING_ATTRIBUTE_SIZE << " letters: ";
    getline(cin, articleSize);
    cout << "\nPlease enter a color with a maximum length of "
         << Clothing::MAX_STRING_ATTRIBUTE_SIZE << " letters: ";
    getline(cin, articleColor);
    cout << "\nPlease enter a price for the article: ";
    safeRead(cin, articlePrice);
    cout << "\nPlease enter the initial stock for the article, maximum " << Article::MAX_STOCK << ": ";
    safeRead(cin, stock);
    shared_ptr<Clothing> temp = make_shared<Clothing>(articleId, articleDescription, articlePrice, articleSize, articleColor, stock);
    storage->addArticle(temp);
    cout << "\nThe article with the ID: "
         << articleId << " was added successfully." << endl;
}

void StorageDialogue::addElectronicDevice() {
    int articleId = readArticleId();
    string articleDescription;
    double articleWatts;
    double articlePrice;
    int stock = 0;
    cout << "\nPlease enter an article description with a maximum length of "
         << Article::MAX_ARTICLE_DESCRIPTION_SIZE << ": ";
    getline(cin, articleDescription);
    cout << "\nPlease enter a price for the article: ";
    safeRead(cin, articlePrice);
    cout << "\nPlease enter kilowatts per hour for the article: ";
    safeRead(cin, articleWatts);
    cout << "\nPlease enter the initial stock for the article, maximum " << Article::MAX_STOCK << ": ";
    safeRead(cin, stock);
    shared_ptr<ElectronicDevice> temp = make_shared<ElectronicDevice>(articleId, articleDescription, articlePrice, articleWatts, stock);
    storage->addArticle(temp);
    cout << "\nThe article with the ID: "
         << articleId << " was added successfully." << endl;
}

void StorageDialogue::removeArticle() {
    int articleId = readArticleId();
    storage->removeArticle(articleId);
    cout << "\nThe article with the ID: "
         << articleId << " was removed successfully." << endl;
}

void StorageDialogue::printArticle() {
    int articleId = readArticleId();
    storage->printArticle(articleId);
}

void StorageDialogue::listArticles() {
    storage->printArticles();
}

int StorageDialogue::readArticleId() {
    int articleId = -1;
    cout << "\nPlease enter an article ID consisting of 4 digits: ";
    safeRead(cin, articleId);
    clearUserInput();
    return articleId;
}

void StorageDialogue::addQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    safeRead(cin, quantity);
    storage->addQuantity(articleId, quantity);
    cout << "\nThe article with the ID: "
         << articleId << " has had its stock increased by "
         << quantity  << "." << endl;
}

void StorageDialogue::removeQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    safeRead(cin, quantity);
    storage->removeQuantity(articleId, quantity);
    clearUserInput();
    cout << "\nThe article with the ID: "
         << articleId << " has had its stock decreased by "
         << quantity  << "." << endl;
}

void StorageDialogue::setArticleName() {
    int articleId = readArticleId();
    string newDescription;
    cout << "\nPlease enter a new name for the article:";
    getline(cin, newDescription);
    storage->setArticleName(articleId, newDescription);
    cout << "The name of the article with ID: "
         << articleId << " has been changed to "
         << newDescription << "." << endl;
}

void StorageDialogue::setPrice() {
    int articleId = readArticleId();
    long double newPrice = 0;
    cout << "\nPlease enter a new price:";
    safeRead(cin, newPrice);
    storage->setPrice(articleId, newPrice);
    cout << "Price of the article with ID: "
         << articleId << " has been changed to "
         << newPrice << "." << endl;
}

void StorageDialogue::adjustPrice() {
    int articleId = readArticleId();
    long double percent = 0;
    cout << "\nPlease enter a percentage in the following format:"
         << "\n50.3 -> increases the price by 50.3%"
         << "\n-18 -> decreases the price by 18.0%\n";
    safeRead(cin, percent);
    storage->adjustPriceByPercent(articleId, percent);
    clearUserInput();
    cout << "Price of the article with ID: "
         << articleId << " adjusted by " << percent << "%." << endl;
}

void StorageDialogue::adjustPrices() {
    long double percent = 0;
    cout << "\nPlease enter a percentage in the following format:"
         << "\n50.3 -> increases the price by 50.3%"
         << "\n-18 -> decreases the price by 18.0%\n";
    safeRead(cin, percent);
    storage->adjustPriceByPercent(percent);
    clearUserInput();
    cout << "Prices of all articles adjusted by " << percent << "%." << endl;
}

void StorageDialogue::checkStorageState() {
    if(storage == nullptr) throw STORAGE_NOT_READY;
}

void StorageDialogue::showStorage() {
    cout << *storage << endl;
}

void StorageDialogue::showArticleAmount() {
    cout << "The storage "
         << storage->getName()
         << " contains "
         << storage->getArticleAmount()
         << " articles." << endl;
}

void StorageDialogue::copyArticle() {
    int articleId = 1000 + storage->getArticleAmount();
    shared_ptr<Article> article = make_shared<Clothing>(articleId, "CopyTest", 0.0,"CopySIZE", "Blue", 5);
    cout << "\nThe article with the ID: "
         << articleId << " was created. Attempting to copy..." << endl;
    shared_ptr<Article> copy = article->copy();
    storage->addArticle(copy);
    cout << "\nThe article with the ID: "
         << articleId << " was copied and added successfully." << endl;
}

void StorageDialogue::testEqualArticle() {
    int articleId = 1000 + storage->getArticleAmount();
    int articleId2 = articleId+1;
    cout << "Creating two sample clothing articles..." << endl;

    shared_ptr<Clothing> equalsTest1 = make_shared<Clothing>(articleId, "equalsTest1", 0.0, "equal S", "Equal1", 3);
    shared_ptr<Clothing> equalsTest2 = make_shared<Clothing>(articleId2, "equalsTest2", 55.0, "equal XL", "Equal2", 6);

    cout << "Created Articles:\n" << *equalsTest1 << endl << *equalsTest2 << endl;
    cout << "\nAttempting Clothing equalsTest2 = equalsTest1..." << endl;
    *equalsTest2 = *equalsTest1;
    cout << "Result:\n" << *equalsTest1 << endl << *equalsTest2 << endl;
    storage->addArticle(equalsTest2);
    cout << "\n" << equalsTest2->getDescription() << " with the ID: "
         << equalsTest2->getArticleNr() << " was set and added successfully." << endl;
}

void StorageDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}

void StorageDialogue::createDummyArticles() {
    MockInput mock;
    const int maxLetters = Article::MAX_ARTICLE_DESCRIPTION_SIZE;
    int stock = 1;
    int articleId = 1000 + storage->getArticleAmount();

    for (int i = 0; i < AMOUNT_DUMMY_ARTICLES; ++i) {
        int power = mock.RandomNumber(800, 10);
        string size = mock.RandomString(3, 1);
        string color = mock.RandomString(8, 5);
        string articleDesc = mock.RandomString(maxLetters, 9);
        long double price = mock.RandomNumber(250.0L, 10.5L);
        float roundedPrice = (float)((int)(price * 100 + 0.5f))/100;
        if (mock.RandomNumber(1,0) > 0){
            storage->addArticle(make_shared<Clothing>(articleId, articleDesc, roundedPrice, size, color, stock));
        } else{
            storage->addArticle(make_shared<ElectronicDevice>(articleId, articleDesc, roundedPrice, power, stock));
        }
        articleId++;
    }
    cout << AMOUNT_DUMMY_ARTICLES
         << " articles with random values have been created and added to the storage "
         << storage->getName()  << "." << endl;
}
