/**
 *
 *  @file main.cpp
 *  @authors David Berres
 *  @date 10.07.2020
 */
#include <iostream>
#include "Evaluation.h"

int main() {
    Evaluation evaluation;
    try {
        evaluation.load("Ergebnisse.txt");
        evaluation.showSubjects();
        evaluation.showRegister();
        evaluation.showAverage();

    } catch(EvaluationException& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
