//
// Created by luisf on 07/12/2024.
//
#include <iostream>
#include "../../../headers/domain/model/RealEstateAgent.h"
#include "../../../headers/domain/model/Property.h"

using namespace std;

// Constructor
RealEstateAgent::RealEstateAgent(const string& name, const string& citizenCardNumber, const string& email, const string& phoneNumber)
    : name(name), citizenCardNumber(citizenCardNumber), email(email), phoneNumber(phoneNumber) {}

// Assign a property to this agent
void RealEstateAgent::assignProperty(Property* property) {
    responsibleProperties.push_back(property);
}

// Get all properties managed by this agent
const vector<Property*>& RealEstateAgent::getResponsibleProperties() const {
    return responsibleProperties;
}
