#include<stdexcept>
#include "headers/domain/model/EntityId.h"

EntityId::EntityId(const wstring &value) {
    this->value = value;
}

const wstring &EntityId::getValue() const {
    return this->value;
}

void EntityId::setValue(const wstring &value) {
    if (!this->isValueValid(value))
        throw invalid_argument("Invalid value for an Id.");
    this->value = value;
}

bool EntityId::operator==(const EntityId &other) const {
    if (&other == this) return true;
    return (this->value == other.value);
}

bool EntityId::operator<(const EntityId &other) const {
    return (this->value < other.value);
}