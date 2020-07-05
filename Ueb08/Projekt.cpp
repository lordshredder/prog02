/**
 *
 *  @file Project.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <sstream>
#include "Projekt.h"

Projekt::Projekt(const string &name, const string &description, double hourlyRate)
        : ProjectComponent(name, description), hourlyRate(hourlyRate) {

}

Projekt::Projekt(const string &name, double hourlyRate)
        : ProjectComponent(name, ""), hourlyRate(hourlyRate) {

}

Projekt::Projekt(const Projekt &projekt)
        : ProjectComponent(projekt), hourlyRate(projekt.hourlyRate) {
    cout << "DEBUG CHECK: Project copy constructor called." << endl;
    for (const auto& comp : projekt.components) {
        this->components.push_back(comp->clone());
    }
}

Projekt::~Projekt() {
    cout << "DEBUG CHECK: Project destructor called." << endl;
    components.clear();
}

double Projekt::getHourlyRate() const {
    return hourlyRate;
}

void Projekt::setHourlyRate(const double hourlyRate) {
    this->hourlyRate = hourlyRate;
}

shared_ptr<ProjectComponent> Projekt::clone() const {
    return make_shared<Projekt>(*this);
}

void Projekt::add(shared_ptr<ProjectComponent> projectComponent) {
    projectComponent->setProject(this);
    this->components.push_back(projectComponent);
}

void Projekt::remove(int uniqueId) {
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

double Projekt::getCost() const {
    double calculatedCost = 0.0;
    for(const auto& comp : components){
        calculatedCost += comp->calcCost(hourlyRate);
    }
    return calculatedCost;
}

double Projekt::calcCost(double cost) const {
    double calculatedCost = 0.0;
    for(const auto& comp : components){
        calculatedCost += comp->calcCost(hourlyRate);
    }
    return calculatedCost;
}

string Projekt::toString() const {
    ostringstream ostr;
    ostr << ProjectComponent::toString();
    ostr << "\tHourly Rate: " << this->hourlyRate << endl;
    for(const auto& comp : components) {
        ostr << *comp;
    }
    return ostr.str();
}
