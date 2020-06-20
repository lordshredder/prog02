#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "FileAnalyzer.h"

using namespace std;

string getFileName(const string& s) {

    char sep = '/';

#ifdef _WIN32
    sep = '\\';
#endif

    size_t i = s.rfind(sep, s.length());
    if (i != string::npos) {
        return(s.substr(i+1, s.length() - i));
    }

    return("");
}


int main(int argc, char *argv[]) {
    ifstream infile;	// Eingabedatei
    ofstream outfile;	// Ausgabedatei
    double count = 0;
    double commentcount = 0;
    double cmtdensity;
    string line;
    string path = argv[1];
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
    cout << getFileName(path) << endl;
    while(!infile.eof()) {

        getline(infile,line);
        count++;
        if (!line.find ("//")) {
            commentcount++;
        }
    }
    infile.close();

    cmtdensity = commentcount *100 / count;


    cout << "Number of lines: " << count << endl;
    cout << "Number of comment lines: " << commentcount << endl;
    cout << "Comment density is: " << setprecision(4) << cmtdensity << "%" << endl;






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
