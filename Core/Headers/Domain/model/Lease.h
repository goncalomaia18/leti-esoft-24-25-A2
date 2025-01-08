//
// Created by pedro on 07/12/2024.
//

#ifndef LETI_ESOFT_24_25_A2_LEASE_H
#define LETI_ESOFT_24_25_A2_LEASE_H

#include <string>
#include "RealEstateAgent.h"
#include "Client.h"

class Lease {
private:
    double monthlyRent;
    int leasePeriod;
    std::string leaseStartDate;
    std::string leaseEndDate;
    RealEstateAgent* managingAgent;
    Client* tenant;

public:
    Lease(double monthlyRent, int period, const std::string& startDate,
          const std::string& endDate, RealEstateAgent* agent, Client* tenant);

    double getMonthlyRent() const;
    int getLeasePeriod() const;
    std::string getLeaseStartDate() const;
    std::string getLeaseEndDate() const;
    RealEstateAgent* getManagingAgent() const;
    Client* getTenant() const;

    void setMonthlyRent(double rent);
    void setLeasePeriod(int period);
    void setLeaseStartDate(const std::string& startDate);
    void setLeaseEndDate(const std::string& endDate);
    void setManagingAgent(RealEstateAgent* agent);
    void setTenant(Client* tenant);
};

#endif //LETI_ESOFT_24_25_A2_LEASE_H
