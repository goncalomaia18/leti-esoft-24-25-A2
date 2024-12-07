#ifndef CONSOLEAPP_BOOKINGCONTROLLER_H
#define CONSOLEAPP_BOOKINGCONTROLLER_H

#include "BookingService.h"
#include <vector>
#include <string>

class BookingController {
private:
    BookingService service;

public:
    void handleVisitRequest(const std::string& clientName, const std::vector<std::string>& preferredDates);
};

#endif //CONSOLEAPP_BOOKINGCONTROLLER_H
