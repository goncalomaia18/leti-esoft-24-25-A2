#include "../headers/DisplayListedPropertiesController.h"

DisplayListedPropertiesController::DisplayListedPropertiesController(DisplayListedPropertiesService* service)
        : service(service) {}

std::vector<Property> DisplayListedPropertiesController::listProperties() {
    return service->getListedProperties();
}

std::vector<Property> DisplayListedPropertiesController::filterProperties(const std::string& criteria) {
    return service->getFilteredProperties(criteria);
}
//
// Created by pedro on 07/12/2024.
//
