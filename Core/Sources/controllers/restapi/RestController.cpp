#include "headers/controllers/restapi/RestController.h"
#include <stdexcept>
#include "headers/controllers/shared/App.h"
#include "headers/domain/shared/StringUtils.h"

RestController::RestController(const wstring &userToken) : RestController(App::GetInstance()->getPerson(), userToken) {
}

RestController::RestController(shared_ptr<Person> person, const wstring &userToken) {
    this->userToken = StringUtils::trim(userToken);
    this->person = person;
    if (!person)
        throw invalid_argument("Invalid argument: 'person' cannot be null.");
    if (!ensureUserTokenIsValid())
        throw invalid_argument("Invalid argument: 'userToken' is not valid.");
}

bool RestController::ensureUserTokenIsValid() {
    return StringUtils::ensureNotNullOrEmpty(this->userToken);
}

bool RestController::ensureUserHasRole(const wstring &role) {
    return (StringUtils::trim(role) == StringUtils::trim(this->userToken));
}