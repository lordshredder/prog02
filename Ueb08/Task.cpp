/**
 *
 *  @file Task.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include "Task.h"

using namespace std;

Task::Task(const string &name, const string &description, int hours)
    : ProjectComponent(name, description), hours(hours) {
}

Task::~Task() {
    cout << "DEBUG CHECK: Task destructor called." << endl;
}

int Task::getHours() const {
    return 0;
}

void Task::setHours(const int hours) {

}

double Task::getCost() const {
    return 0.0;
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

double Task::calcCost(double cost) const {
    return hours*cost;
}