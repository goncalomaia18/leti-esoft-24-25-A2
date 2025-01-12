//
// Created by luisf on 12/01/2025.
//

#include <../RestAPI/thirdparty/httplib.h>
#include "../Core/headers/controllers/restapi/StoreController.h"

class StoreRouter {
public:
    void configure(httplib::Server& svr) {
        StoreController storeController;

        // POST /stores to register a new store
        svr.Post("/stores", [&](const httplib::Request& req, httplib::Response& res) {
            try {
                // Parse the incoming JSON request
                json storeData = json::parse(req.body);

                // Pass the request data to the controller
                std::string response = storeController.registerStore(storeData);

                // Set the response
                res.set_content(response, "application/json");
            } catch (const std::exception& e) {
                // Handle JSON parsing errors
                res.status = 400; // Bad Request
                res.set_content(R"({"error": "Invalid JSON format."})", "application/json");
            }
        });
    }
};
