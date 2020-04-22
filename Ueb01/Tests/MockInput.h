#pragma once

#include "../Person.h"
#include <iostream>
#include <random>

class MockInput {

public:
    MockInput() = delete;
    static void CreateDefinedMockInput(Person *personArray, int arrayLength);
    static void CreateRandomMockInput(Person *personArray, int arrayLength);
private:
    static std::string RandomString(std::mt19937 *generator);
    static int RandomBirthday();
};