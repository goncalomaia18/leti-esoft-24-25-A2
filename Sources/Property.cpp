#include "Property.h"
#include <stdexcept>

Property::Property(const std::string& id, const std::string& description)
    : id(id), description(description), published(false) {}

const std::string& Property::getId() const {
    return id;
}

const std::string& Property::getDescription() const {
    return description;
}

bool Property::isPublished() const {
    return published;
}

void Property::publish() {
    if (published) {
        throw std::logic_error("Property is already published.");
    }
    published = true;
}
