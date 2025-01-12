#include "../Core/Headers/Controllers/restapi/AgentController.h"

#include <regex>
#include <iostream>
#include <sstream>

// Static member initialization
std::unordered_set<std::string> AgentController::agentEmails;

// Helper function to extract a value from a JSON-like string
std::string AgentController:: extractValue(const std::string& json, const std::string& key) {
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
// Helper to validate email format
bool AgentController::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

// Helper to validate name
bool AgentController::isValidName(const std::string& name) {
    return !name.empty() && name.length() >= 2;
}

// Helper to validate optional citizen card
bool AgentController::isValidCitizenCard(const std::string& citizenCard) {
    return citizenCard.empty() || (citizenCard.length() >= 8 && citizenCard.length() <= 12);
}

// Process a single agent registration
std::string AgentController::processSingleAgent(const std::string& agentData) {
    std::cout << "Processing agent data: " << agentData << "\n";

    std::string name = extractValue(agentData, "name");
    std::string email = extractValue(agentData, "email");
    std::string phoneNumber = extractValue(agentData, "phoneNumber");
    std::string citizenCard = extractValue(agentData, "citizenCard");

    if (name.empty() || !isValidName(name)) {
        return "Error: Invalid or missing name. Must be at least 2 characters long.";
    }
    if (email.empty() || !isValidEmail(email)) {
        return "Error: Invalid or missing email.";
    }
    if (phoneNumber.empty()) {
        return "Error: Missing phone number.";
    }
    if (!isValidCitizenCard(citizenCard)) {
        return "Error: Invalid citizen card number. Must be 8-12 characters or empty.";
    }
    if (agentEmails.find(email) != agentEmails.end()) {
        return "Error: Email must be unique.";
    }

    agentEmails.insert(email);
    return "Success: Agent registered successfully.";
}

// Register an agent with support for multiple inputs
std::string AgentController::registerAgent(const std::string& agentData) {
    try {
        // Check if the JSON starts with '[' (array)
        if (!agentData.empty() && agentData[0] == '[') {
            std::vector<std::string> results;
            size_t start = 0, end = 0;

            // Split the array into individual JSON objects
            while ((start = agentData.find("{", end)) != std::string::npos) {
                end = agentData.find("}", start);
                if (end == std::string::npos) break;

                std::string singleAgent = agentData.substr(start, end - start + 1);
                results.push_back(processSingleAgent(singleAgent));
            }

            // Combine the results into a single response
            std::ostringstream response;
            for (const auto& result : results) {
                response << result << "\n";
            }
            return response.str();
        } else {
            // Single JSON object
            return processSingleAgent(agentData);
        }
    } catch (...) {
        return "Error: Unexpected error occurred.";
    }
}


