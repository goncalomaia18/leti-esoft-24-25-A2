#include "headers/controllers/ui/UpdateCategoryController.h"

list<shared_ptr<Category>> UpdateCategoryController::getAll() {
    this->service = this->person->getCategoriesService();
    return service->getAll();
}

Result UpdateCategoryController::updateCategory(const wstring &code, const wstring &description) {
    return this->service->changeDescription(code, description);
}