#include "../../../headers/domain/model/Category.h"
#include <stdexcept>

using namespace std;

Category::Category(const wstring &code, const wstring &description) : Entity(make_shared<CategoryId>(code)) {
    if (!this->isDescriptionValid(description))
        throw invalid_argument("Invalid value for description.");

    this->description = description;
}

const wstring &Category::getCode() const {
    return this->id->getValue();
}

const wstring &Category::getDescription() const {
    return this->description;
}

Result Category::changeDescription(const wstring &newDescription) {
    if (this->isDescriptionValid(newDescription)) {
        this->description = newDescription;
        return Result::OK();
    }
    return Result::NOK(L"Invalid category description.");
}

bool Category::isDescriptionValid(const wstring &description) {
    return !(description.empty());
}

bool Category::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}