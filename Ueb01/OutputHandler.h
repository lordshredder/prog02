/**
 *
 *  @file OutputHandler.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.04.2020
 */
#pragma once
#include <iostream>

/**
 * Prints all people in the array.
 * @param personArray The array that should get filled.
 * @param arrayLength The size of the array.
 */
void printAllPeople(Person *personArray, int arrayLength);

/**
 * Prints out the provided Person struct to the console.
 * @param person Person to write.
 */
void writePerson(Person &person);
