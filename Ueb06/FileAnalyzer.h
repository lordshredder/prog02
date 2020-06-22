/**
 *
 *  @file FileAnalyzer.h
 *  @authors David Berres, Nico Schorr
 *  @date 21.06.2021
 */
#pragma once
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * A class used to analyze and print statistics of one or more files.
 */
class FileAnalyzer {
public:
    static const int ASCII_A = 65;
    static const int ASCII_Z = 90;
    static const int ASCII_a = 97;
    static const int ASCII_z = 122;
    static const int ASCII_0 = 48;
    static const int ASCII_9 = 57;

    /**
     * A function that calls both analyzeFileContent and printHeader.
     * @param argc The amount of arguments provided.
     * @param argv  The actual arguments.
     */
    void analyzeFiles(int argc, char *argv[]);
    /**
     * A function used to extract the file name from it's data path.
     * @param path the data path itself.
     * @return returns the modified data path as a string.
     */
    string getFileName(const string& path);
    /**
     * Prints the header of the analyzed content.
     * @return returns the header as a string.
     */
    string printHeader() const;
    /**
     * prints the analyzed content.
     * @return returns the analyzes content as a string.
     */
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
    /**
     * The main function that analyzes the file content.
     * @param path the data path of the file that needs to be analyzed.
     * @return returns the analyzed content as a string.
     */
    string analyzeFileContent(const string& path);
    /**
     * a simple function that resets all analyzed attributes back to zero.
     */
    void resetAttributes();
};

