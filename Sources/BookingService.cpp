#include "../headers/BookingService.h"
#include <iostream>

bool BookingService::requestVisit(const VisitRequest& visitRequest) {
    if (!visitRequest.isValid()) {
        std::cerr << "Invalid visit request: Ensure date format is correct and no more than 3 dates are provided.\n";
        return false;
    }

    // Simulate saving the request to a database or processing it
    std::cout << "Visit request for client \"" << visitRequest.getClientName() << "\" has been successfully submitted.\n";
    std::cout << "Preferred dates:\n";
    for (const auto& date : visitRequest.getPreferredDates()) {
        std::cout << "- " << date << "\n";
    }

    return true;
}
