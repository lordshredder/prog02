//
// Created by Pai on 03/07/2020.
//

#pragma once
#include <string>


#include "ProjectComponent.h"

class Product : public ProjectComponent{
public:
    Product(std::string name, std::string description, int productioncost);
    virtual ~Product();
    int getProductionCost();
    int setProductionCost();
private:
    int productioncost;

};

