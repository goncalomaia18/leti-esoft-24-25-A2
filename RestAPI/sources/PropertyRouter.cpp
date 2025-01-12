#include <../RestAPI/headers/PropertyRouter.h>

void PropertyRouter::configure(httplib::Server &svr) {
    PropertyController propertyController;

    svr.Get("/", [&](const httplib::Request &, httplib::Response &res) {
        res.set_content("<h1>Welcome to the API</h1><p>Use /properties to get the list of properties.</p>", "text/html");
    });

    svr.Get("/properties", [&](const httplib::Request &, httplib::Response &res) {
        res.set_content(propertyController.getAllProperties(), "application/json");
    });
}
