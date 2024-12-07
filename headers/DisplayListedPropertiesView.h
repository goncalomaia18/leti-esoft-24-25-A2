//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESVIEW_H
#define LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESVIEW_H
#include <vector>
#include <string>
#include "Property.h"
#include "DisplayListedPropertiesController.h"

class DisplayListedPropertiesView {
private:
    DisplayListedPropertiesController* controller;

public:
    DisplayListedPropertiesView(DisplayListedPropertiesController* controller);

    void displayProperties(const std::vector<Property>& properties);
    void requestToDisplayProperties();
    void applyFilters(const std::string& criteria);
};


#endif //LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESVIEW_H
