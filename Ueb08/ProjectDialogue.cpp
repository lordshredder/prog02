/**
 *
 *  @file ProjectDialogue.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "ProjectDialogue.h"
#include "safeRead.h"
#include "Task.h"
#include "Product.h"
#include <string>

using namespace std;

const string ProjectDialogue::PROJECT_NOT_READY = "Please initialize and select a project first.";
const string ProjectDialogue::BAD_USER_INPUT = "Invalid input.";
const string ProjectDialogue::ID_DOES_NOT_EXIST = "ID does not exist.";

ProjectDialogue::ProjectDialogue() = default;

ProjectDialogue::~ProjectDialogue() = default;

void ProjectDialogue::startDialogue() {
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

void ProjectDialogue::readUserSelection() {
    int selection = -1;
    cout << "\nPlease Select an option by entering a valid number:\n"
         << SELECT_CREATE_PROJECT << " : Create new project\n"
         << SELECT_CREATE_TASK << " : Create new task\n"
         << SELECT_CREATE_PRODUCT << " : Create new product\n"
         << SELECT_REMOVE_COMPONENT << " : Remove project component via ID\n"
         << SELECT_SHOW_PROJECT << " : Show the current project\n"
         << SELECT_CALCULATE_COST << " : Calculate current project cost\n"
         << SELECT_SWITCH_ACTIVE_PROJECT << " : Switch to project ID\n"
         << SELECT_QUIT << " : Quit\n";
    if (safeRead(cin, selection)) {
        currentSelection = static_cast<Select>(selection);
    } else{
        throw ProjectDialogueException(BAD_USER_INPUT);
    }
}

void ProjectDialogue::executeSelection(const Select& selection) {
    if (selection == SELECT_QUIT) return;
    switch (currentSelection) {
        case SELECT_CREATE_PROJECT:
            createProject();
            break;
        case SELECT_CREATE_TASK:
            createTask();
            break;
        case SELECT_CREATE_PRODUCT:
            createProduct();
            break;
        case SELECT_REMOVE_COMPONENT:
            removeComponent();
            break;
        case SELECT_SHOW_PROJECT:
            showProject();
            break;
        case SELECT_CALCULATE_COST:
            calculateCost();
            break;
        case SELECT_SWITCH_ACTIVE_PROJECT:
            switchProject();
            break;
        default:
            throw ProjectDialogueException(BAD_USER_INPUT);
    }

}

void ProjectDialogue::createProject() {
    cout << "\nPlease enter a name for the project, maximum 20 letters:" << endl;
    string name;
    string description;
    double hourlyRate = 0.0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the project, maximum 20 letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the hourly rate for the project:" << endl;
    cin >> hourlyRate;
    shared_ptr<Project> project = make_shared<Project>(name, description, hourlyRate);
    projects.insert({project->getId(), project});
    if (currentProjectId != 0) projects[currentProjectId]->add(project);
    currentProjectId = project->getId();
    cout << "\nNew project with ID: " << project->getId() << " created. Its name is: " << project->getName() << endl;
}

void ProjectDialogue::removeComponent() {
    int uniqueId = readComponentId();
    projects[currentProjectId]->remove(uniqueId);
}

void ProjectDialogue::showProject() {
    cout << "\nProject:\n"
         << *projects[currentProjectId] << endl;
}

void ProjectDialogue::calculateCost() {
    cout << "Project Cost: " << projects[currentProjectId]->getCost() << endl;
}

void ProjectDialogue::switchProject() {
    int projectId = readComponentId();
    try {
        projects[projectId];
        currentProjectId = projectId;
    } catch (const std::out_of_range& e) {
        throw ProjectDialogueException(ID_DOES_NOT_EXIST);
    } catch (...) {

    }
}

int ProjectDialogue::readComponentId() {
    int componentId = -1;
    cout << "\nPlease enter the component ID: ";
    safeRead(cin, componentId);
    clearUserInput();
    return componentId;
}

void ProjectDialogue::createTask() {
    if (currentProjectId == 0) throw ProjectDialogueException(PROJECT_NOT_READY);
    cout << "\nPlease enter a name for the task, maximum 20 letters:" << endl;
    string name;
    string description;
    int hours = 0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the task, maximum 20 letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the hours for the task:" << endl;
    cin >> hours;
    shared_ptr<Task> task = make_shared<Task>(name, description, hours);
    projects[currentProjectId]->add(task);
    cout << "\nNew task with ID: " << task->getId() << " created. Its name is: " << task->getName() << endl;
}

void ProjectDialogue::createProduct() {
    if (currentProjectId == 0) throw ProjectDialogueException(PROJECT_NOT_READY);
    cout << "\nPlease enter a name for the product, maximum 20 letters:" << endl;
    string name;
    string description;
    double productionCost = 0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the product, maximum 20 letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the production cost for the product:" << endl;
    cin >> productionCost;
    shared_ptr<Product> product = make_shared<Product>(name, description, productionCost);
    projects[currentProjectId]->add(product);
    cout << "\nNew product with ID: " << product->getId() << " created. Its name is: " << product->getName() << endl;
}

void ProjectDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}

/*void ProjectDialogue::createDummyArticles() {
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
}*/

