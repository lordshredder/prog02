//
// Created by Pai on 19/04/2020.
//

#include "Person.h"

Person::Person() {

}

Person::Person(string name, string vorname, int geburtsdatum) {
    _name = name;
    _vorname = vorname;
    _geburtsdatum = geburtsdatum;
}

const string &Person::getName() const {
    return _name;
}

const string &Person::getVorname() const {
    return _vorname;
}

int Person::getGeburtsdatum() const {
    return _geburtsdatum;
}

bool operator<(Person &lhs, Person &rhs) {
    return lhs.getName() < rhs.getName();
}
