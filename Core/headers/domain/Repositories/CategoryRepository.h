#ifndef TASKS_CATEGORYREPOSITORY_H
#define TASKS_CATEGORYREPOSITORY_H

#include "Repository.h"
#include "../model/Category.h"
#include "../model/CategoryId.h"

class CategoryRepository : virtual public Repository<Category, CategoryId> {
public:
    virtual optional<shared_ptr<Category>> getById(const wstring &code) = 0;
};

#endif //TASKS_CATEGORYREPOSITORY_H