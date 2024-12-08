#include "../headers/BookingView.h"
#include <iostream>

void BookingView::displayBookingInterface() {
    std::string clientName;
    std::vector<std::string> preferredDates;
    std::string date;

    std::cout << "Enter your name: ";
    std::getline(std::cin, clientName);

    std::cout << "Enter up to 3 preferred dates (format: dd-mm-yyyy hh:mm). Type 'done' to finish:\n";

    while (preferredDates.size() < 3) {
        std::cout << "Date " << (preferredDates.size() + 1) << ": ";
        std::getline(std::cin, date);

        if (date == "done") break;
        preferredDates.push_back(date);
    }

    controller.handleVisitRequest(clientName, preferredDates);
}

