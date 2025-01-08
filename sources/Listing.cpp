<<<<<<< HEAD:Sources/Listing.cpp
#include "../headers/models/Listing.h"

Listing::Listing(const std::string& publishDate, const std::string& businessType,
                 double commission, const std::string& status,
                 const std::string& title, const std::string& description,
                 const std::vector<std::string>& tags, Property* property)
        : publishDate(publishDate), businessType(businessType),
          commission(commission), status(status), title(title),
          description(description), tags(tags), property(property),
          advertisement(nullptr), sale(nullptr), lease(nullptr) {}

std::string Listing::getPublishDate() const { return publishDate; }
std::string Listing::getBusinessType() const { return businessType; }
double Listing::getCommission() const { return commission; }
std::string Listing::getStatus() const { return status; }
std::string Listing::getTitle() const { return title; }
std::string Listing::getDescription() const { return description; }
std::vector<std::string> Listing::getTags() const { return tags; }
Property* Listing::getProperty() const { return property; }

void Listing::setPublishDate(const std::string& publishDate) { this->publishDate = publishDate; }
void Listing::setBusinessType(const std::string& businessType) { this->businessType = businessType; }
void Listing::setCommission(double commission) { this->commission = commission; }
void Listing::setStatus(const std::string& status) { this->status = status; }
void Listing::setTitle(const std::string& title) { this->title = title; }
void Listing::setDescription(const std::string& description) { this->description = description; }
void Listing::setTags(const std::vector<std::string>& tags) { this->tags = tags; }
void Listing::setProperty(Property* property) { this->property = property; }

void Listing::setAdvertisement(Advertisement* ad) { advertisement = ad; }
Advertisement* Listing::getAdvertisement() const { return advertisement; }

void Listing::setSale(Sale* sale) { this->sale = sale; }
Sale* Listing::getSale() const { return sale; }

void Listing::setLease(Lease* lease) { this->lease = lease; }
Lease* Listing::getLease() const { return lease; }

=======
//
// Created by luisf on 07/12/2024.
//

#include "../headers/models/Listing.h"
#include <iostream>
#include "../headers/models/Property.h"

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
>>>>>>> main:sources/Listing.cpp
