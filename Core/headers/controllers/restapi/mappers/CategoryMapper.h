#ifndef TASKS_CATEGORYMAPPER_H
#define TASKS_CATEGORYMAPPER_H

#include "thirdparty/SimpleJson.hpp"
#include "../../../domain/model/Category.h"
#include <string>
#include <list>

using namespace std;
using json::JSON;

class CategoryMapper {
public:
    static JSON toJson(shared_ptr<Category> obj);

    static JSON toJson(list<shared_ptr<Category>> objs);
};

#endif //TASKS_CATEGORYMAPPER_H