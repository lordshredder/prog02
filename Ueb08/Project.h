/**
 *
 *  @file Project.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#pragma once
#include "ProjectComponent.h"
#include <memory>

class Project : public ProjectComponent {
public:
    void add(std::shared_ptr<ProjectComponent> projectComponent);
    void remove(std::shared_ptr<ProjectComponent> projectComponent);
    Project(const std::string& name, const std::string& description, int hourlyRate);
    virtual ~Project();
    int getHourlyRate() const;
    void setHourlyRate(const int hourlyRate);
private:
    int hourlyRate;
};




