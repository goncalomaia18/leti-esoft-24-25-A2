//
// Created by pedro on 08/01/2025.
//

#ifndef LETI_ESOFT_24_25_A2_AGENTROUTER_H
#define LETI_ESOFT_24_25_A2_AGENTROUTER_H
#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class AgentRouter : public RouterConfig {
public:
    AgentRouter();

    void configure(httplib::Server &svr);
};
#endif //LETI_ESOFT_24_25_A2_AGENTROUTER_H
