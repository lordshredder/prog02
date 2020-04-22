//
// Created by Nico on 22.04.2020.
//

#ifndef UEB01_INPUTHANDLER_H
#define UEB01_INPUTHANDLER_H
#include <iostream>

class InputHandler {

public:
    static void ReadPerson(Person *person);
    static int ControlInput(Person *personArray, int size);

};


#endif //UEB01_INPUTHANDLER_H
