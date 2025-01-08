#include "headers/controllers/ui/DeleteCategoryController.h"
#include <vector>

vector<shared_ptr<Category>> DeleteCategoryController::getAll() {
    this->service = this->person->getCategoriesService();
    list<shared_ptr<Category>> list = service->getAll();
    vector<shared_ptr<Category>> categories;
    /** Transforming a list into a vector --> adapting to the UI needs
     *  This differs from what was done on the UpdateCategoryController to show some diversity
     *  and explores the responsibilities of Controllers (i.e. serving as adapters)
    */
    for (shared_ptr<Category> cat: list)
        categories.push_back(cat);
    //
    return categories;
}

Result DeleteCategoryController::deleteCategory(const wstring &code) {
    return this->service->remove(code);
}