
//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_LISTING_H
#define LETI_ESOFT_24_25_A2_LISTING_H


#include <string>
#include <vector>
#include "Advertisement.h"
#include "Sale.h"
#include "Lease.h"
#include "Property.h"

class Listing {
private:
    std::string publishDate;
    std::string businessType;
    double commission;
    std::string status;
    std::string title;
    std::string description;
    std::vector<std::string> tags;
    Property* property;             // Propriedade associada
    Advertisement* advertisement;
    Sale* sale;
    Lease* lease;

public:
    Listing(const std::string& publishDate, const std::string& businessType,
            double commission, const std::string& status,
            const std::string& title, const std::string& description,
            const std::vector<std::string>& tags, Property* property);

    std::string getPublishDate() const;
    std::string getBusinessType() const;
    double getCommission() const;
    std::string getStatus() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::vector<std::string> getTags() const;
    Property* getProperty() const;

    void setPublishDate(const std::string& publishDate);
    void setBusinessType(const std::string& businessType);
    void setCommission(double commission);
    void setStatus(const std::string& status);
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setTags(const std::vector<std::string>& tags);
    void setProperty(Property* property);

    void setAdvertisement(Advertisement* ad);
    Advertisement* getAdvertisement() const;
    void setSale(Sale* sale);
    Sale* getSale() const;
    void setLease(Lease* lease);
    Lease* getLease() const;
};

#endif //LETI_ESOFT_24_25_A2_LISTING_H
=======
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
>>>>>>> main
