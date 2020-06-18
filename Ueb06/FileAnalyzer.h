//
// Created by Pai on 18/06/2020.
//

#pragma once
#include <iostream>
using namespace std;
class FileAnalyzer {
public:
    void analyzeFiles(int argc, char *argv[]);
    void analyzeFiles();
    std::string toString() const;
    friend ostream& operator<< (ostream& stream, const FileAnalyzer& list);
private:
    int numberCount = 0;
    int sLetterCount = 0;
    int cLetterCount = 0;
    int commentCount = 0;
    int lineCount = 0;
};

