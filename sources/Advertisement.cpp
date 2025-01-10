#include "../headers/models/Advertisement.h"

Advertisement::Advertisement(const std::string& id, double commission,
                             const std::string& visibilityStatus, Listing* listing)
        : id(id), commission(commission), visibilityStatus(visibilityStatus), listing(listing) {}

std::string Advertisement::getId() const { return id; }
double Advertisement::getCommission() const { return commission; }
std::string Advertisement::getVisibilityStatus() const { return visibilityStatus; }
Listing* Advertisement::getListing() const { return listing; }

void Advertisement::setId(const std::string& id) { this->id = id; }
void Advertisement::setCommission(double commission) { this->commission = commission; }
void Advertisement::setVisibilityStatus(const std::string& status) { visibilityStatus = status; }
void Advertisement::setListing(Listing* listing) { this->listing = listing; }
//
// Created by pedro on 07/12/2024.
//
