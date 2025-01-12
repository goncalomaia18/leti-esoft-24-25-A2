#include "headers/controllers/restapi/PropertyController.h"

#include <string>

std::string PropertyController::getAllProperties() {
    std::string properties = R"([
        {
            "id": 1,
            "title": "Luxury Apartment in Downtown",
            "price": 500000,
            "location": "Downtown City",
            "status": "Available"
        },
        {
            "id": 2,
            "title": "Cozy Cottage in the Countryside",
            "price": 250000,
            "location": "Countryside",
            "status": "Available"
        },
        {
            "id": 3,
            "title": "Modern Office Space",
            "price": 750000,
            "location": "Business District",
            "status": "Available"
        }
    ])";
    return properties;
}
