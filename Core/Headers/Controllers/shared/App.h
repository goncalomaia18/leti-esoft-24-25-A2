#ifndef TASKS_APP_H
#define TASKS_APP_H

#include <mutex>
#include <memory>
#include "headers/domain/model/Person.h"

using namespace std;

/**
 * Inspired on https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
 *
 * The App class works as aSingleton. It defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients classes access the same instance of this
 * class over and over.
 */
class App {
/**
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
private:
    static App *pinstance_;
    static mutex mutex_;
    shared_ptr<Person> person;

    shared_ptr<RepositoryFactory> createRepositoryFactory(const wstring &persistenceMode);

protected:
    App();

    ~App();

public:
    /**
     * Singletons should not be cloneable.
     */
    App(App &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const App &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static App *GetInstance();

    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    shared_ptr<Person> getPerson();

};

#endif //TASKS_APP_H