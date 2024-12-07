cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2 main.cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(DHMS main.cpp
        Sources/PropertyContainer.cpp
        Sources/PublishAdController.cpp
        Sources/PublishAdView.cpp
        headers/DisplayListedPropertiesView.h
        headers/DisplayListedPropertiesController.h
        headers/DisplayListedPropertiesService.h
        headers/Listing.h
        Sources/DisplayListedPropertiesController.cpp
        Sources/DisplayListedPropertiesView.cpp
        Sources/DisplayListedPropertiesService.cpp
        Sources/Listing.cpp
        headers/ListingRepository.h
        headers/Advertisement.h
        headers/Sale.h
        headers/Lease.h
        Sources/Sale.cpp
        Sources/Lease.cpp
        Sources/Advertisement.cpp
        Sources/ListingRepository.cpp
        Sources/BookingController.cpp
        headers/BookingController.h
        Sources/BookingService.cpp
        Sources/BookingView.cpp
        Sources/VisitRequest.cpp
        headers/BookingService.h
        headers/BookingView.h
        headers/VisitRequest.h
)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)

target_link_libraries(leti-esoft-24-25-A2 main.cpp Core)