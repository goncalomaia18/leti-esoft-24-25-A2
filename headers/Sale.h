//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_SALE_H
#define LETI_ESOFT_24_25_A2_SALE_H

#include <string>
#include "RealEstateAgent.h"
#include "Client.h"

class Sale {
private:
    double saleValue;
    RealEstateAgent* responsibleAgent;
    Client* buyerClient;

public:
    Sale(double saleValue, RealEstateAgent* agent, Client* buyer);

    double getSaleValue() const;
    RealEstateAgent* getResponsibleAgent() const;
    Client* getBuyerClient() const;

    void setSaleValue(double value);
    void setResponsibleAgent(RealEstateAgent* agent);
    void setBuyerClient(Client* buyer);
};



#endif //LETI_ESOFT_24_25_A2_SALE_H
