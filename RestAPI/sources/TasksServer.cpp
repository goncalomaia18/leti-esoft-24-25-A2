#include "../headers/TasksServer.h"
#include "../headers/ServerStatusRouter.h"
#include "../headers/PropertyRouter.h"
#include <iostream>

#include "../headers/AgentRouter.h"

namespace json {
    class JSON;
}

using namespace std;
using json::JSON;

TasksServer::TasksServer() {
    this->logger = &std::cout;
}

TasksServer::TasksServer(basic_ostream<char> *logger) {
    if (logger == nullptr)
        this->logger = &std::cout;
    else
        this->logger = logger;
}

void TasksServer::run() {
    this->run("0.0.0.0", 8080);
}

void TasksServer::run(int port) {
    this->run("0.0.0.0", port);
}

void TasksServer::run(string host, int port) {
    this->log("Welcome to the TasksRestAPI Server.");
    this->log("HTTP Server is being configured...");

    // ADDING ServerStatus Resource
    this->log("\t ... configuring server status resource...");
    ServerStatusRouter ssRouter;
    ssRouter.configure(this->svr);

    // ADDING Categories Resource
    this->log("\t ... configuring categories resource...");
    AgentRouter catRouter;
    catRouter.configure(this->svr);

    // ADD HERE OTHER RESOURCE CONFIGURATIONS


    // START LISTENING HTTP REQUESTS
    this->log("HTTP Server is listening on port " + std::to_string(port) + ".");

    this->svr.listen(host.data(), port);
    // SERVER IS STOPPING
    this->log("HTTP Server is stopping.");
}

void TasksServer::log(string message) {
    (*this->logger) << message << std::endl;
}