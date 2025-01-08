#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"

MemoryRepositoryFactory::MemoryRepositoryFactory() {
}

shared_ptr<CategoryRepository> MemoryRepositoryFactory::getCategoriesRepo() {
    return this->categories;
}