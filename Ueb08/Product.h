/**
 *
 *  @file Product.h
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#pragma once
#include <string>
#include "ProjectComponent.h"

class ProductException : public ProjectComponentException {
public:
    ProductException(const string& msg = "") : ProjectComponentException(msg) {

    }
};

/**
 *  A subclass called Product, it inherits methods and attributes
 *  from the ProjectComponent class. It also has it's own attribute called productionCost.
 */
class Product : public ProjectComponent {
public:
    const static string NEGATIVE_COST;
    /**
     * Constructor for the subclass Product
     * @param name The Name of the product.
     * @param description The description of the product.
     * @param productionCost The production cost.
     */
    Product(const std::string& name, const std::string& description, double productionCost);
    /**
     * Destructor.
     */
    virtual ~Product();
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual std::shared_ptr<ProjectComponent> clone() const override;
    virtual std::string toString() const override;
    double getProductionCost() const;
    virtual double getCost() const override;
    void setProductionCost(const double cost);
private:
    double productionCost;
};

