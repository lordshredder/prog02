#pragma once

#include "Person.h"

class PersonStorage {

public:
    PersonStorage() = delete;
    static void readPerson(Person *person);
    static void sortPerson(Person *personArray, int arrayLength);

private:
    static void swapPerson(Person *personArray, int positionOne, int positionTwo);
};


