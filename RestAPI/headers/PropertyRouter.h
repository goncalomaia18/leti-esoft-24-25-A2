#ifndef TASKS_CATEGORYROUTER_H
#define TASKS_CATEGORYROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class Propertyouter : public PropertyConfig {
public:
    PropertyRouter();

    void configure(httplib::Server &svr);
};

#endif //TASKS_CATEGORYROUTER_H