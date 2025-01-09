#ifndef TASKS_ENTITYID_H
#define TASKS_ENTITYID_H

#include <string>

using namespace std;

class EntityId {
private:
    wstring value;

protected:
    EntityId(const wstring &value);

    virtual void setValue(const wstring &value);

    virtual bool isValueValid(const wstring &value) = 0;

public:
    const wstring &getValue() const;

    virtual bool operator==(const EntityId &other) const;

    virtual bool operator<(const EntityId &other) const;
};

#endif //TASKS_ENTITYID_H