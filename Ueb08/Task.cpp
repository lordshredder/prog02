/**
 *
 *  @file Task.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include "Task.h"
#include "Project.h"
#include "ExceptionChecker.h"

using namespace std;

const string Task::NEGATIVE_HOURS = "Hours cannot be negative.";

Task::Task(const string &name, const string &description, int hours)
    : ProjectComponent(name, description) {
    setHours(hours);
}

Task::~Task() {
    cout << "DEBUG CHECK: Task destructor called, Name: " << this->getName() << endl;
}

int Task::getHours() const {
    return hours;
}

void Task::setHours(const int hours) {
    check<ProjectException>(hours >= 0, NEGATIVE_HOURS);
    this->hours = hours;
}

double Task::getCost() const {
    shared_ptr<Project> temp = dynamic_pointer_cast<Project>(getRoot());
    if (temp == nullptr) return 0.0;
    return hours*temp->getHourlyRate();
}

shared_ptr<ProjectComponent> Task::clone() const {
    return make_shared<Task>(*this);
}

string Task::toString() const {
    ostringstream ostr;
    ostr << ProjectComponent::toString();
    ostr << "\tHours: " << this->hours << endl;
    return ostr.str();
}