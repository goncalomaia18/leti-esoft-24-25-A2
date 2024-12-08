//
// Created by luisf on 07/12/2024.
//

#ifndef REALESTATEAGENT_H
#define REALESTATEAGENT_H

#include <string>
#include <vector>
#include "../headers/models/Property.h"
#include "../headers/models/Visit.h"

using namespace std;

class RealEstateAgent {
private:
    string name;
    string citizenCardNumber;
    string email;
    string phoneNumber;
    vector<Property*> responsibleProperties;
    vector<Visit*> scheduledVisits;

public:
    RealEstateAgent(const string& name, const string& citizenCardNumber, const string& email, const string& phoneNumber);

    // Methods
    void assignProperty(Property* property);
    void scheduleVisit(Visit* visit);

    // Getters
    const vector<Property*>& getResponsibleProperties() const;
    const vector<Visit*>& getScheduledVisits() const;
};

#endif // REALESTATEAGENT_H
