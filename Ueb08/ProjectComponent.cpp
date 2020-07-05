/**
 *
 *  @file ProjectComponent.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include <utility>
#include "ProjectComponent.h"

int ProjectComponent::uniqueIDCounter;
ProjectComponent::ProjectComponent(const std::string& name, const std::string& description)
    : name(name), description(description) {
    uniqueId = ++ProjectComponent::uniqueIDCounter;
    std::cout << "The Component " << name << " was created with the unique ID: " << uniqueId << std::endl;
}

int ProjectComponent::getId() const {
    return this->uniqueId;
}

std::string ProjectComponent::getName() const {
    return this->name;
}

std::string ProjectComponent::getDescription() const {
    return this->description;
}

void ProjectComponent::setName(const std::string &name) {
    this->name = name;
}

ProjectComponent::ProjectComponent(const ProjectComponent &component) {
    std::cout << "DEBUG: COPY CONSTRUCTOR ProjectComponent." << std::endl;
}

std::string ProjectComponent::toString() const {
    std::ostringstream ostr;
    ostr << "Unique ID: " << uniqueId << "\tName: " << name << "\tDescription: " << description;
    return ostr.str();
}

std::ostream &operator<<(std::ostream &stream, const ProjectComponent &component) {
    return stream << component.toString();
}

void ProjectComponent::remove(int uniqueId) {

}

void ProjectComponent::setProject(std::shared_ptr<ProjectComponent> project) {
    root = std::move(project);
}

std::shared_ptr<ProjectComponent> ProjectComponent::getRoot() const {
    return root;
}
