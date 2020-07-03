//
// Created by Pai on 03/07/2020.
//

#include "Task.h"

Task::Task(const std::string &name, const std::string &description, int hours)
    : ProjectComponent(name, description), hours(hours) {
}
