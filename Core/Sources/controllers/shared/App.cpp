#include "headers/controllers/shared/App.h"
#include "headers/controllers/shared/ConfigFileReader.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"

using namespace std;

/**
 * Static methods should be defined outside the class.
 */

App *App::pinstance_{nullptr};
std::mutex App::mutex_;

/**
 * Instance Methods
 */
App::App() {
    ConfigFileReader reader;
    ConfigObject cfg = reader.read_config("config.ini");
    shared_ptr<RepositoryFactory> repoFactory = this->createRepositoryFactory(cfg.persistenceMode);
    this->person = make_shared<Person>(cfg.personName, repoFactory);
}

App::~App() {
}

shared_ptr<Person> App::getPerson() {
    return this->person;
}

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
App *App::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new App();
    }
    return pinstance_;
}

shared_ptr<RepositoryFactory> App::createRepositoryFactory(const wstring &persistenceMode) {

    // By now the only known/available RepositoryFactory is the MemoryRepositoryFactory
    // Further, the "persistenceMode" argument must be evaluated to decide which one to create
    // repoFactory = make_shared<MemoryRepositoryFactory>();
    shared_ptr<RepositoryFactory> repoFactory = make_shared<MemoryRepositoryFactory>();
    return repoFactory;
}