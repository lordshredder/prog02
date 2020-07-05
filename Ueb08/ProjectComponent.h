/**
 *
 *  @file ProjectComponent.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once
#include <string>
#include <memory>
#include "Project.h"

/**
 *  A class called ProjectComponent, used to simulate project management by
 *  adding and removing tasks, products and projects.
 */
class ProjectComponent {
public:
    /**
     * Constructor for the class ProjectComponent.
     * @param name The name of the component.
     * @param description The description of the component.
     */
    ProjectComponent(const std::string& name, const std::string& description);
    /**
     * Copy Constructor
     * @param project The project to copy.
     */
    ProjectComponent(const ProjectComponent& component);
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const = 0;
    int getId() const;
    virtual void remove(int uniqueId);
    virtual double getCost() const = 0;
    std::string getName() const;
    std::string getDescription() const;
    void setName(const std::string& name);
    virtual void setProject(shared_ptr<Project> project);
    virtual double calcCost(double cost) const = 0;
    virtual std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const ProjectComponent& component);

protected:
    std::string name;
    std::string description;
    int uniqueId;
    static int uniqueIDCounter;
    shared_ptr<Project> root;
};

