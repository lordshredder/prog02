/**
 *
 *  @file InputHandler.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.04.2020
 */
#include <iostream>
#include "Person.h"
#include "InputHandler.h"
using namespace std;

int controlInput(Person personArray[], int arraySize) {
    char selection = 0;
    int position = 0;
    Person person;

    do {
        readPerson(person);
        personArray[position] = person;
        position++;
        if (position < arraySize) {
            cout << "\nNochmal? nein=n, sonst beliebiges Zeichen\n";
            while (getchar() != '\n');
            cin >> selection;
        }
    } while (selection != 'n' && position < arraySize);
    return position;
}

void readPerson(Person &person) {
    cout << "\nBitte Vornamen eingeben: " << endl;
    cin >> person.name;
    cout << "Bitte Nachnamen eingeben: " << endl;
    cin >> person.surname;
    cout << "Bitte Geburtstag eingeben: " << endl;
    cin >> person.birthdate.day;
    cout << "Bitte Geburtsmonat eingeben: " << endl;
    cin >> person.birthdate.month;
    cout << "Bitte Geburtsjahr eingeben: " << endl;
    cin >> person.birthdate.year;
}
