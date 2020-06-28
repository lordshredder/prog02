/**
 *
 *  @file ElectronicDevice.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */

#include "ElectronicDevice.h"

using namespace std;


const std::string ElectronicDevice::NEGATIVE_KILOWATTS = "The kilowatts size cannot be negative or zero.";

ElectronicDevice::ElectronicDevice(int articleNr, const string &description,
        long double price, const int kilowatts, int stock) : Article(articleNr, description, price, stock)  {
    this->kilowatts = kilowatts;
}

ElectronicDevice::ElectronicDevice(const ElectronicDevice &e) : Article(e), kilowatts(e.kilowatts) {
    cout << "DEBUG COPY CONSTRUCTOR ELECTRONICDEVICE" << endl;
}

ElectronicDevice &ElectronicDevice::operator=(ElectronicDevice electronicDevice) {
    Article::operator=(electronicDevice);
    swap(kilowatts, electronicDevice.kilowatts);

    return *this;
}

ElectronicDevice::~ElectronicDevice() {
    cout << "ELECTRONICDEVICE DESTRUCTOR DEBUG" << endl;
}

shared_ptr<Article> ElectronicDevice::copy() const {
    return make_shared<ElectronicDevice>(*this);
}

string ElectronicDevice::toString() const {
    int space = 10;
    stringstream str;
    str << Article::toString();
    str << "    Kilowatts: "  << kilowatts << setw(space-kilowatts) << "\t  ";
    return str.str();
}

int ElectronicDevice::getKilowatts() const {
    return kilowatts;
}

void ElectronicDevice::setKilowatts(const int &kilowatts) {
    if (kilowatts <= 0) {
        throw NEGATIVE_KILOWATTS;
    }
    this->kilowatts = kilowatts;
}














