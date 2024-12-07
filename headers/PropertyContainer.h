#ifndef PROPERTY_CONTAINER_H
#define PROPERTY_CONTAINER_H

#include <vector>
#include <memory>
#include <string>
#include "Property.h"

class PropertyContainer {
public:
    std::vector<std::shared_ptr<Property>> getUnpublishedProperties();
    std::shared_ptr<Property> findById(const std::string& id);
    void save(std::shared_ptr<Property> property);

private:
    std::vector<std::shared_ptr<Property>> properties;
};

#endif // PROPERTY_CONTAINER_H
