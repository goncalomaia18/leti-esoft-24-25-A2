//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_LISTINGREPOSITORY_H
#define LETI_ESOFT_24_25_A2_LISTINGREPOSITORY_H


#include <vector>
#include "Listing.h"
#include "Property.h"

class ListingRepository {
public:
    virtual std::vector<Listing> getListings() = 0;
    virtual std::vector<Listing> getFilteredListings(const std::string& criteria) = 0;
    virtual void saveListing(const Listing& listing) = 0;
    virtual ~ListingRepository() = default;
};

#endif //LETI_ESOFT_24_25_A2_LISTINGREPOSITORY_H
