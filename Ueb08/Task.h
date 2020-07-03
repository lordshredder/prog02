/**
 *
 *  @file Task.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "ProjectComponent.h"
#include <string>

class Task : public ProjectComponent {
public:
    Task(const std::string& name, const std::string& description, int hours);
    virtual ~Task();
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    int getHours() const;
    void setHours(const int hours);
    virtual double getCost() const override;
private:
    int hours;
};

