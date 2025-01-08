#ifndef TASKS_LISTCATEGORIESCONTROLLER_H
#define TASKS_LISTCATEGORIESCONTROLLER_H

#include "AuthController.h"

using namespace std;

class ListCategoriesController : public AuthController {
private:
    shared_ptr<Category> category;

public:
    ListCategoriesController(const wstring &userToken) : AuthController(userToken) {};

    ListCategoriesController(shared_ptr<Person> person, const wstring &userToken) : AuthController(person, userToken) {};

    const list<shared_ptr<Category>> getAll() const;
};

#endif //TASKS_LISTCATEGORIESCONTROLLER_H