/**
 *
 *  @file Project.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include "Project.h"
using namespace std;

Project::Project(const string& name, const string& description, double hourlyRate)
        : ProjectComponent(name, description), hourlyRate(hourlyRate) {

}

Project::Project(const string &name, double hourlyRate)
        : ProjectComponent(name, ""), hourlyRate(hourlyRate) {

}

Project::Project(const Project& project)
        :  ProjectComponent(project.name, project.description), hourlyRate(project.hourlyRate) {
    cout << "DEBUG CHECK: Project copy constructor called." << endl;
    for (const auto& comp : project.components) {
        this->components.push_back(comp->clone());
    }
}

void Project::add(shared_ptr<ProjectComponent> projectComponent) {
    //projectComponent->setProject(this);
    this->components.push_back(projectComponent);
}

void Project::remove(int uniqueId) {
    int size = components.size();
    int position = 0;
    for (int i = 0; i < size; ++i) {
        components[i]->remove(uniqueId);
        if (components[i]->getId() != uniqueId) continue;
        position = i;
        components.erase(components.begin()+position);
        return;
    }
}

Project::~Project() {
    cout << "DEBUG CHECK: Project destructor called." << endl;
    components.clear();
}

double Project::getHourlyRate() const {
    return hourlyRate;
}

void Project::setHourlyRate(const double hourlyRate) {
    this->hourlyRate = hourlyRate;
}

double Project::getCost() const {
    double cost = 0.0;
    for(const auto& comp : components){
        cost += comp->getCost();
    }
    return cost;
}

std::shared_ptr<ProjectComponent> Project::clone() const {
    return make_shared<Project>(*this);
}

string Project::toString() const {
    ostringstream ostr;
    ostr << ProjectComponent::toString();
    ostr << "\tHourly Rate: " << this->hourlyRate << endl;
    for(const auto& comp : components) {
        ostr << *comp;
    }
    return ostr.str();
}