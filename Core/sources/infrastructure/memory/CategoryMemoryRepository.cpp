#include "headers/infrastructure/memory/CategoryMemoryRepository.h"

using namespace std;

CategoryMemoryRepository::CategoryMemoryRepository() : MemoryRepository<Category, CategoryId>() {
}

optional<shared_ptr<Category>> CategoryMemoryRepository::getById(const wstring &code) {
    for (list<shared_ptr<Category>>::iterator it = container.begin(); it != container.end(); ++it) {
        shared_ptr<Category> obj = *it;
        if (obj->hasCode(code))
            return make_optional<shared_ptr<Category>>(obj);
    }
    return nullopt;
}