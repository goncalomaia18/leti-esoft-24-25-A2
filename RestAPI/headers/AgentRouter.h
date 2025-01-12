//
// Created by pedro on 12/01/2025.
//

#ifndef AGENTROUTER_H
#define AGENTROUTER_H


#include <../RestAPI/thirdparty/httplib.h>
#include <headers/controllers/restapi/AgentController.h>

class AgentRouter {
public:
    static void configure(httplib::Server& svr);
};


#endif //AGENTROUTER_H
