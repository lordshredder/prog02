/**
 *
 *  @file Task.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "Task.h"

Task::Task(const std::string &name, const std::string &description, int hours)
    : ProjectComponent(name, description), hours(hours) {
}

Task::~Task() {

}

int Task::getHours() const {
    return 0;
}

void Task::setHours(const int hours) {

}
