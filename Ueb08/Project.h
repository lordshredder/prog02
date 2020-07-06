/**
 *
 *  @file Project.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once
#include "ProjectComponent.h"
#include <vector>
#include <string>

/**
 *  A subclass called Task, it inherits methods and attributes
 *  from the ProjectComponent class. It also has it's own attribute called hours.
 */
class Project : public ProjectComponent, public std::enable_shared_from_this<Project> {
public:
    /**
     * Constructor for the subclass Task.
     * @param name The name of the Task
     * @param description The description of the Task.
     * @param hours How many hours it takes.
     */
    Project(const std::string& name, const std::string& description, double hourlyRate);
    Project(const std::string& name, double hourlyRate);
    Project(const Project& project);
    /**
     * Destructor.
     */
    virtual ~Project();
    void remove(int uniqueId);
    void add(std::shared_ptr<ProjectComponent> projectComponent);
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    virtual std::string toString() const override;
    double getHourlyRate() const;
    void setHourlyRate(const double hourlyRate);
    virtual double getCost() const override;
protected:
    std::vector<std::shared_ptr<ProjectComponent>> components;
    double hourlyRate;
};
