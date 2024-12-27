#ifndef TASKS_CATEGORYROUTER_H
#define TASKS_CATEGORYROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class CategoryRouter : public RouterConfig {
public:
    CategoryRouter();

    void configure(httplib::Server &svr);
};

#endif //TASKS_CATEGORYROUTER_H