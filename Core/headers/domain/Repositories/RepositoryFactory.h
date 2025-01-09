#ifndef TASKS_REPOSITORYFACTORY_H
#define TASKS_REPOSITORYFACTORY_H

#include "CategoryRepository.h"

class RepositoryFactory {
public:
    virtual shared_ptr<CategoryRepository> getCategoriesRepo() = 0;
};

#endif //TASKS_REPOSITORYFACTORY_H