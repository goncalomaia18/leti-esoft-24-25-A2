#include "../../../headers/domain/model/Lease.h"

Lease::Lease(double monthlyRent, int period, const std::string& startDate,
             const std::string& endDate, RealEstateAgent* agent, Client* tenant)
        : monthlyRent(monthlyRent), leasePeriod(period), leaseStartDate(startDate),
          leaseEndDate(endDate), managingAgent(agent), tenant(tenant) {}

double Lease::getMonthlyRent() const { return monthlyRent; }
int Lease::getLeasePeriod() const { return leasePeriod; }
std::string Lease::getLeaseStartDate() const { return leaseStartDate; }
std::string Lease::getLeaseEndDate() const { return leaseEndDate; }
RealEstateAgent* Lease::getManagingAgent() const { return managingAgent; }
Client* Lease::getTenant() const { return tenant; }

void Lease::setMonthlyRent(double rent) { monthlyRent = rent; }
void Lease::setLeasePeriod(int period) { leasePeriod = period; }
void Lease::setLeaseStartDate(const std::string& startDate) { leaseStartDate = startDate; }
void Lease::setLeaseEndDate(const std::string& endDate) { leaseEndDate = endDate; }
void Lease::setManagingAgent(RealEstateAgent* agent) { managingAgent = agent; }
void Lease::setTenant(Client* tenant) { tenant = tenant; }
//
// Created by pedro on 07/12/2024.
//
