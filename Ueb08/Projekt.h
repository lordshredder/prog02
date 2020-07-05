/**
 *
 *  @file Project.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#pragma once

#include <vector>
#include "ProjectComponent.h"

using namespace std;

class Projekt : public ProjectComponent {
public:
    /**
     * Constructor for the subclass Project.
     * @param name The name of the project.
     * @param description The description of the project.
     * @param hourlyRate The money it takes per hour.
     */
    Projekt(const string& name, const string& description, double hourlyRate);
    Projekt(const string& name, double hourlyRate);
    /**
     * Copy Constructor.
     * @param project The project to copy.
     */
    Projekt(const Projekt& projekt);
    /**
     * Destructor.
     */
    virtual ~Projekt();
    /**
     * Adds either a project, a task or a product to the existing project.
     * @param projectComponent can be a project, task or product
     */
    void add(shared_ptr<ProjectComponent> projectComponent);
    /**
     * Removes the chosen project component.
     * @param uniqueId used to find the exact component.
     */
    void remove(int uniqueId) override;
    double getHourlyRate() const;
    void setHourlyRate(const double hourlyRate);
    double getCost() const override;
    double calcCost(double cost) const override;
    string toString() const override;
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    shared_ptr<ProjectComponent> clone() const override;
    vector<shared_ptr<ProjectComponent>> components;
private:
    double hourlyRate;
};
