/**
 *
 *  @file Task.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include "Task.h"

Task::Task(const std::string &name, const std::string &description, int hours)
    : ProjectComponent(name, description), hours(hours) {
}

Task::~Task() {
    std::cout << "DEBUG CHECK: Task destructor called." << std::endl;
}

int Task::getHours() const {
    return 0;
}

void Task::setHours(const int hours) {

}

double Task::getCost() const {
    return 3.3;
}

std::shared_ptr<ProjectComponent> Task::clone() const {
    return std::make_shared<Task>(*this);
}
