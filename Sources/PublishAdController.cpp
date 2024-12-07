#include "PublishAdController.h"
#include <stdexcept>

PublishAdController::PublishAdController(std::shared_ptr<PropertyContainer> propertyContainer)
    : propertyContainer(propertyContainer) {}

std::vector<std::shared_ptr<Property>> PublishAdController::getUnpublishedProperties() {
    return propertyContainer->getUnpublishedProperties();
}

void PublishAdController::publishProperty(const std::string& propertyId) {
    auto property = propertyContainer->findById(propertyId);
    if (!property) {
        throw std::invalid_argument("Property not found.");
    }

    property->publish();
    propertyContainer->save(property);
}
