//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESCONTROLLER_H
#define LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESCONTROLLER_H

#include <vector>
#include <string>
#include "Property.h"
#include "DisplayListedPropertiesService.h"

class DisplayListedPropertiesController {
private:
    DisplayListedPropertiesService* service;

public:
    DisplayListedPropertiesController(DisplayListedPropertiesService* service);

    std::vector<Property> listProperties();
    std::vector<Property> filterProperties(const std::string& criteria);
};


#endif //LETI_ESOFT_24_25_A2_DISPLAYLISTEDPROPERTIESCONTROLLER_H
