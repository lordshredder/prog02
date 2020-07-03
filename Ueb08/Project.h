//
// Created by Pai on 03/07/2020.
//

#pragma once


#include "ProjectComponent.h"
#include <memory>

class Project {
public:
    void add(std::shared_ptr<ProjectComponent> projectComponent);
    void remove(std::shared_ptr<ProjectComponent> projectComponent);
};

