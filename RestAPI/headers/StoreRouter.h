#ifndef STOREROUTER_H
#define STOREROUTER_H

#include <../RestAPI/thirdparty/httplib.h>

class StoreRouter {
public:
    static void configure(httplib::Server& svr);
};

#endif // STOREROUTER_H
