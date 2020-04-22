#pragma once
#include <string>

using std::string;

struct Person {

public:
    Person();
    Person(string name, string vorname, int geburtsdatum);
    const string &getName() const;
    const string &getVorname() const;
    int getGeburtsdatum() const;
    friend bool operator< (Person & lhs, Person & rhs );

private:
    string _name;
    string _vorname;
    int _geburtsdatum {0};

};