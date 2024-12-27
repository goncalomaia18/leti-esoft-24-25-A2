#ifndef LETI_ESOFT_24_25_A2_PROPERTY_CONTAINER_H
#define LETI_ESOFT_24_25_A2_PROPERTY_CONTAINER_H

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

#endif // LETI_ESOFT_24_25_A2_PROPERTY_CONTAINER_H
