//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESSERVICE_H
#define LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESSERVICE_H


#include <vector>
#include <string>
#include "ListingRepository.h"
#include "../headers/models/Property.h"

class DisplayListedPropertiesService {
private:
    ListingRepository* repository;

public:
    DisplayListedPropertiesService(ListingRepository* repository);

    std::vector<Property> getListedProperties();
    std::vector<Property> getFilteredProperties(const std::string& criteria);
};


#endif //LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESSERVICE_H
