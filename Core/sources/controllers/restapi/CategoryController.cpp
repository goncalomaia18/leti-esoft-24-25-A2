#include "headers/controllers/restapi/CategoryController.h"
#include "headers/controllers/restapi/mappers/CategoryMapper.h"
#include <optional>

HttpResult CategoryController::getAll() {
    HttpResult result;
    try {
        shared_ptr<CategoryService> service = this->person->getCategoriesService();
        list<shared_ptr<Category>> cats = service->getAll();
        result = HttpResult(HttpStatus::HTTP_OK, CategoryMapper::toJson(cats));
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult CategoryController::getById(const wstring &code) {
    HttpResult result;
    try {
        shared_ptr<CategoryService> service = this->person->getCategoriesService();
        optional<shared_ptr<Category>> found = service->getByCode(code);
        if (found.has_value())
            result = HttpResult(HttpStatus::HTTP_OK, CategoryMapper::toJson(found.value()));
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult CategoryController::postCategory(const wstring &code, const wstring &description) {
    HttpResult result;
    try {
        shared_ptr<CategoryService> service = this->person->getCategoriesService();
        shared_ptr<Category> cat = service->create(code, description);
        Result res = service->addOrUpdate(cat);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK_CREATED);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult CategoryController::putCategory(const wstring &code, const wstring &description) {
    HttpResult result;
    try {
        shared_ptr<CategoryService> service = this->person->getCategoriesService();
        Result res = service->changeDescription(code, description);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult CategoryController::deleteCategory(const wstring &code) {
    HttpResult result;
    try {
        shared_ptr<CategoryService> service = this->person->getCategoriesService();
        Result res = service->remove(code);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND, res.getMessage());
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}