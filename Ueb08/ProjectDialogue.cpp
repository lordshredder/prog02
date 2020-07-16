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
#include "MockInput.h"
#include "ExceptionChecker.h"
#include <string>
#include <iomanip>

using namespace std;

const string ProjectDialogue::PROJECT_NOT_READY = "Please initialize and select a project first.";
const string ProjectDialogue::BAD_USER_INPUT = "Invalid input.";
const string ProjectDialogue::ID_DOES_NOT_EXIST = "ID does not exist.";
const string ProjectDialogue::ID_ALREADY_EXISTS = "Project already exists.";

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
         << SELECT_SHOW_CURRENT_PROJECT << " : Show the current project\n"
         << SELECT_SHOW_FULL_PROJECT << " : Show the full project\n"
         << SELECT_CALCULATE_COST << " : Calculate cost of current project\n"
         << SELECT_SWITCH_ACTIVE_PROJECT << " : Switch to project ID\n"
         << SELECT_CREATE_DUMMY_COMPONENTS << " : Create Dummy Components\n"
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
        case SELECT_SHOW_CURRENT_PROJECT:
            showProject();
            break;
        case SELECT_SHOW_FULL_PROJECT:
            showFullProject();
            break;
        case SELECT_CALCULATE_COST:
            calculateCost();
            break;
        case SELECT_SWITCH_ACTIVE_PROJECT:
            switchProject();
            break;
        case SELECT_CREATE_DUMMY_COMPONENTS:
            createDummyProjects();
            break;
        default:
            throw ProjectDialogueException(BAD_USER_INPUT);
    }

}

void ProjectDialogue::createProject() {
    cout << "\nPlease enter a name for the project, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    string name;
    string description;
    double hourlyRate = 0.0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the project, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the hourly rate for the project:" << endl;
    cin >> hourlyRate;
    shared_ptr<Project> project = make_shared<Project>(name, description, hourlyRate);
    if (!projects.insert({project->getId(), project}).second) throw ProjectDialogueException(ID_ALREADY_EXISTS);
    if (currentProjectId != 0) projects[currentProjectId]->add(project);
    currentProjectId = project->getId();
    cout << "\nNew project with ID: " << project->getId() << " created. Its name is: " << project->getName() << endl;
}

void ProjectDialogue::createTask() {
    check<ProjectDialogueException>(currentProjectId != 0, PROJECT_NOT_READY);
    cout << "\nPlease enter a name for the task, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    string name;
    string description;
    int hours = 0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the task, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the hours for the task:" << endl;
    cin >> hours;
    shared_ptr<Task> task = make_shared<Task>(name, description, hours);
    projects[currentProjectId]->add(task);
    cout << "\nNew task with ID: " << task->getId() << " created. Its name is: " << task->getName() << endl;
}

void ProjectDialogue::createProduct() {
    check<ProjectDialogueException>(currentProjectId != 0, PROJECT_NOT_READY);
    cout << "\nPlease enter a name for the product, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    string name;
    string description;
    double productionCost = 0;
    clearUserInput();
    getline(cin, name);
    cout << "\nPlease enter a description for the product, maximum " << ProjectComponent::MAX_STRING_SIZE << " letters:" << endl;
    getline(cin, description);
    cout << "\nPlease enter the production cost for the product:" << endl;
    cin >> productionCost;
    shared_ptr<Product> product = make_shared<Product>(name, description, productionCost);
    projects[currentProjectId]->add(product);
    cout << "\nNew product with ID: " << product->getId() << " created. Its name is: " << product->getName() << endl;
}

void ProjectDialogue::removeComponent() {
    check<ProjectDialogueException>(currentProjectId != 0, PROJECT_NOT_READY);
    int uniqueId = readComponentId();
    if (projects.find(uniqueId) != projects.end()) {
        remove(uniqueId);
        return;
    }
    if (currentProjectId != 0) {
        int projectId = projects.begin()->second->getId();
        shared_ptr<Project> p = projects[projectId];
        p->remove(uniqueId);
    }
    cout << "The Component with the ID: " << uniqueId << " has been removed if it existed." << endl;
}

