/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <iomanip>
#include "ProjectComponent.h"
#include "Task.h"
#include "ProjectDialogue.h"

using namespace std;


int main() {

    try {
        ProjectDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }



/*    Project projectZero("p1", 100.0);
    shared_ptr<ProjectComponent> c1 = make_shared<Task>("kfks", "satt", 5);
    projectZero.add(c1);
    for (int i = 0; i < 10; ++i) {
        shared_ptr<Task> t = make_shared<Task>("sdfsf", "asfs", 2);
        projectZero.add(t);
    }
    shared_ptr<ProjectComponent> t = make_shared<Task>("sf", "a77", 8);
    shared_ptr<Product> p = make_shared<Product>("fs", "savvvt", 5.85);
    shared_ptr<Project> c = make_shared<Project>("khks", "safff", 10.0);
    c->add(p);
    c->add(t);
    projectZero.add(c);
    Project copy = projectZero;
    copy.components[3]->setName("copy");
    cout << copy.components[3]->getName() <<  endl;
    cout << projectZero.components[3]->getName() <<  endl;
    std::cout << "Hello, World!" << std::endl;
    cout << projectZero << endl;
*//*    projectZero.remove(15);
    cout << projectZero << endl;*//*
    cout << "cost: " << fixed << setprecision(2) << projectZero.getCost() << endl;*/

    return 0;
}
