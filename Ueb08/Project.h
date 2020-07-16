/**
 *
 *  @file Project.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once
#include "ProjectComponent.h"
#include "MockInput.h"
#include <vector>
#include <string>

class ProjectException : public ProjectComponentException {
public:
    ProjectException(const string& msg = "") : ProjectComponentException(msg) {

    }
};

/**
 *  A subclass called Task, it inherits methods and attributes
 *  from the ProjectComponent class. It also has it's own attribute called hours.
 */
class Project : public ProjectComponent, public std::enable_shared_from_this<Project> {
public:
    const static string NEGATIVE_HOURLY_RATE;
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
    /**
     * Removes a ProjectComponent by its unique ID.
     * @param id of the component.
     */
    void remove(int uniqueId);
    /**
     * Adds a project component. Pretty much.
     * The project component will also have its root assigned to this project.
     * @param projectComponent to be added.
     */
    void add(std::shared_ptr<ProjectComponent> projectComponent);
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    virtual std::string toString() const override;
    double getHourlyRate() const;
    virtual double getCost() const override;
    void setHourlyRate(const double hourlyRate);
    Project& operator=(const Project& project);
protected:
    std::vector<std::shared_ptr<ProjectComponent>> components;
    double hourlyRate;
};
