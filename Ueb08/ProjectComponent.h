//
// Created by Pai on 03/07/2020.
//
#pragma once


#include <string>

class ProjectComponent {
public:
    static int uniqueIDCounter;
    ProjectComponent(const std::string& name, const std::string& description);
protected:
    std::string name;
    std::string description;
    int uniqueId;
};

