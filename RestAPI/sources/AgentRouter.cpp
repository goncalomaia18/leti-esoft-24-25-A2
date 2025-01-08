#include "../headers/AgentRouter.h"

AgentRouter::AgentRouter() = default;

void AgentRouter::configure(httplib::Server &svr) {
    // Register a new agent
    svr.Post("/agents", [](const httplib::Request &req, httplib::Response &res) {
        try {
            auto body = json::parse(req.body);
            string name = body["name"];
            string citizenCardNumber = body["citizenCardNumber"];
            string email = body["email"];
            string phoneNumber = body["phoneNumber"];

            RealEstateAgent agent(name, citizenCardNumber, email, phoneNumber);
            AgentService::saveAgent(agent); // Save agent to persistence layer
            res.set_content("Agent successfully created.", "text/plain");
            res.status = 201;
        } catch (const exception &e) {
            res.set_content(e.what(), "text/plain");
            res.status = 400;
        }
    });

    // Get a list of all agents
    svr.Get("/agents", [](const httplib::Request &req, httplib::Response &res) {
        try {
            auto agents = AgentService::getAllAgents(); // Retrieve agents from persistence layer
            json response = json::array();
            for (const auto &agent : agents) {
                json agentJson = {
                        {"name", agent.getName()},
                        {"citizenCardNumber", agent.getCitizenCardNumber()},
                        {"email", agent.getEmail()},
                        {"phoneNumber", agent.getPhoneNumber()}
                };
                response.push_back(agentJson);
            }
            res.set_content(response.dump(), "application/json");
            res.status = 200;
        } catch (const exception &e) {
            res.set_content(e.what(), "text/plain");
            res.status = 500;
        }
    });
}
//
// Created by pedro on 08/01/2025.
//
