#ifndef LETI_ESOFT_24_25_A2__BOOKINGSERVICE_H
#define LETI_ESOFT_24_25_A2__BOOKINGSERVICE_H

#include "VisitRequest.h"
#include <vector>
#include <string>

class BookingService {
public:
    bool requestVisit(const VisitRequest& visitRequest);
};

#endif //LETI_ESOFT_24_25_A2__BOOKINGSERVICE_H
