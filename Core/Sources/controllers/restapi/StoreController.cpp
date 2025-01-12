#include "../Core/headers/controllers/restapi/StoreController.h"

#include <iostream>
#include <regex>
#include <sstream>
#include <unordered_set>
#include <vector>

// Define the store codes as a class member
std::unordered_set<std::string> StoreController::storeCodes;

// Helper function to extract a value from a JSON-like string
std::string extractValue(const std::string& json, const std::string& key) {
    std::size_t keyPos = json.find("\"" + key + "\":");
    if (keyPos == std::string::npos) return "";

    keyPos += key.length() + 3; // Move past `"key":`
    char delimiter = json[keyPos] == '"' ? '"' : '\0'; // Check if it's a string (enclosed in quotes)
    std::size_t valueStart = delimiter ? keyPos + 1 : keyPos;
    std::size_t valueEnd = delimiter ? json.find("\"", valueStart) : json.find(",", valueStart);

    if (delimiter && valueEnd == std::string::npos) valueEnd = json.find("}", valueStart);
    if (!delimiter && valueEnd == std::string::npos) valueEnd = json.length();

    return json.substr(valueStart, valueEnd - valueStart);
}

// Validate store code format
bool StoreController::isValidStoreCode(const std::string& code) {
    std::regex codeRegex("^[a-zA-Z0-9]{5}$");
    return std::regex_match(code, codeRegex);
}

// Validate time format (hh:mm)
bool StoreController::isValidTime(const std::string& time) {
    std::regex timeRegex("^([01]\\d|2[0-3]):[0-5]\\d$");
    return std::regex_match(time, timeRegex);
}

// Process a single store's registration
std::string StoreController::processSingleStore(const std::string& storeData) {
    std::cout << "Processing single store data: " << storeData << "\n";

    std::string storeCode = extractValue(storeData, "storeCode");
    std::string openingTime = extractValue(storeData, "openingTime");
    std::string closingTime = extractValue(storeData, "closingTime");

    std::cout << "Extracted storeCode: " << storeCode << "\n";
    std::cout << "Extracted openingTime: " << openingTime << "\n";
    std::cout << "Extracted closingTime: " << closingTime << "\n";

    if (storeCode.empty() || !isValidStoreCode(storeCode)) {
        return "Error: Invalid or missing storeCode. Must be exactly 5 alphanumeric characters.";
    }
    if (openingTime.empty() || !isValidTime(openingTime)) {
        return "Error: Invalid or missing openingTime. Must be in the format hh:mm.";
    }
    if (closingTime.empty() || !isValidTime(closingTime)) {
        return "Error: Invalid or missing closingTime. Must be in the format hh:mm.";
    }

    if (storeCodes.find(storeCode) != storeCodes.end()) {
        return "Error: Store code must be unique.";
    }

    storeCodes.insert(storeCode);
    return "Success: Store registered successfully.";
}


// Register a store with manual JSON parsing
std::string StoreController::registerStore(const std::string& storeData) {
    try {
        // Check if the JSON starts with '[' (array)
        if (!storeData.empty() && storeData[0] == '[') {
            std::vector<std::string> results;
            size_t start = 0, end = 0;

            // Split the array into individual JSON objects
            while ((start = storeData.find("{", end)) != std::string::npos) {
                end = storeData.find("}", start);
                if (end == std::string::npos) break;

                std::string singleStore = storeData.substr(start, end - start + 1);
                results.push_back(processSingleStore(singleStore));
            }

            // Combine the results into a single response
            std::ostringstream response;
            for (const auto& result : results) {
                response << result << "\n";
            }
            return response.str();
        } else {
            // Single JSON object
            return processSingleStore(storeData);
        }
    } catch (...) {
        return "Error: Unexpected error occurred.";
    }
}
