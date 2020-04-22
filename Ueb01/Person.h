#pragma once

#include <string>
#include "Birthdate.h"

using std::string;

struct Person {
    string name;
    string surname;
    Birthdate birthdate;
};