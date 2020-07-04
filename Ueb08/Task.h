/**
 *
 *  @file Task.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "ProjectComponent.h"
#include <string>

/**
 *  A subclass called Task, it inherits methods and attributes
 *  from the ProjectComponent class. It also has it's own attribute called hours.
 */
class Task : public ProjectComponent {
public:
    /**
     * Constructor for the subclass Task.
     * @param name The name of the Task
     * @param description The description of the Task.
     * @param hours How many hours it takes.
     */
    Task(const std::string& name, const std::string& description, int hours);
    /**
     * Destructor.
     */
    virtual ~Task();
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    int getHours() const;
    void setHours(const int hours);
    virtual double getCost() const override;
private:
    int hours;
};

