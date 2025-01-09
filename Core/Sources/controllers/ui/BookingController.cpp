#include "../headers/BookingController.h"
#include <iostream>

void BookingController::handleVisitRequest(const std::string& clientName, const std::vector<std::string>& preferredDates) {
    VisitRequest visitRequest(clientName, preferredDates);

    if (!service.requestVisit(visitRequest)) {
        std::cerr << "Failed to process visit request.\n";
    }
}

