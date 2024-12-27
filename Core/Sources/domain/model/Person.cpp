#include "headers/domain/model/Person.h"
#include "headers/domain/shared/StringUtils.h"
#include "headers/domain/exceptions/TaskDomainError.h"

using namespace std;

Person::Person(const wstring &name, shared_ptr<RepositoryFactory> repoFactory) {
    if (!this->isNameValid(name))
        throw TaskDomainError("Invalid value for a person name.");
    this->name = StringUtils::trim(name);
    this->repoFactory = repoFactory;
}

bool Person::isNameValid(const wstring &name) {
    return StringUtils::ensureNotNullOrEmpty(name);
}

const wstring &Person::getName() const {
    return this->name;
}

shared_ptr<CategoryService> Person::getCategoriesService() {
    return make_shared<CategoryService>(this->repoFactory->getCategoriesRepo());
}