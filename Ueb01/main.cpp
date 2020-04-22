#include <iostream>
#include "Person.h"
#include "MockInput.h"
#include "PersonStorage.h"
#include "InputHandler.h"
#include "OutputHandler.h"

using std::cout;

int main() {

    int arraySize = 10;
    Person personen[arraySize];
    MockInput::CreateRandomMockInput(personen, arraySize);
    printAllPeople(personen, arraySize);
    cout << "\n\nSorting the Array..." << std::endl;
    sortPerson(personen, arraySize);
    printAllPeople(personen, arraySize);

    return 0;
}


