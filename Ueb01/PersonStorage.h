//
// Created by Pai on 22/04/2020.
//

#ifndef UEB01_PERSONSTORAGE_H
#define UEB01_PERSONSTORAGE_H


#include "Person.h"

class PersonStorage {

public:
    static void readPerson(Person *person);
    static void sortPerson(Person *personArray, int arrayLength);

private:
    bool vergleichePersonen();
    static void swapPerson(Person *personArray, int positionOne, int positionTwo);
};


#endif //UEB01_PERSONSTORAGE_H
