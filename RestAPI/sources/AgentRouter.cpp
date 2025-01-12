#include "../headers/AgentRouter.h"


void AgentRouter::configure(httplib::Server& svr) {
    AgentController agentController;

    svr.Post("/agents", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            // Pass the raw body to the controller
            std::string response = agentController.registerAgent(req.body);

            // Determine response status
            if (response.find("Error") == 0) {
                res.status = 400; // Bad Request
            } else {
                res.status = 200; // OK
            }

            // Set the response
            res.set_content(response, "text/plain");
        } catch (const std::exception& e) {
            // Handle generic errors
            res.status = 500; // Internal Server Error
            res.set_content("Error: An internal error occurred.", "text/plain");
        }
    });
}