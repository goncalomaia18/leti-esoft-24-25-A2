project(Core)


add_library(Core Headers/Domain/model/Category.h sources/domain/model/Category.cpp
        Headers/Domain/repositories/CategoryRepository.h sources/domain/model/Person.cpp Headers/Domain/model/Person.h sources/domain/shared/StringUtils.cpp Headers/Domain/shared/StringUtils.h sources/domain/exceptions/TaskDomainError.cpp Headers/Domain/exceptions/TaskDomainError.h sources/controllers/ui/CreateCategoryController.cpp Headers/Controllers/ui/CreateCategoryController.h sources/controllers/shared/App.cpp Headers/Controllers/shared/App.h sources/controllers/ui/AuthController.cpp Headers/Controllers/ui/AuthController.h sources/controllers/ui/ListCategoriesController.cpp Headers/Controllers/ui/ListCategoriesController.h sources/controllers/ui/UpdateCategoryController.cpp Headers/Controllers/ui/UpdateCategoryController.h sources/domain/shared/Result.cpp Headers/Domain/shared/Result.h sources/controllers/ui/DeleteCategoryController.cpp Headers/Controllers/ui/DeleteCategoryController.h Headers/Domain/repositories/Repository.h sources/domain/model/EntityId.cpp Headers/Domain/model/EntityId.h Headers/Domain/model/Entity.h Headers/Domain/model/CategoryId.h Headers/Infrastructure/memory/MemoryRepository.h Headers/Domain/repositories/RepositoryFactory.h sources/infrastructure/memory/MemoryRepositoryFactory.cpp Headers/Infrastructure/memory/MemoryRepositoryFactory.h Headers/Controllers/shared/ConfigFileReader.h sources/domain/services/CategoryService.cpp Headers/Domain/services/CategoryService.h sources/controllers/restapi/CategoryController.cpp Headers/Controllers/restapi/CategoryController.h sources/controllers/restapi/RestController.cpp Headers/Controllers/restapi/RestController.h Headers/Controllers/restapi/HttpStatus.h sources/controllers/restapi/HttpResult.cpp Headers/Controllers/restapi/HttpResult.h sources/controllers/restapi/mappers/CategoryMapper.cpp Headers/Controllers/restapi/mappers/CategoryMapper.h
        sources/domain/model/Property.cpp
        sources/domain/model/Sale.cpp
        sources/domain/model/Listing.cpp
        sources/domain/model/Lease.cpp
        sources/domain/model/RealEstateAgent.cpp
        headers/controllers/restapi/BookingController.h
        headers/controllers/ui/DisplayListedPropertiesController.h
        headers/controllers/ui/PublishAdController.h
        headers/controllers/restapi/PropertyController.h
        sources/controllers/restapi/mappers/PropertyController.cpp
        headers/controllers/restapi/StoreController.h
        sources/controllers/restapi/StoreController.cpp
        headers/infrastructure/infrastructure/container/PropertyContainer.h)
