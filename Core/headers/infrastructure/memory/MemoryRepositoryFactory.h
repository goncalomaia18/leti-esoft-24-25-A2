#ifndef TASKS_MEMORYREPOSITORYFACTORY_H
#define TASKS_MEMORYREPOSITORYFACTORY_H

#include "headers/domain/repositories/RepositoryFactory.h"

class MemoryRepositoryFactory : public RepositoryFactory {
private:
public:
    MemoryRepositoryFactory();

    virtual shared_ptr<CategoryRepository> getCategoriesRepo() override;
};

#endif //TASKS_MEMORYREPOSITORYFACTORY_H