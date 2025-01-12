#include "../Core/headers/controllers/restapi/StoreController.h"
#include <regex>
#include <sstream>

bool StoreController::isValidStoreCode(const std::string& code) {
    std::regex codeRegex("^[a-zA-Z0-9]{5}$");
    return std::regex_match(code, codeRegex);
}

bool StoreController::isValidTime(const std::string& time) {
    std::regex timeRegex("^([01]\\d|2[0-3]):[0-5]\\d$");
    return std::regex_match(time, timeRegex);
}

std::string StoreController::getFieldValue(const std::string& data, const std::string& fieldName) {
    std::size_t start = data.find(fieldName + "=");
    if (start == std::string::npos) return "";

    start += fieldName.length() + 1; // Move past "fieldName="
    std::size_t end = data.find("&", start);
    if (end == std::string::npos) end = data.length();

    return data.substr(start, end - start);
}

std::string StoreController::registerStore(const std::string& storeData) {
    // Parse fields from the raw string
    std::string storeCode = getFieldValue(storeData, "storeCode");
    std::string openingTime = getFieldValue(storeData, "openingTime");
    std::string closingTime = getFieldValue(storeData, "closingTime");

    // Validate the store code
    if (storeCode.empty() || !isValidStoreCode(storeCode)) {
        return "Error: Invalid or missing storeCode. Must be exactly 5 alphanumeric characters.";
    }

    // Ensure the store code is unique
    if (storeCodes.find(storeCode) != storeCodes.end()) {
        return "Error: Store code must be unique.";
    }

    // Validate opening and closing times
    if (openingTime.empty() || !isValidTime(openingTime)) {
        return "Error: Invalid or missing openingTime. Must be in the format hh:mm.";
    }
    if (closingTime.empty() || !isValidTime(closingTime)) {
        return "Error: Invalid or missing closingTime. Must be in the format hh:mm.";
    }

    // Add the store to the collection of registered stores
    storeCodes.insert(storeCode);
    return "Success: Store registered successfully.";
}
