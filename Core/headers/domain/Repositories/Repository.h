#ifndef TASKS_REPOSITORY_H
#define TASKS_REPOSITORY_H

#include <type_traits>
#include <list>
#include <optional>
#include "../shared/Result.h"
#include "../model/Entity.h"
#include "../model/EntityId.h"

template<typename TEntity, typename TEntityId, typename = enable_if_t<is_base_of_v<Entity<TEntityId>, TEntity>>, typename = enable_if_t<is_base_of_v<EntityId, TEntityId>>>
class Repository {
public:
    virtual Result save(shared_ptr<TEntity> obj) = 0;

    virtual Result remove(shared_ptr<TEntity> obj) = 0;

    virtual list <shared_ptr<TEntity>> getAll() = 0;

    virtual optional<shared_ptr<TEntity>> getById(shared_ptr<TEntityId> id) = 0;

    virtual bool isEmpty() = 0;

    virtual long count() = 0;
};

#endif //TASKS_REPOSITORY_H