/**
 *
 *  @file ProjectComponent.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "ProjectComponent.h"
#include "ExceptionChecker.h"

const string ProjectComponent::NAME_CANNOT_BE_EMPTY = "The name cannot be empty";
const string ProjectComponent::NAME_SIZE_LIMIT_EXCEEDED = "The name cannot be longer than " + to_string(ProjectComponent::MAX_STRING_SIZE) + " letters.";
const string ProjectComponent::DESCRIPTION_SIZE_LIMIT_EXCEEDED = "The name cannot be longer than " + to_string(ProjectComponent::MAX_STRING_SIZE) + " letters.";;

int ProjectComponent::uniqueIDCounter;
ProjectComponent::ProjectComponent(const std::string& name, const std::string& description) {
    setName(name);
    setDescription(description);
    uniqueId = ++ProjectComponent::uniqueIDCounter;
    std::cout << "The Component " << name << " was created with the unique ID: " << uniqueId << std::endl;
}

ProjectComponent::ProjectComponent(const ProjectComponent &component) {
    std::cout << "DEBUG: COPY CONSTRUCTOR ProjectComponent." << std::endl;
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

void ProjectComponent::setDescription(const string &description) {
    check<ProjectComponentException>(description.size() <= MAX_STRING_SIZE, DESCRIPTION_SIZE_LIMIT_EXCEEDED);
    this->description = description;
}

void ProjectComponent::setName(const std::string& name) {
    check<ProjectComponentException>(!name.empty(), NAME_CANNOT_BE_EMPTY);
    check<ProjectComponentException>(name.size() <= MAX_STRING_SIZE, NAME_SIZE_LIMIT_EXCEEDED);
    this->name = name;
}

std::string ProjectComponent::toString() const {
    std::ostringstream ostr;
    std::shared_ptr<ProjectComponent> temp = getRoot();
    while(temp != nullptr){
        ostr << "  --> ";
        if(temp != nullptr) temp = temp->getRoot();
    }
    ostr << "ID: " << uniqueId << "\tName: " << std::setw(MAX_STRING_SIZE) << name << "\tDescription: " << std::setw(MAX_STRING_SIZE) << description;
    return ostr.str();
}

std::ostream &operator<<(std::ostream &stream, const ProjectComponent &component) {
    return stream << component.toString();
}

void ProjectComponent::remove(int uniqueId) {

}

void ProjectComponent::setRoot(shared_ptr<ProjectComponent> project) {
    root = project;
}

std::shared_ptr<ProjectComponent> ProjectComponent::getRoot() const {
    return root.lock();
}
