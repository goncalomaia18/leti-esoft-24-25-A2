#ifndef TASKS_CATEGORYMEMORYREPOSITORY_H
#define TASKS_CATEGORYMEMORYREPOSITORY_H

#include <list>
#include <optional>
#include <memory>
#include "headers/domain/model/Category.h"
#include "headers/domain/repositories/CategoryRepository.h"
#include "headers/infrastructure/memory/MemoryRepository.h"

using namespace std;

class CategoryMemoryRepository : public CategoryRepository, public MemoryRepository<Category, CategoryId> {
private:
public:
    CategoryMemoryRepository();

    virtual optional<shared_ptr<Category>> getById(const wstring &code);
};

#endif //TASKS_CATEGORYMEMORYREPOSITORY_H