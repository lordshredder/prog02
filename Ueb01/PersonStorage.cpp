#include "PersonStorage.h"

void sortPerson(Person *personArray, int arrayLength) {
    int min;
    for (int i = 0; i < arrayLength-1; ++i) {
        min = i;
        for (int j = i+1; j < arrayLength; ++j) {
            if (personArray[j].surname.compare(personArray[min].surname) < 0) {
                min = j;
            }
        }
        swapPerson(personArray, min, i);
    }

    for (int i = 0; i < arrayLength-1; ++i) {
        min = i;
        for (int j = i+1; j < arrayLength; ++j) {
            if (personArray[j].surname == personArray[min].surname
            && personArray[j].name.compare(personArray[min].name) < 0) {
                min = j;
            }
        }
        swapPerson(personArray, min, i);
    }

}

void swapPerson(Person *personArray, int positionOne, int positionTwo) {
    Person temp;
    temp = personArray[positionOne];
    personArray[positionOne] = personArray[positionTwo];
    personArray[positionTwo] = temp;
}
