#ifndef TASKS_CATEGORYCONTROLLER_H
#define TASKS_CATEGORYCONTROLLER_H

#include <string>
#include <memory>
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"
#include "RestController.h"
#include "HttpResult.h"

class CategoryController : public RestController {
protected:

public:
    CategoryController(const wstring &userToken) : RestController(userToken) {};

    CategoryController(shared_ptr<Person> person, const wstring &userToken) : RestController(person, userToken) {};

    HttpResult getAll();

    HttpResult getById(const wstring &code);

    HttpResult postCategory(const wstring &code, const wstring &description);

    HttpResult putCategory(const wstring &code, const wstring &description);

    HttpResult deleteCategory(const wstring &code);
};

#endif //TASKS_CATEGORYCONTROLLER_H