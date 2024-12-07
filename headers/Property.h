#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Property {
public:
    Property(const std::string& id, const std::string& description);

    const std::string& getId() const;
    const std::string& getDescription() const;
    bool isPublished() const;

    void publish();

private:
    std::string id;
    std::string description;
    bool published;
};

#endif // PROPERTY_H
