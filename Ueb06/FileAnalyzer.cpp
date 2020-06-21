//
// Created by Pai on 18/06/2020.
//
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "FileAnalyzer.h"

void FileAnalyzer::resetAttributes() {
    numberCount = 0;
    sLetterCount = 0;
    cLetterCount = 0;
    commentCount = 0;
    lineCount = 0;
    commentDensity = 0.0;
}

void FileAnalyzer::analyzeFiles(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        analyzeFileContent(argv, argv[i]);
    }
}

void FileAnalyzer::analyzeFileContent(char *const *argv, const string &path) {
    ifstream infile;
    string line;
    infile.open(argv[1]);
    if (!infile) {
        cout << argv[1] << " cannot be opened.\n";
        return;
    }
    fileName = getFileName(path);
    char c = '1';
    while(!infile.eof()) {
        getline(infile,line);
        for (char i : line) {
            c = i;
            if(c >= 65 && c <= 90){
                ++cLetterCount;
            } else if (c >= 97 && c <= 122){
                ++sLetterCount;
            } else if(c >= 48 && c <= 57){
                ++numberCount;
            }
        }
        lineCount++;
        if (line.find("//") != -1) {
            commentCount++;
        }
    }
    infile.close();
    commentDensity = commentCount * 100.0 / lineCount;
    cout << *this << endl;
    resetAttributes();
}

std::string FileAnalyzer::toString() const {
    int space = 15;
    ostringstream ostr;
    ostr << "Input File: ";
    ostr << fileName << endl;
    ostr << "Lines" << "\t";
    ostr << "Comments" << "\t" << "Comment Density" << "\t";
    ostr << "0-9" << "\t" << "A-Z" << "\t" << "a-z" << endl;
    ostr << lineCount << "\t";
    ostr << commentCount << "\t" << setprecision(3) << commentDensity << "%" << "\t";
    ostr << numberCount << "\t" << cLetterCount << "\t" << sLetterCount << "\t" << endl << endl;
    return ostr.str();
}

ostream& operator<< (ostream& stream, const FileAnalyzer& analyzer){
    return stream << analyzer.toString();
}

std::string FileAnalyzer::getFileName(const string& path) {
    char sep = _WIN32 ? '\\' : '/';
    size_t i = path.rfind(sep, path.length());
    if (i != string::npos) {
        return(path.substr(i + 1, path.length() - i));
    }
    return("");
}
