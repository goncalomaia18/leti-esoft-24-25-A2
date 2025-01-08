#ifndef TASKS_CATEGORYID_H
#define TASKS_CATEGORYID_H

#include "Entity.h"

class CategoryId : public EntityId {
protected:
    bool isValueValid(const wstring &value) override {
        return !(value.empty() || value.length() < 5);
    };

public:
    CategoryId(const wstring &value) : EntityId(value) {
        this->setValue(value);
    };
};

#endif //TASKS_CATEGORYID_H