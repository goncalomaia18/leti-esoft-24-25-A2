#include "../headers/DisplayListedPropertiesView.h"
#include <iostream>

DisplayListedPropertiesView::DisplayListedPropertiesView(DisplayListedPropertiesController* controller)
        : controller(controller) {}

void DisplayListedPropertiesView::displayProperties(const std::vector<Property>& properties) {
    for (const auto& property : properties) {
        std::cout << "Property Type: " << property.getType() << "\n";
        std::cout << "Location: " << property.getLocation() << "\n";
        std::cout << "Price: $" << property.getPrice() << "\n";
        std::cout << "-----------------------------\n";
    }
}

void DisplayListedPropertiesView::requestToDisplayProperties() {
    std::vector<Property> properties = controller->listProperties();
    displayProperties(properties);
}

void DisplayListedPropertiesView::applyFilters(const std::string& criteria) {
    std::vector<Property> filteredProperties = controller->filterProperties(criteria);
    displayProperties(filteredProperties);
}
//
// Created by pedro on 07/12/2024.
//
