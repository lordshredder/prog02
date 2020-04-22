#include <iostream>
#include "Person.h"
#include "Tests/MockInput.h"
#include "PersonStorage.h"

using std::cout;

int main() {
    cout << "Hello, World!" << std::endl;
    int arraySize = 10;
    Person personen[arraySize];
    MockInput::CreateRandomMockInput(personen, arraySize);
    for (int i = 0; i < 10; ++i) {
        cout << personen[i].getName() << "\t\t\t" << personen[i].getVorname() << "\n";
    }
    cout << "Sorting the Array..." << std::endl;
    PersonStorage::sortPerson(personen, arraySize);
    for (int i = 0; i < 10; ++i) {
        cout << personen[i].getName() << "\t\t\t" << personen[i].getVorname() << "\n";
    }
    return 0;
}


