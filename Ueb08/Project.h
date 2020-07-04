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

/**
 *  A subclass called Project, it inherits methods and attributes
 *  from the ProjectComponent class. It also has it's own attribute called hourlyRate.
 */
class Project : public ProjectComponent {
public:
    /**
     * Adds either a project, a task or a product to the existing project.
     * @param projectComponent can be a project, task or product
     */
    void add(shared_ptr<ProjectComponent> projectComponent);
    /**
     * Removes the chosen project component.
     * @param uniqueId used to find the exact component.
     */
    void remove(int uniqueId);
    /**
     * Constructor for the subclass Project.
     * @param name The name of the project.
     * @param description The description of the project.
     * @param hourlyRate The money it takes per hour.
     */
    Project(const string& name, const string& description, double hourlyRate);
    Project(const string& name, double hourlyRate);
    /**
     * Copy Constructor.
     * @param project The project to copy.
     */
    Project(const Project& project);
    /**
     * Destructor.
     */
    virtual ~Project();
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    double getHourlyRate() const;
    void setHourlyRate(const double hourlyRate);
    virtual double getCost() const override;
    vector<shared_ptr<ProjectComponent>> components;
private:
    double hourlyRate;
};




