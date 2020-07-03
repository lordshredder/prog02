/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include "ProjectComponent.h"
#include "Task.h"
#include "Project.h"
using namespace std;


int main() {
    Project projectZero("p1", 100.50);
    shared_ptr<ProjectComponent> c1 = make_shared<Task>("kfks", "satt", 34);
    projectZero.add(c1);
    for (int i = 0; i < 10; ++i) {
        shared_ptr<Task> t = make_shared<Task>("sdfsf", "asfs", i+2);
        projectZero.add(t);
    }
    Task t = Task("sf", "a77", 8);
    Task g = t;
    g = t;

    projectZero.remove(5);
    Project copy = projectZero;
    copy.components[3]->setName("copy");
    cout << copy.components[3]->getName() <<  endl;
    cout << projectZero.components[3]->getName() <<  endl;
            std::cout << "Hello, World!" << std::endl;
    return 0;
}
