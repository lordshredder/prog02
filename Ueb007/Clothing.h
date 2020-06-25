/**
 *
 *  @file Clothing.h
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */
#pragma once


#include "Article.h"

class Clothing : public Article {
public:
    static const int MAX_STRING_ATTRIBUTE_SIZE = 16;
    static const std::string EMPTY_CLOTHING_SIZE;
    static const std::string CLOTHING_SIZE_LIMIT_EXCEEDED;
    static const std::string EMPTY_COLOR;
    static const std::string COLOR_LIMIT_EXCEEDED;
    Clothing(int articleNr, const std::string& description, long double price, const std::string& clothingSize, const std::string& color, int stock = 0);
    Clothing(const Clothing& c);
    Clothing& operator=(Clothing clothing);
    virtual ~Clothing();

    virtual shared_ptr<Article> copy() const override;
    std::string getClothingSize() const;
    std::string getColor() const;
    void setClothingSize(const std::string& clothingSize);
    void setColor(const std::string& color);
    virtual std::string toString() const override;
protected:
    std::string clothingSize;
    std::string color;
};