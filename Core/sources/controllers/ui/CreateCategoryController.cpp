#include "headers/controllers/shared/App.h"
#include "headers/controllers/ui/CreateCategoryController.h"

void CreateCategoryController::createCategory(const wstring &code, const wstring &description) {
    this->service = this->person->getCategoriesService();
    this->category = service->create(code, description);
}

Result CreateCategoryController::saveCreatedCategory() {
    if (this->category) {
        return this->service->addOrUpdate(this->category);
    }
    return Result::NOK(L"A category should be created first.");
}

Result CreateCategoryController::createAndSaveCategory(const wstring &code, const wstring &description) {
    return Result::NOK(L"not implemented yet");
}