void ProjectDialogue::remove(int uniqueId) {
    if (projects.find(uniqueId) != projects.end()) {
        vector<int> ids;
        for (const auto& project : projects) {
           shared_ptr<ProjectComponent> temp = project.second->getRoot();
            if (!(temp != nullptr)) continue;
            int tempId = temp->getId();
            if (tempId == uniqueId) ids.push_back(project.second->getId());
        }
        projects.erase(uniqueId);
        for (auto id : ids) {
            remove(id);
        }
        currentProjectId = 0;
        if (!projects.empty())
            currentProjectId = projects.begin()->second->getId();
    }
}

void ProjectDialogue::showProject() {
    check<ProjectDialogueException>(projects.find(currentProjectId) != projects.end(), PROJECT_NOT_READY);
    cout << "\nProject: " << projects[currentProjectId]->getName() << '\n'
         << *projects[currentProjectId] << endl;
}

void ProjectDialogue::showFullProject() {
    check<ProjectDialogueException>(currentProjectId != 0, PROJECT_NOT_READY);
    int baseProject = projects.begin()->second->getId();
    cout << "\nProject: " << projects[baseProject]->getName() << '\n'
         << *projects[baseProject] << endl;
}

void ProjectDialogue::calculateCost() {
    check<ProjectDialogueException>(projects.find(currentProjectId) != projects.end(), PROJECT_NOT_READY);
    cout << "Project " << projects[currentProjectId]->getName() <<  " cost: " << fixed << setprecision(2) << projects[currentProjectId]->getCost() << " EUR" << endl;
}

void ProjectDialogue::switchProject() {
    int projectId = readComponentId();
    check<ProjectDialogueException>(projects.find(projectId) != projects.end(), ID_DOES_NOT_EXIST);
    currentProjectId = projectId;
}

int ProjectDialogue::readComponentId() {
    int componentId = -1;
    cout << "\nPlease enter the component ID: ";
    safeRead(cin, componentId);
    clearUserInput();
    return componentId;
}


void ProjectDialogue::clearUserInput() {
    string temp;
    cin.clear();
    getline(cin, temp);
}

void ProjectDialogue::createDummyProjects() {
    MockInput mock;
    const int maxLetters = ProjectComponent::MAX_STRING_SIZE;
    if (currentProjectId == 0) {
        string name = mock.RandomString(8, 5);
        string desc = mock.RandomString(maxLetters, 9);
        long double rate = mock.RandomNumber(250.0L, 10.5L);
        float roundedPrice = (float)((int)(rate * 100 + 0.5f))/100;
        shared_ptr<Project> p = make_shared<Project>(name, desc, roundedPrice);
        projects.insert({p->getId(), p});
        currentProjectId = p->getId();
    }
    for (int i = 0; i < AMOUNT_DUMMY_COMPONENTS; ++i) {
        int hours = mock.RandomNumber(800, 10);
        string name = mock.RandomString(maxLetters, 5);
        string desc = mock.RandomString(maxLetters, 5);
        long double price = mock.RandomNumber(250.0L, 10.5L);
        float roundedPrice = (float)((int)(price * 100 + 0.5f))/100;
        shared_ptr<Project> p;
        shared_ptr<ProjectComponent> pc;
        switch(mock.RandomNumber(2,1)){
            case 0:
                p = make_shared<Project>(name, desc, roundedPrice);
                projects.insert({p->getId(), p});
                projects[currentProjectId]->add(p);
                currentProjectId = p->getId();
                break;
            case 1:
                pc = make_shared<Product>(name, desc, roundedPrice);
                projects[currentProjectId]->add(pc);
                break;
            case 2:
                pc = make_shared<Task>(name, desc, hours);
                projects[currentProjectId]->add(pc);
                break;
        }
    }
    cout << AMOUNT_DUMMY_COMPONENTS
         << " components with random values have been created." << endl;
}

