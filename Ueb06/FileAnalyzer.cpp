/**
 *
 *  @file FileAnalyzer.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 21.06.2021
 */
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <vector>
#include "FileAnalyzer.h"
#include "OutputFormatter.h"

using namespace std;

void FileAnalyzer::analyzeFiles(int argc, char *argv[]) {
    if (argc < 2) return;
    vector<string> files;
    for (int i = 1; i < argc; ++i) {
        resetAttributes();
        files.push_back(analyzeFileContent(argv[i]));
    }
    cout << printHeader();
    for (const auto& file : files) {
        cout << file;
    }
}

void FileAnalyzer::resetAttributes() {
    numberCount = 0;
    sLetterCount = 0;
    cLetterCount = 0;
    commentCount = 0;
    lineCount = 0;
    commentDensity = 0.0;
}

string FileAnalyzer::analyzeFileContent(const string& path) {
    ifstream infile;
    string line;
    infile.open(path);
    if (!infile) {
        return center(path + " does not exist.", 105) + "\n";
    }
    fileName = getFileName(path);
    while(!infile.eof()) {
        getline(infile,line);
        for (char c : line) {
            if(c >= ASCII_A && c <= ASCII_Z){
                ++cLetterCount;
            } else if (c >= ASCII_a && c <= ASCII_z){
                ++sLetterCount;
            } else if(c >= ASCII_0 && c <= ASCII_9){
                ++numberCount;
            }
        }
        ++lineCount;
        if (line.find("//") == NOT_FOUND) continue;
        ++commentCount;
    }
    infile.close();
    commentDensity = commentCount * 100.0 / lineCount;
    return this->toString();
}

std::string FileAnalyzer::getFileName(const string& path) {
    char sep = _WIN32 ? '\\' : '/';
    size_t i = path.rfind(sep, path.length());
    if (i != string::npos) {
        return(path.substr(i + 1, path.length() - i));
    }
    return "";
}

string FileAnalyzer::printHeader() const {
    int space = 15;
    ostringstream ostr;
    ostr << center("Lines", space) << "\t" << center("Comments", space) << "\t";
    ostr << center("Comment Density", space) << "\t" << center("0-9", space) << "\t" << center("A-Z", space) << "\t";
    ostr << center("a-z", space) << center("Input File", space) << endl;
    return ostr.str();
}

string FileAnalyzer::toString() const {
    int space = 15;
    stringstream commentDens;
    commentDens << setprecision(3) << commentDensity << "%";
    ostringstream ostr;
    ostr << center(to_string(lineCount), space) << "\t" << center(to_string(commentCount), space) << "\t";
    ostr << center(commentDens.str(), space) << "\t" << center(to_string(numberCount), space) << "\t";
    ostr << center(to_string(cLetterCount), space) << "\t" << center(to_string(sLetterCount), space) << "\t";
    ostr << center(fileName, space) << endl;
    return ostr.str();
}

ostream& operator<<(ostream& stream, const FileAnalyzer& analyzer){
    return stream << analyzer.toString();
}
