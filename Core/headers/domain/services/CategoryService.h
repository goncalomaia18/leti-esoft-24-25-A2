#ifndef TASKS_CATEGORYSERVICE_H
#define TASKS_CATEGORYSERVICE_H

#include <headers/domain/repositories/CategoryRepository.h>

class CategoryService {
private:
    shared_ptr<CategoryRepository> repo;

public:
    CategoryService(shared_ptr<CategoryRepository> repo);

    virtual shared_ptr<Category> create(const wstring &code, const wstring &description);

    virtual Result addOrUpdate(shared_ptr<Category> obj);

    virtual Result remove(const wstring &code);

    virtual Result changeDescription(const wstring &code, const wstring &description);

    virtual list<shared_ptr<Category>> getAll();

    virtual optional<shared_ptr<Category>> getByCode(const wstring &code);
};

#endif //TASKS_CATEGORYSERVICE_H