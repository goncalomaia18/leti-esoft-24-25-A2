#include "../headers/VisitRequest.h"
#include <regex>

VisitRequest::VisitRequest(const std::string& name, const std::vector<std::string>& dates)
        : clientName(name), preferredDates(dates) {}

std::string VisitRequest::getClientName() const {
    return clientName;
}

std::vector<std::string> VisitRequest::getPreferredDates() const {
    return preferredDates;
}

bool VisitRequest::isValid() const {
    if (preferredDates.size() > 3) return false;

    std::regex dateTimeFormat(R"(\d{2}-\d{2}-\d{4} \d{2}:\d{2})");
    for (const auto& date : preferredDates) {
        if (!std::regex_match(date, dateTimeFormat)) {
            return false;
        }
    }
    return true;
}

