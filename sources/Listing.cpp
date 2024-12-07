//
// Created by luisf on 07/12/2024.
//

#include "../headers/Listing.h"
#include <iostream>
#include "../headers/Property.h"

using namespace std;

// Constructor
Listing::Listing(Property* property, const string& publishDate, const string& businessType, double commission)
    : property(property), publishDate(publishDate), businessType(businessType), commission(commission), sale(nullptr), lease(nullptr), advertisement(nullptr) {}

// Set the sale linked to this listing
void Listing::setSale(Sale* sale) {
    this->sale = sale;
}

// Get the property linked to this listing
Property* Listing::getProperty() const {
    return property;
}