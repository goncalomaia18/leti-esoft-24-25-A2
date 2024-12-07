#include "../headers/PropertyContainer.h"


std::vector<std::shared_ptr<Property>> PropertyContainer::getUnpublishedProperties() {
    std::vector<std::shared_ptr<Property>> unpublished;
    for (const auto& property : properties) {
        if (!property->isPublished()) {
            unpublished.push_back(property);
        }
    }
    return unpublished;
}

std::shared_ptr<Property> PropertyContainer::findById(const std::string& id) {
    for (const auto& property : properties) {
        if (property->getId() == id) {
            return property;
        }
    }
    return nullptr;
}

void PropertyContainer::save(std::shared_ptr<Property> property) {
    // In a real application, this would save the property to a database.
    // Here, it simply ensures the property remains in the list.
    for (auto& existingProperty : properties) {
        if (existingProperty->getId() == property->getId()) {
            existingProperty = property;
            return;
        }
    }
    properties.push_back(property);
}
