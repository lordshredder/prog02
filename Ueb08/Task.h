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
    int getHours() const;
    void setHours(const int hours);
private:
    int hours;
};

