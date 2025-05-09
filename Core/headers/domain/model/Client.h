//
// Created by luisf on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_CLIENT_H
#define LETI_ESOFT_24_25_A2_CLIENT_H

#include <string>
#include <vector>
#include "Listing.h"
#include "Visit.h"

class Visit;
using namespace std;

class Client {
private:
    string name;
    string citizenCardNumber;
    string taxIdNumber;
    string email;
    string phoneNumber;
    vector<Listing*> listings;
    vector<Visit*> visits;

public:
    Client(const string& name, const string& citizenCardNumber, const string& taxIdNumber,
           const string& email, const string& phoneNumber);

    // Methods
    void requestListing(Listing* listing);
    void requestVisit(Visit* visit);

    // Getters
    const vector<Listing*>& getListings() const;
    const vector<Visit*>& getVisits() const;
};

#endif // LETI_ESOFT_24_25_A2_CLIENT_H
