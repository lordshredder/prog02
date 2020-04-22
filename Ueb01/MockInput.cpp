#include <random>
#include <algorithm>
#include <chrono>
#include <functional>
#include "MockInput.h"
using std::string;

void MockInput::CreateDefinedMockInput(Person *personArray, int arrayLength) {
    string names[10]{"Nico", "Nico", "nico", "niCO", "David", "Dave", "David", "david", "dAvid", "Helmut"};
    string surnames[10]{"Schoor", "Schorr", "for", "yupp", "Borres", "berres", "Berres", "Blubb", "Test", "Folz"};
    unsigned seed = 0;
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    for (int i = 0; i <arrayLength; ++i) {
        string name = names[i];
        string surname = surnames[i];
        struct Person temp{ name, surname, RandomBirthday(&generator) };
        personArray[i] = temp;
    }
}
void MockInput::CreateRandomMockInput(Person *personArray, int arrayLength)
{
    unsigned seed = 0;
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    for (int i = 0; i <arrayLength; ++i) {
        string name = RandomString(&generator);
        string surname = RandomString(&generator);
        struct Person temp{ name, surname, RandomBirthday(&generator) };
        personArray[i] = temp;
    }
}

string MockInput::RandomString(std::mt19937 *generator)
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    auto size = std::bind(std::uniform_int_distribution<int>(8, 12), *generator);
    std::shuffle(str.begin(), str.end(), *generator);
    (generator)->operator()();
    return str.substr(0, size());
}

Birthdate MockInput::RandomBirthday(std::mt19937 *generator) {
    auto year = std::bind(std::uniform_int_distribution<int>(1900, 2020), *generator);
    auto day = std::bind(std::uniform_int_distribution<int>(1, 30), *generator);
    auto month = std::bind(std::uniform_int_distribution<int>(1, 12), *generator);
    (generator)->operator()();
    Birthdate bd{ day(), month(), year() };

    return bd;
}


