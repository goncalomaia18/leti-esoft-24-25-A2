//
// Created by luisf on 07/12/2024.
//
#include <iostream>
#include "../headers/Visit.h"

using namespace std;

// Constructor
Visit::Visit(const string& visitDate, const string& visitTime, const string& status,
             bool visitAvailability, RealEstateAgent* agent, Property* property, Client* client)
    : visitDate(visitDate), visitTime(visitTime), status(status),
      visitAvailability(visitAvailability), scheduledBy(agent), property(property), client(client) {}

// Setters
void Visit::setVisitDate(const string& visitDate) {
    this->visitDate = visitDate;
}

void Visit::setVisitTime(const string& visitTime) {
    this->visitTime = visitTime;
}

void Visit::setStatus(const string& status) {
    this->status = status;
}

void Visit::setVisitAvailability(bool availability) {
    this->visitAvailability = availability;
}

// Getters
const string& Visit::getVisitDate() const {
    return visitDate;
}

const string& Visit::getVisitTime() const {
    return visitTime;
}

const string& Visit::getStatus() const {
    return status;
}

bool Visit::isVisitAvailable() const {
    return visitAvailability;
}

RealEstateAgent* Visit::getScheduledBy() const {
    return scheduledBy;
}

Property* Visit::getProperty() const {
    return property;
}

Client* Visit::getClient() const {
    return client;
}

// Method to print visit details
void Visit::printDetails() const {
    cout << "Visit Details:" << endl;
    cout << "Date: " << visitDate << endl;
    cout << "Time: " << visitTime << endl;
    cout << "Status: " << status << endl;
    cout << "Availability: " << (visitAvailability ? "Available" : "Not Available") << endl;
    cout << "Scheduled by: " << scheduledBy->getName() << endl;
    cout << "Property: " << property->getLocation() << endl;
    cout << "Client: " << client->getName() << endl;
}
