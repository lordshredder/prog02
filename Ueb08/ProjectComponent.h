/**
 *
 *  @file ProjectComponent.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once
#include <string>
#include <memory>

class ProjectComponent {
public:
    ProjectComponent(const std::string& name, const std::string& description);
    ProjectComponent(const ProjectComponent& project);
    virtual std::shared_ptr<ProjectComponent> clone() const = 0;
    int getId() const;
    virtual double getCost() const = 0;
    std::string getName() const;
    std::string getDescription() const;
    void setName(const std::string& name);

protected:
    std::string name;
    std::string description;
    int uniqueId;
    static int uniqueIDCounter;
};

