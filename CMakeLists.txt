cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2)
set(CMAKE_CXX_STANDARD 17)

add_executable(leti-esoft-24-25-A2 main.cpp)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(ConsoleApp)
add_subdirectory(RestAPI)

target_link_libraries(leti-esoft-24-25-A2 Core)