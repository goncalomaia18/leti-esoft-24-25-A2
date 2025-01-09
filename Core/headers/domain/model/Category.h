#ifndef TASKS_CATEGORY_H
#define TASKS_CATEGORY_H

#include <string>
#include "../shared/Result.h"
#include "CategoryId.h"

using namespace std;

class Category : public Entity<CategoryId> {
private:
    wstring description;

    Category();

    bool isDescriptionValid(const wstring &description);

public:
    Category(const wstring &code, const wstring &description);

    const wstring &getCode() const;

    const wstring &getDescription() const;

    Result changeDescription(const wstring &newDescription);

    bool hasCode(const wstring &code) const;
};

#endif //TASKS_CATEGORY_H