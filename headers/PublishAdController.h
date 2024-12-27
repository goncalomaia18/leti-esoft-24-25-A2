#ifndef LETI_ESOFT_24_25_A2_PUBLISH_AD_CONTROLLER_H
#define LETI_ESOFT_24_25_A2_PUBLISH_AD_CONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "models/Property.h"
#include "PropertyContainer.h"

class PublishAdController {
public:
    explicit PublishAdController(std::shared_ptr<PropertyContainer> propertyContainer);
    std::vector<std::shared_ptr<Property>> getUnpublishedProperties();
    void publishProperty(const std::string& propertyId);

private:
    std::shared_ptr<PropertyContainer> propertyContainer;
};

#endif // LETI_ESOFT_24_25_A2_PUBLISH_AD_CONTROLLER_H

