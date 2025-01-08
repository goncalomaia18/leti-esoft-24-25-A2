#ifndef LETI_ESOFT_24_25_A2__BOOKINGCONTROLLER_H
#define LETI_ESOFT_24_25_A2__BOOKINGCONTROLLER_H

#include "../headers/models/BookingService.h"
#include <vector>
#include <string>

class BookingController {
private:
    BookingService service;

public:
    void handleVisitRequest(const std::string& clientName, const std::vector<std::string>& preferredDates);
};

#endif //LETI_ESOFT_24_25_A2__BOOKINGCONTROLLER_H
