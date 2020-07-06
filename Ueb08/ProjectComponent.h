/**
 *
 *  @file ProjectComponent.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */
#pragma once
#include <string>
#include <memory>

using namespace std;

/**
 * Exception class
 */
class ProjectComponentException : public logic_error {
public:
    ProjectComponentException(const string& msg = "") : logic_error(msg) {

    }
};

/**
 *  A class called ProjectComponent, used to simulate project management by
 *  adding and removing tasks, products and projects.
 */
class ProjectComponent {
public:
    const static int MAX_STRING_SIZE = 15;
    const static string NAME_CANNOT_BE_EMPTY;
    const static string NAME_SIZE_LIMIT_EXCEEDED;
    const static string DESCRIPTION_SIZE_LIMIT_EXCEEDED;
    /**
     * Constructor for the class ProjectComponent.
     * @param name The name of the component.
     * @param description The description of the component.
     */
    ProjectComponent(const std::string& name, const std::string& description);
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
    void setDescription(const std::string& description);
    std::shared_ptr<ProjectComponent> getRoot() const;
    void setRoot(std::shared_ptr<ProjectComponent> project);
    virtual std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const ProjectComponent& component);

protected:
    std::string name;
    std::string description;
    int uniqueId;
    static int uniqueIDCounter;
    std::weak_ptr<ProjectComponent> root;
};

