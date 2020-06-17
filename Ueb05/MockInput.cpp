/**
 *
 *  @file MockInput.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#include <random>
#include <algorithm>
#include <chrono>
#include <functional>
#include "MockInput.h"


MockInput::MockInput()  : generator(std::chrono::system_clock::now().time_since_epoch().count()) {
}

string MockInput::RandomString(const int &maxLetters, const int& minLetters) {
    if (maxLetters < 0 || minLetters < 0) return "";
    if (maxLetters < minLetters) return "";
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    auto size = std::bind(std::uniform_int_distribution<int>(minLetters, maxLetters), generator);
    std::shuffle(str.begin(), str.end(), generator);
    generator();
    return str.substr(0, size());
}

int MockInput::RandomNumber(const int& maxNumber, const int& minNumber) {
    auto number = std::bind(std::uniform_int_distribution<int>(minNumber, maxNumber), generator);
    generator();
    return number();
}

long double MockInput::RandomNumber(const long double& maxNumber, const long double& minNumber) {

    auto number = std::bind(std::uniform_real_distribution<long double>(minNumber, maxNumber), generator);
    generator();
    return number();
}
