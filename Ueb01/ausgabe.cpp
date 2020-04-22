#include <iostream>
#include "Person.h"
#include "ausgabe.h"
using namespace std;


void steuereAusgabe(Person *personArray, int z)
{
    for (int i = 0; i < z; i++)
    {
        cout << "\nName: " << personArray[i].getName() << endl;
        cout << "Vorname: " << personArray[i].getVorname() << endl;
        cout << "Geburtsdatum: " << personArray[i].getGeburtsdatum() << endl;
    }
}