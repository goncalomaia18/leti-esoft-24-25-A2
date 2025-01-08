//
// Created by pedro on 08/01/2025.
//

#ifndef LETI_ESOFT_24_25_A2_STORE_H
#define LETI_ESOFT_24_25_A2_STORE_H

#include <string>
#include <vector>

class Store {
private:
    std::string code;
    std::string name;
    std::string address;
    std::string openingTime;
    std::string closingTime;

public:
    // Constructor
    Store(const std::string &code, const std::string &name, const std::string &address,
          const std::string &openingTime, const std::string &closingTime);

    // Getters
    std::string getCode() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getOpeningTime() const;
    std::string getClosingTime() const;

    // Setters
    void setCode(const std::string &code);
    void setName(const std::string &name);
    void setAddress(const std::string &address);
    void setOpeningTime(const std::string &openingTime);
    void setClosingTime(const std::string &closingTime);

    // Additional Methods
    void displayDetails() const;
};


#endif //LETI_ESOFT_24_25_A2_STORE_H
