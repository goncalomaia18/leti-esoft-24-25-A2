#ifndef LETI_ESOFT_24_25_A2_VISITREQUEST_H
#define LETI_ESOFT_24_25_A2_VISITREQUEST_H

#include <string>
#include <vector>

class VisitRequest {
private:
    std::string clientName;
    std::vector<std::string> preferredDates; // Format: "dd-mm-yyyy hh:mm"

public:
    VisitRequest(const std::string& name, const std::vector<std::string>& dates);

    std::string getClientName() const;
    std::vector<std::string> getPreferredDates() const;

    bool isValid() const; // Validates format and date count
};

#endif //LETI_ESOFT_24_25_A2_VISITREQUEST_H
