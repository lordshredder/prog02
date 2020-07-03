/**
 *
 *  @file Project.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */


#include <iostream>
#include "Project.h"
using namespace std;

Project::Project(const std::string& name, const std::string& description, int hourlyRate)
        : ProjectComponent(name, description), hourlyRate(hourlyRate) {

}

void Project::add(std::shared_ptr<ProjectComponent> projectComponent) {

}

void Project::remove(std::shared_ptr<ProjectComponent> projectComponent) {

}

Project::~Project() {
    cout << "DEBUG CHECK: Project destructor called." << endl;
}

int Project::getHourlyRate() const {
    return hourlyRate;
}

void Project::setHourlyRate(const int hourlyRate) {
    this->hourlyRate = hourlyRate;
}

