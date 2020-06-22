//
// Created by Pai on 18/06/2020.
//
#pragma once
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

class FileAnalyzer {
public:
    static const int ASCII_A = 65;
    static const int ASCII_Z = 90;
    static const int ASCII_a = 97;
    static const int ASCII_z = 122;
    static const int ASCII_0 = 48;
    static const int ASCII_9 = 57;
    static const int NOT_FOUND = -1;
    void analyzeFiles(int argc, char *argv[]);
    string getFileName(const string& path);
    string printHeader() const;
    string toString() const;
    friend ostream& operator<<(ostream& stream, const FileAnalyzer& list);
private:
    int numberCount = 0;
    int sLetterCount = 0;
    int cLetterCount = 0;
    int commentCount = 0;
    int lineCount = 0;
    double commentDensity = 0.0;
    string fileName;
    string analyzeFileContent(const string& path);
    void resetAttributes();
};

