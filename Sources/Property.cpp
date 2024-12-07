#include "../headers/Property.h"
<<<<<<< HEAD:Sources/Property.cpp
#include <iostream>
=======
#include <stdexcept>
>>>>>>> main:sources/Property.cpp

// Construtor
Property::Property(const std::string& type, double area, const std::string& location,
                   double distanceFromCityCenter, double price, const std::vector<std::string>& photos,
                   bool availability)
        : type(type), area(area), location(location), distanceFromCityCenter(distanceFromCityCenter),
          price(price), photos(photos), availability(availability) {}

// Getters
std::string Property::getType() const { return type; }
double Property::getArea() const { return area; }
std::string Property::getLocation() const { return location; }
double Property::getDistanceFromCityCenter() const { return distanceFromCityCenter; }
double Property::getPrice() const { return price; }
std::vector<std::string> Property::getPhotos() const { return photos; }
bool Property::isAvailable() const { return availability; }

// Setters
void Property::setType(const std::string& type) { this->type = type; }
void Property::setArea(double area) { this->area = area; }
void Property::setLocation(const std::string& location) { this->location = location; }
void Property::setDistanceFromCityCenter(double distance) { this->distanceFromCityCenter = distance; }
void Property::setPrice(double price) { this->price = price; }
void Property::setPhotos(const std::vector<std::string>& photos) { this->photos = photos; }
void Property::setAvailability(bool availability) { this->availability = availability; }

// Método adicional: Mostrar detalhes
void Property::displayDetails() const {
    std::cout << "Type: " << type << "\n"
              << "Area: " << area << " m²\n"
              << "Location: " << location << "\n"
              << "Distance from City Center: " << distanceFromCityCenter << " km\n"
              << "Price: $" << price << "\n"
              << "Availability: " << (availability ? "Available" : "Not Available") << "\n"
              << "Photos:\n";
    for (const auto& photo : photos) {
        std::cout << "  - " << photo << "\n";
    }
}
