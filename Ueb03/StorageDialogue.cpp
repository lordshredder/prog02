/**
 *
 *  @file StorageDialogue.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */

#include "StorageDialogue.h"
#include "MockInput.h"

const string StorageDialogue::STORAGE_NOT_READY = "Please initialize the storage first.";
const string StorageDialogue::BAD_USER_INPUT = "Invalid input.";

StorageDialogue::StorageDialogue() {

}

StorageDialogue::~StorageDialogue() {
    delete storage;
}

void StorageDialogue::startDialogue() {
    while (currentSelection != SelectQuit) {
        try {
            readUserSelection();
            executeSelection(currentSelection);
        } catch (const string& e) {
            clearUserInput();
            cout << "\nERROR: " << e << "\n";
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            cout << "\nSomething went terribly wrong." << endl;
        }
    }
    cout << "Goodbye." << endl;
}

void StorageDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
    << SelectCreateStorage << " : Create new storage\n"
    << SelectShowStorage << " : Show the current storage\n"
    << SelectShowArticleCount << " : Show the current amount of articles in the storage\n"
    << SelectAddArticle << " : Add new article\n"
    << SelectRemoveArticle << " : Remove existing article\n"
    << SelectShowArticle << " : Print article\n"
    << SelectShowArticles << " : Print all articles\n"
    << SelectAddQuantity << " : Add stock to article\n"
    << SelectRemoveQuantity << " : Remove stock from article\n"
    << SelectSetName << " : Set name of article\n"
    << SelectSetPrice << " : Set Price of article\n"
    << SelectAdjustPrice << " : Adjust Price of article\n"
    << SelectAdjustPriceAll << " : Adjust Price of all articles\n"
    << SelectTestCopyConstructor << " : Create then Clone a new article and add it to the storage.\n"
    << SelectCreateTestArticles << " : Create random articles for testing purposes.\n"
    << SelectQuit << " : Quit\n";
    if (cin >> selection) {
        currentSelection = static_cast<Select>(selection);
    } else{
        throw BAD_USER_INPUT;
    }
}

void StorageDialogue::executeSelection(const Select& selection) {
    if (selection == SelectQuit) return;
    if (selection != SelectCreateStorage) checkStorageState();
    switch (currentSelection) {
        case SelectCreateStorage:
            createStorage();
            break;
        case SelectShowStorage:
            showStorage();
            break;
        case SelectShowArticleCount:
            showArticleAmount();
            break;
        case SelectAddArticle:
            addArticle();
            break;
        case SelectRemoveArticle:
            removeArticle();
            break;
        case SelectShowArticle:
            printArticle();
            break;
        case SelectShowArticles:
            listArticles();
            break;
        case SelectAddQuantity:
            addQuantity();
            break;
        case SelectRemoveQuantity:
            removeQuantity();
            break;
        case SelectSetName:
            setArticleName();
            break;
        case SelectSetPrice:
            setPrice();
            break;
        case SelectAdjustPrice:
            adjustPrice();
            break;
        case SelectAdjustPriceAll:
            adjustPrices();
            break;
        case SelectTestCopyConstructor:
            copyArticle();
            break;
        case SelectCreateTestArticles:
            createDummyArticles();
            break;
        default:
            throw BAD_USER_INPUT;
    }

}

void StorageDialogue::createStorage() {
    if (storage != nullptr) delete storage;
    char name[Storage::MAX_STORAGE_NAME_SIZE];
    cout << "\nPlease enter a name for the storage, maximum 20 letters:" << endl;
    cin >> name;
    storage = new Storage(name);
    clearUserInput();
    cout << "\nNew storage created. Its name is: " << storage->getName() << endl;
}

void StorageDialogue::addArticle() {
    int articleId = readArticleId();
    string articleDescription;
    double articlePrice;
    int stock = 0;
    cout << "\nPlease enter an article description with a maximum length of "
    << Article::MAX_ARTICLE_DESCRIPTION_SIZE << ": ";
    cin >> articleDescription;
    clearUserInput();
    cout << "\nPlease enter a price for the article: ";
    cin >> articlePrice;
    clearUserInput();
    cout << "\nPlease enter the initial stock for the article, maximum " << Article::MAX_STOCK << ": ";
    cin >> stock;
    storage->addArticle(articleId, articleDescription, articlePrice, stock);
    clearUserInput();
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
    cin >> articleId;
    clearUserInput();
    return articleId;
}

void StorageDialogue::addQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    cin >> quantity;
    storage->addQuantity(articleId, quantity);
    clearUserInput();
    cout << "\nThe article with the ID: "
    << articleId << " has had its stock increased by "
    << quantity  << "." << endl;
}

void StorageDialogue::removeQuantity() {
    int articleId = readArticleId();
    int quantity = 0;
    cout << "\nPlease enter a quantity: ";
    cin >> quantity;
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
    cin >> newDescription;
    storage->setArticleName(articleId, newDescription);
    clearUserInput();
    cout << "The name of the article with ID: "
    << articleId << " has been changed to "
    << newDescription << "." << endl;
}

void StorageDialogue::setPrice() {
    int articleId = readArticleId();
    long double newPrice = 0;
    cout << "\nPlease enter a new price:";
    cin >> newPrice;
    storage->setPrice(articleId, newPrice);
    clearUserInput();
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
    cin >> percent;
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
    cin >> percent;
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
    Article* article = new Article(articleId, "CopyTest", 0.0, 5);
    cout << "\nThe article with the ID: "
         << articleId << " was created. Attempting to copy..." << endl;
    Article* copy = article->copy();
    storage->addArticle((*copy));
    cout << "\nThe article with the ID: "
         << articleId << " was copied and added successfully." << endl;
}

void StorageDialogue::clearUserInput() {
    char c;
    cin.clear();
    while (cin.get(c) && c != '\n');
}

void StorageDialogue::createDummyArticles() {
    MockInput mock;
    int stock = 1;
    int articleId = 1000 + storage->getArticleAmount();
    for (int i = 0; i < AMOUNT_DUMMY_ARTICLES; ++i) {
        string articleDesc = mock.RandomString(20, 9);
        long double price = mock.RandomNumber(250.0L, 10.5L);
        float roundedPrice = (float)((int)(price * 100 + 0.5f))/100;
        storage->addArticle(articleId, articleDesc, roundedPrice, stock);
        articleId++;
    }
    cout << AMOUNT_DUMMY_ARTICLES
    << " articles with random values have been created and added to the storage "
    << storage->getName()  << "." << endl;
}
