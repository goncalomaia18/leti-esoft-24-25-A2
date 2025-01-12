project(RestAPI)

add_executable(RestAPI RestAPI.cpp sources/RouterConfig.cpp headers/RouterConfig.h sources/TasksServer.cpp headers/TasksServer.h sources/ServerStatusRouter.cpp headers/ServerStatusRouter.h
        sources/PropertyRouter.cpp
        headers/HttpResult.h
        headers/HttpResult.h
        headers/StoreRouter.h
        sources/StoreRouter.cpp)

target_link_libraries(RestAPI Core)

# We need to link our application to ws2_32 on windows for the implementation of winsock2.h
if(WIN32)
    target_link_libraries(RestAPI ws2_32)
endif()
# WIN32