/**
 *
 *  @file Product.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(const std::string& name, const std::string& description, int productioncost)
    : ProjectComponent(name, description), productionCost(productioncost) {

}

Product::~Product() {
    cout << "DEBUG CHECK: Product destructor called." << endl;
}

int Product::getProductionCost() const {
    return productionCost;
}

void Product::setProductionCost(const int productionCost)  {
    this->productionCost = productionCost;
}
