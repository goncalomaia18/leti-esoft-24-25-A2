#include "../headers/StoreRouter.h"
#include "../headers/models/Store.h"
#include "../services/StoreService.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

StoreRouter::StoreRouter() = default;

void StoreRouter::configure(httplib::Server &svr) {
    // Endpoint to create a new store
    svr.Post("/stores", [](const httplib::Request &req, httplib::Response &res) {
        try {
            auto body = json::parse(req.body);

            std::string code = body["code"];
            std::string name = body["name"];
            std::string address = body["address"];
            std::string openingTime = body["openingTime"];
            std::string closingTime = body["closingTime"];

            Store store(code, name, address, openingTime, closingTime);
            StoreService::saveStore(store); // Save store to database or in-memory

            res.set_content("Store successfully created.", "text/plain");
            res.status = 201;
        } catch (const std::exception &e) {
            res.set_content(e.what(), "text/plain");
            res.status = 400;
        }
    });

    // Endpoint to retrieve all stores
    svr.Get("/stores", [](const httplib::Request &req, httplib::Response &res) {
        try {
            auto stores = StoreService::getAllStores();
            json response = json::array();

            for (const auto &store : stores) {
                json storeJson = {
                        {"code", store.getCode()},
                        {"name", store.getName()},
                        {"address", store.getAddress()},
                        {"openingTime", store.getOpeningTime()},
                        {"closingTime", store.getClosingTime()}
                };
                response.push_back(storeJson);
            }

            res.set_content(response.dump(), "application/json");
            res.status = 200;
        } catch (const std::exception &e) {
            res.set_content(e.what(), "text/plain");
            res.status = 500;
        }
    });
}

