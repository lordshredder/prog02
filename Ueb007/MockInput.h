/**
 *
 *  @file MockInput.h
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#pragma once
#include <iostream>
#include <random>
using std::string;
using std::mt19937;

/**
 * Technically, this does not belong to the exercise...
 * It's just to create random input to make testing more comfortable.
 * I don't want to write comments for this.
 */
class MockInput {
public:
    MockInput();
    int RandomNumber(const int& maxNumber, const int& minNumber);
    long double RandomNumber(const long double& maxNumber, const long double& minNumber);
    string RandomString(const int& maxLetters, const int& minLetters = 1);

private:
    mt19937 generator;
};
