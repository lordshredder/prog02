//
// Created by Pai on 03/07/2020.
//

#include "ProjectComponent.h"
#include <string>

class Task : public ProjectComponent {
public:
Task(const std::string& name, const std::string& description, int hours);
private:
    int hours;
};
