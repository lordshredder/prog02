#include <string>
#include <iostream>
#include <fstream>
#include "FileAnalyzer.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile;	// Eingabedatei
    ofstream outfile;	// Ausgabedatei
    FileAnalyzer analyzer;
    if (argc > 1){


    }
    cout << "Eingabedatei: ";
    //cin >> eingabe;

    infile.open(argv[1]);
    if (!infile) {
        cout << argv[1] << " kann nicht geoeffnet werden\n";
        return 1;
    }
    int length = 10000000;
    char* record = new char[length];
    infile.read(record, length);
    cout << record << endl;
    cout << analyzer;
/*    try {
        USERMENU START;
    }*/
    return 0;
}
