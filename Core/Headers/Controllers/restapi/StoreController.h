//
// Created by luisf on 12/01/2025.
//

#include <nlohmann/json.hpp>
#include <regex>
#include <unordered_set>

using json = nlohmann::json;

class StoreController {
private:
    std::unordered_set<std::string> storeCodes; // To store unique store codes

    bool isValidStoreCode(const std::string& code) {
        std::regex codeRegex("^[a-zA-Z0-9]{5}$");
        return std::regex_match(code, codeRegex);
    }

    bool isValidTime(const std::string& time) {
        std::regex timeRegex("^([01]\\d|2[0-3]):[0-5]\\d$");
        return std::regex_match(time, timeRegex);
    }

public:
    std::string registerStore(const json& storeData) {
        // Validate the store code
        if (!storeData.contains("storeCode") || !isValidStoreCode(storeData["storeCode"])) {
            return R"({"error": "Invalid or missing storeCode. Must be exactly 5 alphanumeric characters."})";
        }

        // Ensure the store code is unique
        if (storeCodes.find(storeData["storeCode"]) != storeCodes.end()) {
            return R"({"error": "Store code must be unique."})";
        }

        // Validate opening and closing times
        if (!storeData.contains("openingTime") || !isValidTime(storeData["openingTime"])) {
            return R"({"error": "Invalid or missing openingTime. Must be in the format hh:mm."})";
        }
        if (!storeData.contains("closingTime") || !isValidTime(storeData["closingTime"])) {
            return R"({"error": "Invalid or missing closingTime. Must be in the format hh:mm."})";
        }

        // Add the store to the collection of registered stores
        storeCodes.insert(storeData["storeCode"]);
        return R"({"message": "Store registered successfully."})";
    }
};
