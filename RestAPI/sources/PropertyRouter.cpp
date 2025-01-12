#include <../RestAPI/headers/PropertyRouter.h>

void PropertyRouter::configure(httplib::Server &svr) {
    PropertyController propertyController;

    svr.Get("/properties", [&](const httplib::Request &, httplib::Response &res) {
        res.set_content(propertyController.getAllProperties(), "application/json");
    });
}
