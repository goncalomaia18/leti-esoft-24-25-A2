#ifndef TASKS_RESTCONTROLLER_H
#define TASKS_RESTCONTROLLER_H

#include <string>
#include <memory>
#include "../../domain/model/Person.h"

class RestController {
protected:
    wstring userToken;
    shared_ptr<Person> person;

    bool ensureUserTokenIsValid();

    bool ensureUserHasRole(const wstring &role);

public:
    RestController(const wstring &userToken);

    RestController(shared_ptr<Person> person, const wstring &userToken);
};

#endif //TASKS_RESTCONTROLLER_H