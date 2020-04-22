//
// Created by Pai on 22/04/2020.
//

#include <random>
#include <algorithm>
#include <chrono>
#include <functional>
#include "MockInput.h"
using std::string;

void MockInput::CreateDefinedMockInput(Person *personArray, int arrayLength) {
    string names[10]{"Nico", "Nico", "nico", "niCO", "David", "Dave", "David", "david", "dAvid", "Helmut"};
    string surnames[10]{"Schoor", "Schorr", "for", "yupp", "Borres", "berres", "Berres", "Blubb", "Test", "Folz"};
    for (int i = 0; i <arrayLength; ++i) {
        string name = names[i];
        string vorname = surnames[i];
        struct Person temp(name, vorname, RandomBirthday());
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
        string vorname = RandomString(&generator);
        struct Person temp(name, vorname, RandomBirthday());
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

int MockInput::RandomBirthday() {
    return 0;
}


