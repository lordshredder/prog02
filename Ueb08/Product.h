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
    Product(const std::string& name, const std::string& description, int productioncost);
    virtual ~Product();
    int getProductionCost() const;
    void setProductionCost(const int productionCost);
private:
    int productionCost;

};

