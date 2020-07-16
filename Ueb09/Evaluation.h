/**
 *
 *  @file Evaluation.h
 *  @authors David Berres
 *  @date 10.07.2020
 */
#pragma once


#include <string>
#include <vector>
#include <stdexcept>
#include <map>

/**
 * Exception class
 */
class EvaluationException : public std::logic_error {
public:
    EvaluationException(const std::string& msg = "") : logic_error(msg) {

    }
};

/**
 * Loads a file in a formatted structure.
 */
class Evaluation {
public:
    static const std::string FILE_COULD_NOT_BE_OPENED;
    /**
     * Loads and maps data from a file.
     * @param pathToFile The full path to the file to read.
     */
    void load(const std::string& pathToFile);
    /**
     * Formats the loaded data to show
     * the subjects and calculate the average grades.
     */
    void showSubjects();
    /**
     * Formats the loaded data to show it
     * sorted by register.
     */
    void showRegister();
    /**
     * Prints the total average of all grades.
     */
    void showAverage();
private:
    std::map<int,std::vector<std::tuple<std::string, float, int>>> registerEntries;
};
