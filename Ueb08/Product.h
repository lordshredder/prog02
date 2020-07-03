/**
 *
 *  @file Product.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#pragma once
#include <string>
#include "ProjectComponent.h"

class Product : public ProjectComponent{
public:
    Product(const std::string& name, const std::string& description, int productionCost);
    virtual ~Product();
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    double getProductionCost() const;
    void setProductionCost(const double cost);
    virtual double getCost() const override;
private:
    double productionCost;
};

