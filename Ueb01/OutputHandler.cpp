#include <iostream>
#include <iomanip>
#include "Person.h"
#include "OutputHandler.h"

using std::cout;
using std::setw;


void printAllPeople(Person *personArray, int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        writePerson(personArray[i]);
    }
}

void writePerson(Person &person) {
    int space = 32;
    cout << "\nName: " << person.surname;
    cout << setw(space-person.surname.length()) << "Vorname: " << person.name;
    cout << setw(space-person.name.length()) << "Geburtsdatum: " << person.birthdate.day << ".";
    cout << person.birthdate.month << "." << person.birthdate.year;
}
