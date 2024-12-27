#ifndef TASKS_SERVERSTATUSROUTER_H
#define TASKS_SERVERSTATUSROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class ServerStatusRouter : public RouterConfig {
private:
    httplib::Server *server = nullptr;
public:
    ServerStatusRouter();

    void configure(httplib::Server &svr);
};

#endif //TASKS_SERVERSTATUSROUTER_H