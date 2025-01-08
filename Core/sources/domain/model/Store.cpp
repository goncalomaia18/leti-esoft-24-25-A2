#include "../headers/domain/model/Store.h"
#include <iostream>

// Constructor
Store::Store(const std::string &code, const std::string &name, const std::string &address,
             const std::string &openingTime, const std::string &closingTime)
        : code(code), name(name), address(address), openingTime(openingTime), closingTime(closingTime) {}

// Getters
std::string Store::getCode() const { return code; }
std::string Store::getName() const { return name; }
std::string Store::getAddress() const { return address; }
std::string Store::getOpeningTime() const { return openingTime; }
std::string Store::getClosingTime() const { return closingTime; }

// Setters
void Store::setCode(const std::string &code) { this->code = code; }
void Store::setName(const std::string &name) { this->name = name; }
void Store::setAddress(const std::string &address) { this->address = address; }
void Store::setOpeningTime(const std::string &openingTime) { this->openingTime = openingTime; }
void Store::setClosingTime(const std::string &closingTime) { this->closingTime = closingTime; }

// Display Details
void Store::displayDetails() const {
    std::cout << "Code: " << code << "\n"
              << "Name: " << name << "\n"
              << "Address: " << address << "\n"
              << "Opening Time: " << openingTime << "\n"
              << "Closing Time: " << closingTime << "\n";
}
