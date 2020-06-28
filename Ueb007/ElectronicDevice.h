/**
 *
 *  @file ElectronicDevice.h
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */
#pragma once


#include "Article.h"

/**
 *  A subclass called ElectronicDevice, it inherits methods and attributes
 *  from the Article class. It also has it's own attribute called kilowatts.
 */
class ElectronicDevice : public Article {
public:
    static const std::string NEGATIVE_KILOWATTS;
    /**
     * Constructor for the subclass ElectronicDevice
     * @param articleNr The Number used to identify the device article. Must be 4 digits and positive.
     * @param description The description used for additional information. Cannot be empty or above the set limit.
     * @param price The price of the device article. Cannot be negative.
     * @param kilowatts The power of the device in kilowatts.
     * @param stock The quantity of the device article. Cannot be negative.
     */
    ElectronicDevice(int articleNr, const std::string& description, long double price, double kilowatts, int stock = 0);
    /**
     * Copy constructor.
     * @param e The device article we're copying from.
     */
    ElectronicDevice(const ElectronicDevice& e);
    /**
     * Equals operator.
     * @param ElectronicDevice The device article we're copying from.
     * @return The device article with new values from the parameter.
     */
    ElectronicDevice& operator=(ElectronicDevice electronicDevice);
    /**
     * Destructor.
     */
    virtual ~ElectronicDevice();
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual shared_ptr<Article> copy() const override;
    double getKilowatts() const;
    void setKilowatts(const double &kilowatts);
    /**
     * Simple toString method.
     * @return String of this object.
     */
    virtual std::string toString() const override;
protected:
    double  kilowatts;

};
