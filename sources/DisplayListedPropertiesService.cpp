#include "../headers/DisplayListedPropertiesService.h"

DisplayListedPropertiesService::DisplayListedPropertiesService(ListingRepository* repository)
        : repository(repository) {}

std::vector<Property> DisplayListedPropertiesService::getListedProperties() {
    std::vector<Listing> listings = repository->getListings();
    std::vector<Property> properties;

    for (const auto& listing : listings) {
        properties.push_back(listing.getProperty());
    }

    return properties;
}

std::vector<Property> DisplayListedPropertiesService::getFilteredProperties(const std::string& criteria) {
    std::vector<Listing> filteredListings = repository->getFilteredListings(criteria);
    std::vector<Property> filteredProperties;

    for (const auto& listing : filteredListings) {
        filteredProperties.push_back(listing.getProperty());
    }

    return filteredProperties;
}
//
// Created by pedro on 07/12/2024.
//
