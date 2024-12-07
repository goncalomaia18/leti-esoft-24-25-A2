//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_ADVERTISEMENT_H
#define LETI_ESOFT_24_25_A2_ADVERTISEMENT_H


#include <string>
#include "Listing.h"

class Advertisement {
private:
    std::string id;
    double commission;
    std::string visibilityStatus;
    Listing* listing;

public:
    Advertisement(const std::string& id, double commission,
                  const std::string& visibilityStatus, Listing* listing);

    std::string getId() const;
    double getCommission() const;
    std::string getVisibilityStatus() const;
    Listing* getListing() const;

    void setId(const std::string& id);
    void setCommission(double commission);
    void setVisibilityStatus(const std::string& status);
    void setListing(Listing* listing);
};

#endif //LETI_ESOFT_24_25_A2_ADVERTISEMENT_H
