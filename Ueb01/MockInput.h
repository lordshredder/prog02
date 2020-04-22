//
// Created by Pai on 22/04/2020.
//

#ifndef UEB01_MOCKINPUT_H
#define UEB01_MOCKINPUT_H


#include "Person.h"
#include <iostream>
#include <random>

class MockInput {

public:
    static void CreateDefinedMockInput(Person *personArray, int arrayLength);
    static void CreateRandomMockInput(Person *personArray, int arrayLength);
private:
    static std::string RandomString(std::mt19937 *generator);
    static int RandomBirthday();
};


#endif //UEB01_MOCKINPUT_H
