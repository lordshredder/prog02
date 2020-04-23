#include <iostream>
#include "Person.h"
#include "MockInput.h"
#include "PersonStorage.h"
#include "InputHandler.h"
#include "OutputHandler.h"

using std::cout;

int main() {

    int arraySize = 10;
    int readPeople = 0;
    Person personen[arraySize];

    readPeople = controlInput(personen, arraySize);
    //MockInput::CreateRandomMockInput(personen, arraySize);
    printAllPeople(personen, readPeople);
    cout << "\n\nSortiere Array..." << std::endl;
    sortPerson(personen, readPeople);
    printAllPeople(personen, readPeople);

    return 0;
}


