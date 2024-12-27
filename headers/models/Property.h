#ifndef LETI_ESOFT_24_25_A2_PROPERTY_H
#define LETI_ESOFT_24_25_A2_PROPERTY_H

#include <string>
#include <vector>

class Property {
private:
    std::string type;
    double area;
    std::string location;
    double distanceFromCityCenter;
    double price;
    std::vector<std::string> photos;
    bool availability;
public:

    Property(const std::string& type, double area, const std::string& location,
             double distanceFromCityCenter, double price, const std::vector<std::string>& photos,
             bool availability);

    // Getters
    std::string getType() const;
    double getArea() const;
    std::string getLocation() const;
    double getDistanceFromCityCenter() const;
    double getPrice() const;
    std::vector<std::string> getPhotos() const;
    bool isAvailable() const;

    // Setters
    void setType(const std::string& type);
    void setArea(double area);
    void setLocation(const std::string& location);
    void setDistanceFromCityCenter(double distance);
    void setPrice(double price);
    void setPhotos(const std::vector<std::string>& photos);
    void setAvailability(bool availability);

    // Métodos adicionais (se necessário)
    void displayDetails() const; // Mostra detalhes da propriedade
};

#endif // LETI_ESOFT_24_25_A2_PROPERTY_H
