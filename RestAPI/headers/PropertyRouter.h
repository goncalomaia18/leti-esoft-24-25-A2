#ifndef PROPERTY_ROUTER_H
#define PROPERTY_ROUTER_H

#include <../RestAPI/thirdparty/httplib.h>
#include <headers/controllers/restapi/PropertyController.h>

class PropertyRouter {
public:
    void configure(httplib::Server &svr);
};

#endif //PROPERTY_ROUTER_H
