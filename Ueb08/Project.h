/**
 *
 *  @file Project.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#pragma once
#include "ProjectComponent.h"
#include <memory>
#include <vector>

using namespace std;

class Project : public ProjectComponent {
public:
    void add(shared_ptr<ProjectComponent> projectComponent);
    void remove(int uniqueId);
    Project(const string& name, const string& description, double hourlyRate);
    Project(const string& name, double hourlyRate);
    Project(const Project& project);
    virtual ~Project();
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    double getHourlyRate() const;
    void setHourlyRate(const double hourlyRate);
    virtual double getCost() const override;
    vector<shared_ptr<ProjectComponent>> components;
private:
    double hourlyRate;
};




