/**
 *
 *  @file Product.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(const std::string& name, const std::string& description, int productionCost)
    : ProjectComponent(name, description), productionCost(productionCost) {

}

Product::~Product() {
    cout << "DEBUG CHECK: Product destructor called." << endl;
}

double Product::getProductionCost() const {
    return productionCost;
}

void Product::setProductionCost(const double cost)  {
    this->productionCost = cost;
}

double Product::getCost() const {
    return 1.2;
}

std::shared_ptr<ProjectComponent> Product::clone() const {
    return std::make_shared<Product>(*this);
}
