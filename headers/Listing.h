#ifndef LISTING_H
#define LISTING_H

#include <string>
#include "Property.h"

using namespace std;

class Sale;       // Forward declaration
class Lease;
class Advertisement;

class Listing {
private:
    Property* property;
    string publishDate;
    string businessType; // "For Sale" or "For Rent"
    double commission;
    Sale* sale;
    Lease* lease;
    Advertisement* advertisement;

public:
    Listing(Property* property, const string& publishDate, const string& businessType, double commission);

    // Getters
    Property* getProperty() const;
    const string& getPublishDate() const;
    const string& getBusinessType() const;
    double getCommission() const;
    Sale* getSale() const;
    Lease* getLease() const;
    Advertisement* getAdvertisement() const;

    // Setters
    void setSale(Sale* sale);
    void setLease(Lease* lease);
    void setAdvertisement(Advertisement* advertisement);
    void printDetails() const;

};

#endif // LISTING_H
