/**
 *
 *  @file Evaluation.cpp
 *  @authors David Berres
 *  @date 10.07.2020
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Evaluation.h"

const std::string Evaluation::FILE_COULD_NOT_BE_OPENED = "File could not be opened";

void Evaluation::load(const std::string& pathToFile) {
/*std::ifstream file;
file.open(pathToFile);*/

std::ifstream file(pathToFile);
if (!file){
    throw EvaluationException(FILE_COULD_NOT_BE_OPENED);
}
while (!file.eof()) {
    int id = 0;
    std::string regist;
    float grade = 0.0f;
    int ects = 0;
    file >> id;
    file >> regist;
    file >> grade;
    file >> ects;
    if (!file.eof()) {
        std::tuple<std::string, float, int> temp(regist, grade, ects);
        registerEntries[id].push_back(temp);
    }
}
    file.close();
}

void Evaluation::showSubjects() {
    std::map<std::string, std::tuple<float,int>> subjects;
    std::cout << "Evaluation by subjects: " << std::endl;
    std::cout << "\nSubject\t\tAverage\t    Participants" << std::endl;
    for(const auto& entry : registerEntries) {
        for (auto tuple : entry.second) {
            std::get<0>(subjects[std::get<0>(tuple)]) += std::get<1>(tuple);
            std::get<1>(subjects[std::get<0>(tuple)]) += 1;
        }
    }
    for(const auto& subject : subjects)
    {
        float avg = std::get<0>(subject.second) / std::get<1>(subject.second);
        std::cout << subject.first << std::setw(20-subject.first.length())
            << std::fixed << std::setprecision(2) << avg
            <<"\t\t" << std::get<1>(subject.second) << std::endl;
    }
}

void Evaluation::showRegister() {
    std::cout << "\n\nEvaluation by register: " << std::endl;
    std::cout << "\nRegister  ECTS  Average" << std::endl;
    for(const auto& entry : registerEntries){
        int ects = 0;
        float avg = 0.0f;
        int amount = 0;
        for (auto tuple : entry.second) {
            ects += std::get<2>(tuple);
            avg += std::get<1>(tuple);
            amount++;
        }
        if (amount) avg /= amount;
        std::cout << entry.first << "    "  << ects << "\t  " << std::fixed << std::setprecision(2) << avg << std::endl;
    }

}

void Evaluation::showAverage() {
    float avg = 0.0f;
    int amount = 0;
    for (const auto& entry : registerEntries) {
        for (const auto& tuple : entry.second) {
            avg += std::get<1>(tuple);
            ++amount;
        }
    }
    avg /= amount;
    std::cout << "\n\nTotal average: " << std::setprecision(2) << std::fixed << avg << std::endl;
}
