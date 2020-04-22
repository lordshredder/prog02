#include <iostream>
#include "Person.h"
#include "InputHandler.h"
using namespace std;

int InputHandler::ControlInput(struct Person personArray[], int size)
{
    char weiter = 0;
    int zaehler = 0;
    struct Person person;

    do
    {
        if (weiter != 'n')
        {
            //lesePerson(&person);
            zaehler++;

            cout << "\nNochmal? nein=n, sonst beliebiges Zeichen\n";
            while (getchar() != '\n');

        }
        cin >> weiter;
    } while (weiter != 'n' || zaehler <= size);
    return zaehler;
}