#include "PersonStorage.h"

void PersonStorage::readPerson(Person *person) {

}

void PersonStorage::sortPerson(Person *personArray, int arrayLength) {
    int min;
    for (int i = 0; i < arrayLength-1; ++i) {
        min = i;
        for (int j = i+1; j < arrayLength; ++j) {
            if (personArray[j].getName().compare(personArray[min].getName()) < 0) {
                min = j;
            }
        }
        swapPerson(personArray, min, i);
    }

    for (int i = 0; i < arrayLength-1; ++i) {
        min = i;
        for (int j = i+1; j < arrayLength; ++j) {
            if (personArray[j].getName() == personArray[min].getName()
            && personArray[j].getVorname().compare(personArray[min].getVorname()) < 0) {
                min = j;
            }
        }
        swapPerson(personArray, min, i);
    }

}

void PersonStorage::swapPerson(Person *personArray, int positionOne, int positionTwo) {
    Person temp;
    temp = personArray[positionOne];
    personArray[positionOne] = personArray[positionTwo];
    personArray[positionTwo] = temp;
}
