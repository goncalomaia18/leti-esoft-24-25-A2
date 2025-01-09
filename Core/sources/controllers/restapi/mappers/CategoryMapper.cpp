#include "headers/controllers/restapi/mappers/CategoryMapper.h"
#include "thirdparty/SimpleJson.hpp"
#include <list>
#include "headers/domain/shared/StringUtils.h"

using namespace std;
using json::JSON;

JSON CategoryMapper::toJson(shared_ptr<Category> obj) {
    JSON result = JSON::Load("{}");
    result["code"] = StringUtils::toString(obj->getCode());
    result["description"] = StringUtils::toString(obj->getDescription());
    return result;
}

JSON CategoryMapper::toJson(list<shared_ptr<Category>> objs) {
    JSON result = JSON::Load("[]");
    int i = 0;
    for (shared_ptr<Category> cat: objs) {
        result[i] = CategoryMapper::toJson(cat);
        i++;
    }
    return result;
}