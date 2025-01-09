#include "headers/controllers/ui/ListCategoriesController.h"

const list<shared_ptr<Category>> ListCategoriesController::getAll() const {
    shared_ptr<CategoryService> service = this->person->getCategoriesService();
    return service->getAll();
}