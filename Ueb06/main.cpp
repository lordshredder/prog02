#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "FileAnalyzer.h"
#include "FileDialogue.h"

using namespace std;

void countFile(char *letter, int &cLetterCount, int &sLetterCount, int &numberCount)
{

    int len = strlen(letter);
    for (int i =0; i < len; i++)
    {
        if (letter[i] < 67)
        for (char b = 'A'; b <= 'Z'; b++)
        {
            if (letter[i] == b)
                cLetterCount++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            if (letter[i] == b)
                sLetterCount++;
        }
    }
    for (int i =0; i < len; i++)
    {
        for (char b = '0'; b <= '9'; b++)
        {
            if (letter[i] == b)
                numberCount++;
        }
    }
}


int main(int argc, char *argv[]) {
    try {
        FileAnalyzer analyzer;
        if (argc > 1) analyzer.analyzeFiles(argc, argv);
        FileDialogue dialogue(analyzer);
        dialogue.startDialogue();
    } catch (const string& e) {
        cout << "\nERROR: " << e << "\n";
    } catch (std::exception &e) {
        cout << e.what() << std::endl;
    } catch (...) {
        cout << "\nSomething went terribly wrong." << endl;
    }





//
//    ifstream infile;	// Eingabedatei
//    ofstream outfile;	// Ausgabedatei
//    string line;
//
//
//    infile.open(argv[1]);
//    if (!infile) {
//        cout << argv[1] << " kann nicht geoeffnet werden\n";
//        return 1;
//    }
//    while(!infile.eof()) {
//        getline(infile,line);
//        char *a = (char*)line.c_str();
//        countFile(a, cLetterCount, sLetterCount, numberCount);
//
//    }
//    infile.close();
//
//    cout << "The file contains: " << endl;
//    cout << cLetterCount << " uppercase letters" << endl;
//    cout << sLetterCount << " lowercase letters" << endl;
//    cout << numberCount << " digits" << endl;


/*    int length = 10000000;
    char* record = new char[length];
    infile.read(record, length);
    cout << record << endl;
    cout << analyzer;

/*    try {
        USERMENU START;
    }*/
    return 0;
}
