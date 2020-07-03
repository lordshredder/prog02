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
    ProjectComponent::uniqueIDCounter = 0;
/*    for (int i = 0; i < 10; ++i) {
        Task t = Task("sdfsf", "asfs", 5);
    }
    Task t = Task("sdfsf", "asfs", 8);*/

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
