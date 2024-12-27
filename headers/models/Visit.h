//
// Created by luisf on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_VISIT_H
#define LETI_ESOFT_24_25_A2_VISIT_H

#include <string>
#include "RealEstateAgent.h"
#include "Property.h"
#include "Client.h"

using namespace std;

class RealEstateAgent;  // Forward declaration
class Property;         // Forward declaration
class Client;           // Forward declaration

class Visit {
private:
    string visitDate;          // Date of the visit
    string visitTime;          // Time of the visit
    string status;             // Status (e.g., "Scheduled", "Completed")
    bool visitAvailability;    // Whether the visit is available or not
    RealEstateAgent* scheduledBy;  // The agent who scheduled the visit
    Property* property;            // The property being visited
    Client* client;               // The client requesting the visit

public:
    // Constructor
    Visit(const string& visitDate, const string& visitTime, const string& status,
          bool visitAvailability, RealEstateAgent* agent, Property* property, Client* client);

    // Setters and getters
    void setVisitDate(const string& visitDate);
    void setVisitTime(const string& visitTime);
    void setStatus(const string& status);
    void setVisitAvailability(bool availability);

    const string& getVisitDate() const;
    const string& getVisitTime() const;
    const string& getStatus() const;
    bool isVisitAvailable() const;

    RealEstateAgent* getScheduledBy() const;
    Property* getProperty() const;
    Client* getClient() const;

    // Method to print visit details
    void printDetails() const;
};

#endif // LETI_ESOFT_24_25_A2_VISIT_H
