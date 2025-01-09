#include "headers/domain/services/CategoryService.h"

CategoryService::CategoryService(shared_ptr<CategoryRepository> repo) {
    this->repo = repo;
}

shared_ptr<Category> CategoryService::create(const wstring &code, const wstring &description) {
    return make_shared<Category>(code, description);
}

Result CategoryService::addOrUpdate(shared_ptr<Category> obj) {
    return this->repo->save(obj);
}

Result CategoryService::remove(const wstring &code) {
    optional<shared_ptr<Category>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Category> cat = obj.value();
        return this->repo->remove(cat);
    }
    return Result::NOK(L"Category not found.");
}

Result CategoryService::changeDescription(const wstring &code, const wstring &description) {
    optional<shared_ptr<Category>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Category> cat = obj.value();
        Result result = cat->changeDescription(description);
        if (result.isOK())
            return this->repo->save(cat);
        else
            return result;
    }
    return Result::NOK(L"Category not found.");
}

list<shared_ptr<Category>> CategoryService::getAll() {
    return this->repo->getAll();
}

optional<shared_ptr<Category>> CategoryService::getByCode(const wstring &code) {
    return this->repo->getById(code);
}