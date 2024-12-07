#ifndef PUBLISH_AD_CONTROLLER_H
#define PUBLISH_AD_CONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "Property.h"
#include "PropertyContainer.h"

class PublishAdController {
public:
    explicit PublishAdController(std::shared_ptr<PropertyContainer> propertyContainer);
    std::vector<std::shared_ptr<Property>> getUnpublishedProperties();
    void publishProperty(const std::string& propertyId);

private:
    std::shared_ptr<PropertyContainer> propertyContainer;
};

#endif // PUBLISH_AD_CONTROLLER_H

