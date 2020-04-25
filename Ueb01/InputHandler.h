/**
 *
 *  @file InputHandler.h
 *  @authors David Berres, Nico Schorr
 *  @date 23.04.2020
 */
#pragma once
#include <iostream>

    /**
     * A single person struct is filled with user input.
     * @param person Struct to fill.
     */
    void readPerson(Person& person);

    /**
     *
     * @param personArray The array that should get filled.
     * @param arraySize The arraySize of the array.
     * @return
     */
    int controlInput(Person personArray[], int arraySize);



