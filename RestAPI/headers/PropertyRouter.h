#ifndef LETI_ESOFT_24_25_A2_STOREROUTER_H
#define LETI_ESOFT_24_25_A2_STOREROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class PropertyRouter : public PropertyConfig {
public:
    PropertyRouter();

    void configure(httplib::Server &svr);
};

#endif //LETI_ESOFT_24_25_A2_STOREROUTER_H