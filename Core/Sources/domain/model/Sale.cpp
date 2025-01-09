//
// Created by pedro on 07/12/2024.
//

#include "../../../headers/domain/model/Sale.h"

Sale::Sale(double saleValue, RealEstateAgent* agent, Client* buyer)
        : saleValue(saleValue), responsibleAgent(agent), buyerClient(buyer) {}

double Sale::getSaleValue() const { return saleValue; }
RealEstateAgent* Sale::getResponsibleAgent() const { return responsibleAgent; }
Client* Sale::getBuyerClient() const { return buyerClient; }

void Sale::setSaleValue(double value) { saleValue = value; }
void Sale::setResponsibleAgent(RealEstateAgent* agent) { responsibleAgent = agent; }
void Sale::setBuyerClient(Client* buyer) { buyerClient = buyer; }

