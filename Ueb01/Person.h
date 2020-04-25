/**
 *
 *  @file Person.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.04.2020
 */
#pragma once
#include <string>
#include "Birthdate.h"
using std::string;

/**
 * Simple Person struct.
 * The Person struct contains the name and the surname of the Person
 * as well as the Birthdate in the form of another struct consisting of
 * three integers.
 */
struct Person {
    string name;
    string surname;
    Birthdate birthdate;
};