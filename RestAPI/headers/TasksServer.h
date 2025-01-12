#ifndef TASKS_TASKSSERVER_H
#define TASKS_TASKSSERVER_H

#include <iostream>
#include "../thirdparty/httplib.h"
#include <headers/controllers/restapi/HttpResult.h>

using namespace std;
using json::JSON;

class TasksServer {
private:
    basic_ostream<char> *logger;
    // HTTP
    httplib::Server svr;

    // HTTPS
    //httplib::SSLServer svr;
    void log(string message);

public:
    TasksServer();

    TasksServer(basic_ostream<char> *logger);

    void run();

    void run(int port);

    void run(string host, int port);
};

#endif //TASKS_TASKSSERVER_H