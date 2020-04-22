#include <iostream>
#include "Person.h"
#include "OutputHandler.h"

using std::cout;

void printAllPeople(Person *personArray, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        WritePerson(personArray[i]);
    }
}

void WritePerson(Person &person) {

    cout << "\nName: " << person.surname;
    cout << "\tVorname: " << person.name;
    cout << "\t\tGeburtsdatum: " << person.birthdate.day << ".";
    cout << person.birthdate.month << "." << person.birthdate.year;
}
