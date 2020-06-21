/**
 * Sicheres Einlesen von Zahlen: Implementierung
 *
 * @file	safeRead.cpp
 * @author	folz
 * @date	25.05.2012
 */
#pragma once
#include <iostream>
using namespace std;

template <typename T>
bool safeRead(istream& in, T& eingabe) {
    char c;
    in >> eingabe; // Erster Leseversuch
    while (!in.good()) { // Test auf Misserfolg
        if (in.eof() || in.bad()) // Fortsetzung überhaupt sinnvoll?
            return false;
        in.clear(); // Misserfolg: Zustand zurücksetzen
        cerr << "Falsche Eingabe - bitte wiederholen" << endl;
        while (in.get(c) && c != '\n')
            ; // Rest der Zeile ignorieren
        in >> eingabe; // neuer Leseversuch
    }
    return in.good();
}

template <typename T>
bool safeReadln(istream& in, T& t) {
    char c;
    if (safeRead(in, t)) {
        while (in.get(c) && c != '\n')
            ; // Rest der Zeile ignorieren
    }
    return in.good();
}


