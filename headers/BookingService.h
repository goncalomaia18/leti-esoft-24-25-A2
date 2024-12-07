#ifndef CONSOLEAPP_BOOKINGSERVICE_H
#define CONSOLEAPP_BOOKINGSERVICE_H

#include "VisitRequest.h"
#include <vector>
#include <string>

class BookingService {
public:
    bool requestVisit(const VisitRequest& visitRequest);
};

#endif //CONSOLEAPP_BOOKINGSERVICE_H
