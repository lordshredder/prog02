#include <iostream>
#include "Person.h"
#include "ausgabe.h"
using namespace std


void steuereAusgabe(struct person *personarray[], int z)
{
    for (int i = 0; i < z; i++)
    {
        cout << "\nName: " << personarray[i].name endl;
        cout << "Vorname: " << personarray[i].vorname endl;
        cout << "Geburtsdatum: " << personarray[i].geburtsdatum endl;
    }
}