/**
 *  Main program to start.
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.04.2020
 */

#include <iostream>
#include "Person.h"
#include "PersonStorage.h"
#include "InputHandler.h"
#include "OutputHandler.h"

using std::cout;

int main() {

    const int arraySize = 100;
    int readPeople = 0;
    Person people[arraySize];
    readPeople = controlInput(people, arraySize);
    printAllPeople(people, readPeople);
    cout << "\n\nSortiere Array..." << std::endl;
    sortPerson(people, readPeople);
    printAllPeople(people, readPeople);
    cout << std::endl;
    return 0;
}


