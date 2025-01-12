//
// Created by pedro on 12/01/2025.
#ifndef AGENT_CONTROLLER_H
#define AGENT_CONTROLLER_H
#include <unordered_set>
#include <string>

class AgentController {
private:
    static std::unordered_set<std::string> agentEmails;
    static std::string extractValue(const std::string& json, const std::string& key);
    // Helper functions
    bool isValidEmail(const std::string& email);
    bool isValidName(const std::string& name);
    bool isValidCitizenCard(const std::string& citizenCard);

    std::string processSingleAgent(const std::string& agentData);

public:
    std::string registerAgent(const std::string& agentData);
};

#endif //AGENT_CONTROLLER_H
