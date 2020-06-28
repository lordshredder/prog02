/**
 *
 *  @file Clothing.h
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */
#pragma once


#include "Article.h"

/**
 *  A subclass called Clothing, it inherits methods and attributes
 *  from the Article class. It also has it's own attributes called
 *  clothingSize and color.
 */
class Clothing : public Article {
public:
    static const int MAX_STRING_ATTRIBUTE_SIZE = 16;
    static const std::string EMPTY_CLOTHING_SIZE;
    static const std::string CLOTHING_SIZE_LIMIT_EXCEEDED;
    static const std::string EMPTY_COLOR;
    static const std::string COLOR_LIMIT_EXCEEDED;

    /**
     * Constructor for the subclass Clothing
     * @param articleNr The Number used to identify the clothing article. Must be 4 digits and positive.
     * @param description The description used for additional information. Cannot be empty or above the set limit.
     * @param price The price of the clothing article. Cannot be negative.
     * @param clothingSize The size of the clothing article.
     * @param color The color of the clothing article.
     * @param stock The quantity of the clothing article. Cannot be negative.
     */
    Clothing(int articleNr, const std::string& description, long double price, const std::string& clothingSize, const std::string& color, int stock = 0);
    /**
     * Copy constructor.
     * @param c The clothing article we're copying from.
     */
    Clothing(const Clothing& c);
    /**
     * Equals operator.
     * @param clothing The clothing article we're copying from.
     * @return The clothing article with new values from the parameter.
     */
    Clothing& operator=(Clothing clothing);
    /**
     * Destructor.
     */
    virtual ~Clothing();
    /**
     * Returns a copy of itself.
     * @return Copy of this object.
     */
    virtual shared_ptr<Article> copy() const override;
    std::string getClothingSize() const;
    std::string getColor() const;
    void setClothingSize(const std::string& clothingSize);
    void setColor(const std::string& color);
    /**
     * Simple toString method.
     * @return String of this object.
     */
    virtual std::string toString() const override;
protected:
    std::string clothingSize;
    std::string color;
};