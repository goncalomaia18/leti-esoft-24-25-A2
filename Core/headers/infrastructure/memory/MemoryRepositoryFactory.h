#ifndef TASKS_MEMORYREPOSITORYFACTORY_H
#define TASKS_MEMORYREPOSITORYFACTORY_H

#include "headers/domain/repositories/RepositoryFactory.h"
#include "CategoryMemoryRepository.h"

class MemoryRepositoryFactory : public RepositoryFactory {
private:
    shared_ptr<CategoryRepository> categories = make_shared<CategoryMemoryRepository>();

public:
    MemoryRepositoryFactory();

    virtual shared_ptr<CategoryRepository> getCategoriesRepo() override;
};

#endif //TASKS_MEMORYREPOSITORYFACTORY_H