//
// Created by Pai on 18/06/2020.
//

#include "FileAnalyzer.h"

void FileAnalyzer::analyzeFiles(int argc, char **argv) {

}

void FileAnalyzer::analyzeFiles() {

}

std::string FileAnalyzer::toString() const {

    return "lol";
}

ostream& operator<< (ostream& stream, const FileAnalyzer& analyzer){
    return stream << analyzer.toString();
}
