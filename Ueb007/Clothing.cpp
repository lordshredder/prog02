/**
 *
 *  @file Clothing.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */

#include "Clothing.h"
#include "ExceptionChecker.h"
#include "StorageExceptions.h"

using namespace std;

const std::string Clothing::EMPTY_CLOTHING_SIZE = "The clothing size cannot be empty.";
const std::string Clothing::CLOTHING_SIZE_LIMIT_EXCEEDED = "The clothing size must be smaller than "+std::to_string(MAX_STRING_ATTRIBUTE_SIZE) + " letters";
const std::string Clothing::EMPTY_COLOR = "The color cannot be empty.";
const std::string Clothing::COLOR_LIMIT_EXCEEDED = "The color must be smaller than "+std::to_string(MAX_STRING_ATTRIBUTE_SIZE) + " letters";

Clothing::Clothing(int articleNr, const string &description,
        long double price, const string &clothingSize,
        const string &color, int stock) : Article(articleNr, description, price, stock)  {
    this->clothingSize = clothingSize;
    this->color = color;
}

Clothing::Clothing(const Clothing &c) : Article(c), clothingSize(c.clothingSize), color(c.color) {
    cout << "DEBUG COPY CONSTRUCTOR CLOTHING" << endl;
}

Clothing &Clothing::operator=(Clothing clothing) {
    Article::operator=(clothing);
    swap(clothingSize, clothing.clothingSize);
    swap(color, clothing.color);
    return *this;
}

Clothing::~Clothing() {
    cout << "CLOTHING DESTRUCTOR DEBUG" << endl;
}

shared_ptr<Article> Clothing::copy() const {
    return make_shared<Clothing>(*this);
}

string Clothing::toString() const {
    int space = 10;
    stringstream str;
    str << Article::toString();
    str << "    Size: "  << clothingSize << setw(space-clothingSize.length()) << "  ";
    str << "Color: "  << color << setw(space-color.length()) << "\t";
    return str.str();
}

std::string Clothing::getClothingSize() const {
    return clothingSize;
}

std::string Clothing::getColor() const {
    return color;
}

void Clothing::setClothingSize(const string &clothingSize) {
    check<ClothingException>(!clothingSize.empty(), EMPTY_CLOTHING_SIZE);
    check<ClothingException>(clothingSize.length() <= MAX_STRING_ATTRIBUTE_SIZE, CLOTHING_SIZE_LIMIT_EXCEEDED);
    this->clothingSize = clothingSize;
}

void Clothing::setColor(const string &color) {
    check<ClothingException>(!color.empty(), EMPTY_COLOR);
    check<ClothingException>(color.length() <= MAX_STRING_ATTRIBUTE_SIZE, COLOR_LIMIT_EXCEEDED);

    this->color = color;
}
