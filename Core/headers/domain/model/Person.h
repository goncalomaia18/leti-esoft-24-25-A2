#ifndef TASKS_PERSON_H
#define TASKS_PERSON_H

#include <string>
#include <memory>
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/services/CategoryService.h"

using namespace std;

class Person {
private:
    wstring name;
    shared_ptr<RepositoryFactory> repoFactory;

    bool isNameValid(const wstring &name);

public:
    Person(const wstring &name, shared_ptr<RepositoryFactory> repoFactory);

    const wstring &getName() const;

    virtual shared_ptr<CategoryService> getCategoriesService();
};

#endif //TASKS_PERSON_H