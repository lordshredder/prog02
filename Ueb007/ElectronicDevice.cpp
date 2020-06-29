/**
 *
 *  @file ElectronicDevice.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */

#include "ElectronicDevice.h"
#include "ExceptionChecker.h"

using namespace std;


const std::string ElectronicDevice::NEGATIVE_KILOWATTS = "The kilowatts size cannot be negative or zero.";

ElectronicDevice::ElectronicDevice(int articleNr, const string &description,
        long double price, double kilowatts, int stock) : Article(articleNr, description, price, stock)  {
    this->kilowatts = kilowatts;
}

ElectronicDevice::ElectronicDevice(const ElectronicDevice &e) : Article(e), kilowatts(e.kilowatts) {
    cout << "DEBUG CHECK: ElectronicDevice copy constructor called." << endl;
}

ElectronicDevice &ElectronicDevice::operator=(ElectronicDevice electronicDevice) {
    cout << "DEBUG CHECK: ElectronicDevice operator= called." << endl;
    Article::operator=(electronicDevice);
    swap(kilowatts, electronicDevice.kilowatts);

    return *this;
}

ElectronicDevice::~ElectronicDevice() {
    cout << "DEBUG CHECK: ElectronicDevice destructor called." << endl;
}

shared_ptr<Article> ElectronicDevice::copy() const {
    return make_shared<ElectronicDevice>(*this);
}

string ElectronicDevice::toString() const {
    stringstream str;
    str << Article::toString();
    str << "    Kilowatts: " << setprecision(2) << fixed << right << std::setw(6) << kilowatts <<" kWh";
    return str.str();
}

double ElectronicDevice::getKilowatts() const {
    return kilowatts;
}

void ElectronicDevice::setKilowatts(const double &kilowatts) {
    check<ElectronicDeviceException>(kilowatts >= 0.0, NEGATIVE_KILOWATTS);
    this->kilowatts = kilowatts;
}














