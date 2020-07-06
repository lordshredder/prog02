/**
 *
 *  @file Product.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "Product.h"
#include <iostream>
#include <sstream>

using namespace std;

Product::Product(const std::string& name, const std::string& description, double productionCost)
    : ProjectComponent(name, description), productionCost(productionCost) {

}

Product::~Product() {
    cout << "DEBUG CHECK: Product destructor called, Name: " << this->getName() << endl;
}

double Product::getProductionCost() const {
    return productionCost;
}

void Product::setProductionCost(const double cost)  {
    this->productionCost = cost;
}

double Product::getCost() const {
    return productionCost;
}

shared_ptr<ProjectComponent> Product::clone() const {
    return std::make_shared<Product>(*this);
}

string Product::toString() const {
    ostringstream ostr;
    ostr << ProjectComponent::toString();
    ostr << "\tProduction cost: " << this->productionCost << endl;
    return ostr.str();
}
